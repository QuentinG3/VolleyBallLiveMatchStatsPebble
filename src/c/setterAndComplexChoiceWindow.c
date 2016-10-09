/*
Author : Quentin Gusbin
Date : 10/09/2016
*/
#include <pebble.h>
#include "setterAndComplexChoiceWindow.h"
#include "data.h"
#include "gameWindow.h"

#define NUM_MENU_SECTIONS 1
#define NUM_FIRST_MENU_ITEMS 3

static Window *g_setter_and_complex_choice_window;
static MenuLayer *s_menu_layer;

char* currentSetNumberBuffer;

static uint16_t menu_get_num_sections_callback(MenuLayer *menu_layer, void *data) {
  return NUM_MENU_SECTIONS;
}

static uint16_t menu_get_num_rows_callback(MenuLayer *menu_layer, uint16_t section_index, void *data) {
      return NUM_FIRST_MENU_ITEMS;
}

static int16_t menu_get_header_height_callback(MenuLayer *menu_layer, uint16_t section_index, void *data) {
  return 0;
}

static void menu_draw_header_callback(GContext* ctx, const Layer *cell_layer, uint16_t section_index, void *data) {
}

static void menu_draw_row_callback(GContext* ctx, const Layer *cell_layer, MenuIndex *cell_index, void *data) {
  switch (cell_index->row) {
        case 0:
          menu_cell_basic_draw(ctx, cell_layer, "Setter position", setterPositionNames[currentSetterPositionIndex], NULL);
          break;
        case 1:
          menu_cell_basic_draw(ctx, cell_layer, "Serve", serveNames[currentComplexIndex], NULL);
          break;
        case 2:
          snprintf(currentSetNumberBuffer, 30,"%s %d","Start set number", currentSetIndex+1);
          menu_cell_basic_draw(ctx, cell_layer, "Start", currentSetNumberBuffer, NULL);
          break;
      }
}

static void menu_select_callback(MenuLayer *menu_layer, MenuIndex *cell_index, void *data) {
  switch (cell_index->row) {
        case 0:
          next_setter_position();
          menu_layer_reload_data(s_menu_layer);
          break;
        case 1:
          next_complex();
          menu_layer_reload_data(s_menu_layer);
          break;
        case 2:
          window_stack_pop(true);
          initialize_game_window();
          break;
      }
  
}

static void setter_and_complex_choice_window_load(Window *window) {
  
 
  
  //Creating the menu layer and displaying it
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);
  
  currentSetNumberBuffer = malloc(sizeof(char) * 30);
  
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

static void setter_and_complex_choice_window_unload(Window *window){
  
  free(currentSetNumberBuffer);
  menu_layer_destroy(s_menu_layer);
  window_destroy(g_setter_and_complex_choice_window);
  
}

void initialize_setter_and_complex_choice_window(){
  
  //Window creation
  g_setter_and_complex_choice_window = window_create();

  //Set handlers to manage the elements inside the Window
  window_set_window_handlers(g_setter_and_complex_choice_window, (WindowHandlers) {
    .load = setter_and_complex_choice_window_load,
    .unload = setter_and_complex_choice_window_unload
  });
  
  window_stack_push(g_setter_and_complex_choice_window, true);
}

