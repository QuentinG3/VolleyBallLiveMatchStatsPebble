#include <pebble.h>
#include "matchOverWindow.h"
#include "windows.h"
#include "data.h"
#include "statByComplexWindow.h"

#define NUM_MENU_SECTIONS 1
#define NUM_FIRST_MENU_ITEMS 3
#include "T3Window.h"



static MenuLayer *s_menu_layer;
static T3Window * myT3Window;
  
const char * keyboardSet1[] = {T3_LAYOUT_LOWERCASE, T3_LAYOUT_UPPERCASE};
const char * keyboardSet2[] = {T3_LAYOUT_NUMBERS};
const char * keyboardSet3[] = {T3_LAYOUT_PUNC, T3_LAYOUT_BRACKETS};
char* email = "";

void sendStats(const char* text){
  // Create dictionary
  DictionaryIterator *iter;
  
  app_message_outbox_begin(&iter);
  
  char* current_stat_buffer = malloc(sizeof(char) * 10);
  int setterOrder[6] = {0,5,4,3,2,1};
  int n = 0;
  for(int i = 0;i<5;i++){
    for(int j = 0;j<6;j++){
      for(int k = 0;k<2;k++){
        for(int l = 0;l<2;l++){
          int setter = setterOrder[j];
          int current_stat = dataVariable[i][setter][k][l];
          snprintf(current_stat_buffer, 30,"%d",current_stat);
          dict_write_cstring(iter,n,current_stat_buffer);
          //dict_write_uint8(iter, n, dataVariable[i][setter][k][l]);
          n++;
        }
      }
    }
  }
  free(current_stat_buffer);
  dict_write_cstring(iter,130,text);
  // Send the message!
  app_message_outbox_send();
}
void myCloseHandler(const char * text) {
    t3window_destroy(myT3Window);
    sendStats(text);
}
void displayKeyboard(){
  myT3Window = t3window_create(
    keyboardSet1, 2,
    keyboardSet2, 1,
    keyboardSet3, 2,
    (T3CloseHandler)myCloseHandler);
  
  t3window_show(myT3Window, true);
}
static uint16_t menu_get_num_sections_callback(MenuLayer *menu_layer, void *data) {
  return NUM_MENU_SECTIONS;
}

static uint16_t menu_get_num_rows_callback(MenuLayer *menu_layer, uint16_t section_index, void *data) {
      return NUM_FIRST_MENU_ITEMS;
}

static int16_t menu_get_header_height_callback(MenuLayer *menu_layer, uint16_t section_index, void *data) {
  return 30;
}

static void menu_draw_header_callback(GContext* ctx, const Layer *cell_layer, uint16_t section_index, void *data) {
  menu_cell_basic_header_draw(ctx, cell_layer, "Match over ! What do you want to do?");
}

static void menu_draw_row_callback(GContext* ctx, const Layer *cell_layer, MenuIndex *cell_index, void *data) {
  switch (cell_index->row) {
        case 0:
          menu_cell_basic_draw(ctx, cell_layer, "Send Data", "Send data and exit", NULL);
          break;
        case 1:
          menu_cell_basic_draw(ctx, cell_layer, "Analyse data", "Have a look at game data", NULL);
          break;
        case 2:
          menu_cell_basic_draw(ctx, cell_layer, "Exit app", "", NULL);
          break;
      }
}

static void menu_select_callback(MenuLayer *menu_layer, MenuIndex *cell_index, void *data) {
  switch (cell_index->row) {
        case 0:
          displayKeyboard();
          break;
        case 1:
          initialize_stat_by_complex_window(0,0);
          window_stack_push(g_stat_by_complex_window, true);
          window_destroy(g_game_window);
          break;
        case 2:
          window_stack_pop_all(true);
          window_destroy(g_match_over_window);
      }
  
}

static void match_over_window_short_back_click_handler(ClickRecognizerRef recognizer, void *context) {
  printf("Back button disabled");
}

static void match_over_click_config_provider(void *context) {

    ButtonId idBack = BUTTON_ID_BACK; //The back button

    window_single_click_subscribe(idBack,match_over_window_short_back_click_handler); 
}

static void match_over_load(Window *window) {
  
 
  //Creating the menu layer and displaying it
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);
  
  s_menu_layer = menu_layer_create(bounds);
  menu_layer_set_callbacks(s_menu_layer, NULL, (MenuLayerCallbacks){
    .get_num_sections = menu_get_num_sections_callback,
    .get_num_rows = menu_get_num_rows_callback,
    .get_header_height = menu_get_header_height_callback,
    .draw_header = menu_draw_header_callback,
    .draw_row = menu_draw_row_callback,
    .select_click = menu_select_callback,
  });
  
  // Bind the menu layer's click config provider to the window for interactivity
  menu_layer_set_click_config_onto_window(s_menu_layer, window);

  layer_add_child(window_layer, menu_layer_get_layer(s_menu_layer));
  
  
}

static void match_over_unload(Window *window){
  menu_layer_destroy(s_menu_layer);
}

void initialize_match_over_window(){
  
  //Window creation
  g_match_over_window = window_create();
  
  //Setting the click handler
  window_set_click_config_provider(g_match_over_window, match_over_click_config_provider);
  
  //Set handlers to manage the elements inside the Window
  window_set_window_handlers(g_match_over_window, (WindowHandlers) {
    .load = match_over_load,
    .unload = match_over_unload
  });
  
}