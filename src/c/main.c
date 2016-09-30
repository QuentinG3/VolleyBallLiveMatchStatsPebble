#include <pebble.h>
#include "data.h"
#include "setterAndComplexChoiceWindow.h"
#include "gameWindow.h"
#include "windows.h"
#include "stack.h"
#include "setOverWindow.h"
#include "matchOverWindow.h"
#include "statByComplexWindow.h"
#include "statByPlayerWindow.h"

static void inbox_received_callback(DictionaryIterator *iterator, void *context) {
  //APP_LOG(APP_LOG_LEVEL_INFO, "Indox received success!");
}

static void inbox_dropped_callback(AppMessageResult reason, void *context) {
  APP_LOG(APP_LOG_LEVEL_ERROR, "Message dropped!");
}

static void outbox_failed_callback(DictionaryIterator *iterator, AppMessageResult reason, void *context) {
  APP_LOG(APP_LOG_LEVEL_ERROR, "Outbox send failed!");
}

static void outbox_sent_callback(DictionaryIterator *iterator, void *context) {
  APP_LOG(APP_LOG_LEVEL_INFO, "Outbox send success!");
}


static void initAllWindows() {
  
  app_message_register_inbox_received(inbox_received_callback);
  app_message_register_inbox_dropped(inbox_dropped_callback);
  app_message_register_outbox_failed(outbox_failed_callback);
  app_message_register_outbox_sent(outbox_sent_callback);
  
  //Initilizing historic stack
  initializeHistoricStack();
  
  //Initializing setterAndComplexChoiceWindow
  initialize_setter_and_complex_choice_window();
  
  //Initializing setterAndComplexChoiceWindow
  initialize_game_window();
  
  //Initializing SetOverWindow
  initialize_set_over_window();
  
  //Initializing MatchOverWindow
  initialize_match_over_window();
  
  //Initializing StatByComplex
  initialize_stat_by_complex_window();
  
  //Initializing StatByPlayer
  initialize_stat_by_player_window();
  
  // Show the Window on the watch, with animated=true
  //window_stack_push(g_game_window, true);
  window_stack_push(g_setter_and_complex_choice_window, true);
  //window_stack_push(g_set_over_window, true);
  //window_stack_push(g_stat_by_complex_window, true);
  //window_stack_push(g_stat_by_player_window, true);
  //window_stack_push(g_match_over_window, true);
  
    // Open AppMessage
  app_message_open(100, 1024);
}

static void deinit(void) {
  //Destroy the historic
  deinitializeHistoricStack();
	
	// Destroy all the windows
	window_destroy(g_setter_and_complex_choice_window);
  window_destroy(g_game_window);
  window_destroy(g_set_over_window);
  window_destroy(g_match_over_window);
  window_destroy(g_stat_by_complex_window);
  window_destroy(g_stat_by_player_window);
}

int main(void) {
	initAllWindows();
	app_event_loop();
	deinit();
}
