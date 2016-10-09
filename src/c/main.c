/*
Author : Quentin Gusbin
Date : 10/09/2016
*/
#include <pebble.h>
#include "data.h"
#include "setterAndComplexChoiceWindow.h"
#include "gameWindow.h"
#include "stack.h"

//Declaration of some necessary methods for communication with AppMessage(Allow us to send message to the server)
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

  
  // Open AppMessage
  app_message_open(100, 1400);
}

static void deinit(void) {
  //Destroy the historic
  deinitializeHistoricStack();
	
}

int main(void) {
	initAllWindows();
	app_event_loop();
	deinit();
}
