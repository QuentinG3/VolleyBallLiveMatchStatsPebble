#include <pebble.h>
#include "setOverWindow.h"
#include "data.h"
#include "gameWindow.h"
#include "setterAndComplexChoiceWindow.h"
#include "matchOverWindow.h"

#define NUM_MENU_SECTIONS 1
#define NUM_FIRST_MENU_ITEMS 2

static Window *g_set_over_window;
static MenuLayer *s_menu_layer;

static uint16_t menu_get_num_sections_callback(MenuLayer *menu_layer, void *data) {
  return NUM_MENU_SECTIONS;
}

static uint16_t menu_get_num_rows_callback(MenuLayer *menu_layer, uint16_t section_index, void *data) {
      return NUM_FIRST_MENU_ITEMS;
}

static int16_t menu_get_header_height_callback(MenuLayer *menu_layer, uint16_t section_index, void *data) {
  return 25;
}

static void menu_draw_header_callback(GContext* ctx, const Layer *cell_layer, uint16_t section_index, void *data) {
  menu_cell_basic_header_draw(ctx, cell_layer, "Set is over?");
}

static void menu_draw_row_callback(GContext* ctx, const Layer *cell_layer, MenuIndex *cell_index, void *data) {
  switch (cell_index->row) {
        case 0:
          menu_cell_basic_draw(ctx, cell_layer, "Yes", "Go to next set !", NULL);
          break;
        case 1:
          menu_cell_basic_draw(ctx, cell_layer, "No", "Oops, wrong button", NULL);
          break;
      }
}

static void menu_select_callback(MenuLayer *menu_layer, MenuIndex *cell_index, void *data) {
  switch (cell_index->row) {
        case 0:
          gotoNextSet();
          if(matchOver()){
            window_stack_pop(true);
            initialize_match_over_window();
            
          }
          else{
            window_stack_pop(true);
            initialize_setter_and_complex_choice_window();
          }
          break;
        case 1:
          undoLastAction();
        
          window_stack_pop(true);
          initialize_game_window();
          break;
      }
  
}

static void set_over_window_short_back_click_handler(ClickRecognizerRef recognizer, void *context) {
  printf("Back button disabled");
}

static void set_over_click_config_provider(void *context) {

    ButtonId idBack = BUTTON_ID_BACK; //The back button

    window_single_click_subscribe(idBack,set_over_window_short_back_click_handler); 
}

static void set_over_load(Window *window) {
  
 
  
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

static void set_over_unload(Window *window){
  menu_layer_destroy(s_menu_layer);
  window_destroy(g_set_over_window);
}

void initialize_set_over_window(){
  
  //Window creation
  g_set_over_window = window_create();
  
  //Setting the click handler
  window_set_click_config_provider(g_set_over_window, set_over_click_config_provider);

  //Set handlers to manage the elements inside the Window
  window_set_window_handlers(g_set_over_window, (WindowHandlers) {
    .load = set_over_load,
    .unload = set_over_unload
  });
  
  window_stack_push(g_set_over_window, true);
  
}