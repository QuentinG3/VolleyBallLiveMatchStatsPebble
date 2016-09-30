#include <pebble.h>
#include "gameWindow.h"
#include "windows.h"
#include "data.h"

#define NUM_SETTER_POSITION 6
#define NUM_COMPLEX 2
#define NUM_MAX_SET 5

static TextLayer *s_setter_layer;

static TextLayer *s_C1_layer;
static TextLayer *s_C2_layer;

static TextLayer *s_C1_percentage_layer;
static TextLayer *s_C2_percentage_layer;

static TextLayer *s_C1_C2_layer;
static TextLayer *s_C1_C2_percentage_layer;


static TextLayer *s_service_indication_left_layer;
static TextLayer *s_service_indication_right_layer;

static TextLayer *s_home_team_score_layer;
static TextLayer *s_away_team_score_layer;

char* home_score_text_buffer;
char* away_score_text_buffer;

char* C1_percentage_text_buffer;
char* C2_percentage_text_buffer;
char* C1_And_C2_percentage_text_buffer;

void computeAndDisplaySetterPosition(){
  text_layer_set_text(s_setter_layer,  setterPositionNames[currentSetterPositionIndex]);
}


void computeAndDisplayHomeScore(){
  //Getting the home score
  int sum = computeHomeScore(currentSetIndex);
  //Displaying the home score
  snprintf(home_score_text_buffer, 30,"%d",sum);
  text_layer_set_text(s_home_team_score_layer, home_score_text_buffer);
}

void computeAndDisplayAwayScore(){
  //Getting away score
  int sum = computeAwayScore(currentSetIndex);
  
  //Displaying the home score
  snprintf(away_score_text_buffer, 30,"%d",sum);
  text_layer_set_text(s_away_team_score_layer, away_score_text_buffer);
}

void computeAndDisplayServe(){;
  //If we are in complex 1 (means that we don't have the serve)
  if(currentComplexIndex == 0){
      layer_set_hidden((Layer *)s_service_indication_right_layer, false);
      layer_set_hidden((Layer *)s_service_indication_left_layer, true);
  }
  //Else we are in complex 2 (means we have the serve)
  else{
      layer_set_hidden((Layer *)s_service_indication_right_layer, true);
      layer_set_hidden((Layer *)s_service_indication_left_layer, false);
  }
}

void computeAndDisplayC1Percentage(){
  
  //Computing the C1 percentage
  double percentageNumerator = (double) dataVariable[currentSetIndex][currentSetterPositionIndex][0][0];
  double percentageDenominator = percentageNumerator + (double) dataVariable[currentSetIndex][currentSetterPositionIndex][0][1];
  
  double percentage = (percentageNumerator/percentageDenominator)*100;
  
  //Displating the C1 percentage
  if(percentageDenominator == 0 || percentage < 60){
    text_layer_set_text_color(s_C1_percentage_layer, GColorRed);
  }
  else{
    text_layer_set_text_color(s_C1_percentage_layer, GColorBlack);
  }
  snprintf(C1_percentage_text_buffer, 30,"%d",(int)percentage);
  strcat(C1_percentage_text_buffer,"%");
  text_layer_set_text(s_C1_percentage_layer, C1_percentage_text_buffer);
  
}

void computeAndDisplayC2Percentage(){
    //Computing the C2 percentage
  double percentageNumerator = (double) dataVariable[currentSetIndex][currentSetterPositionIndex][1][0];
  double percentageDenominator = percentageNumerator + (double) dataVariable[currentSetIndex][currentSetterPositionIndex][1][1];
  
  double percentage = (percentageNumerator/percentageDenominator)*100;
  
  //Displating the C2 percentage
  if(percentageDenominator == 0 || percentage < 40){
    text_layer_set_text_color(s_C2_percentage_layer, GColorRed);
  }
  else{
    text_layer_set_text_color(s_C2_percentage_layer, GColorBlack);
  }
  snprintf(C2_percentage_text_buffer, 30,"%d",(int)percentage);
  strcat(C2_percentage_text_buffer,"%");
  text_layer_set_text(s_C2_percentage_layer, C2_percentage_text_buffer);
}

void computeAndDisplayC1AndC2Percentage(){
  //Computing the C1 percentage
  double C1percentageNumerator = (double) dataVariable[currentSetIndex][currentSetterPositionIndex][0][0];
  double C1percentageDenominator = C1percentageNumerator + (double) dataVariable[currentSetIndex][currentSetterPositionIndex][0][1];
  double C1percentage;
  if(C1percentageDenominator == 0){
    C1percentage = 0;
  }else{
    C1percentage = (C1percentageNumerator/C1percentageDenominator)*100;
  }
  

  
  //Computing the C2 percentage
  double C2percentageNumerator = (double) dataVariable[currentSetIndex][currentSetterPositionIndex][1][0];
  double C2percentageDenominator = C2percentageNumerator + (double) dataVariable[currentSetIndex][currentSetterPositionIndex][1][1];
  double C2percentage;
  if(C2percentageDenominator == 0){
    C2percentage = 0;
  }else{
    C2percentage = (C2percentageNumerator/C2percentageDenominator)*100;
  }
  
  double totalPercentage =  C1percentage + C2percentage;
    
  //Displaying C1 + C2 percentage
  if(totalPercentage < 101){
    text_layer_set_text_color(s_C1_C2_percentage_layer, GColorRed);
  }
  else{
    text_layer_set_text_color(s_C1_C2_percentage_layer, GColorBlack);
  }
  snprintf(C1_And_C2_percentage_text_buffer, 30,"%d",(int)totalPercentage);
  strcat(C1_And_C2_percentage_text_buffer,"%");
  text_layer_set_text(s_C1_C2_percentage_layer, C1_And_C2_percentage_text_buffer);
  
  
}

void updateUI(){
  computeAndDisplaySetterPosition();
  computeAndDisplayHomeScore();
  computeAndDisplayAwayScore();
  computeAndDisplayServe();
  computeAndDisplayC1Percentage();
  computeAndDisplayC2Percentage();
  computeAndDisplayC1AndC2Percentage();
  
}

static void game_window_short_select_click_handler(ClickRecognizerRef recognizer, void *context) {
  window_stack_push(g_stat_by_complex_window, true);
}

static void game_window_short_up_click_handler(ClickRecognizerRef recognizer, void *context) {
  
  //Creating the historic if we want to undo
  stackElementT elem = {currentSetterPositionIndex,currentComplexIndex,0};
  StackPush(&historicStack[currentSetIndex],elem);
  
  //Adding the point in the data
  dataVariable[currentSetIndex][currentSetterPositionIndex][currentComplexIndex][0]++;
  if(currentComplexIndex == 0){
    next_setter_position();
    next_complex();
  }
  
  //Updating the UI with the new informations
  updateUI();
  
  //We check if the set is over. If it is we ask the user if the set is really over by asking him with the next window.
  if(setIsFinished(currentSetIndex)){
    //TODO go to the window asking if set is finished
    window_stack_push(g_set_over_window, true);
  }
}

static void game_window_short_down_click_handler(ClickRecognizerRef recognizer, void *context) {
  //Creating the historic if we want to undo
  stackElementT elem = {currentSetterPositionIndex,currentComplexIndex,1};
  StackPush(&historicStack[currentSetIndex],elem);
  
  //Adding the point in the data
  dataVariable[currentSetIndex][currentSetterPositionIndex][currentComplexIndex][1]++;
  if(currentComplexIndex == 1){
    next_complex();
  }
  
  //Updating the UI with the new informations
  updateUI();
  
    //We check if the set is over. If it is we ask the user if the set is really over by asking him with the next window.
  if(setIsFinished(currentSetIndex)){
    //TODO go to the window asking if set is finished
    window_stack_push(g_set_over_window, true);
  }
}

static void game_window_long_up_click_handler(ClickRecognizerRef recognizer, void *context) {
    //Checking if we can go back in time
    undoLastAction();
    
    //Computing and dsplaying new values with the changed informations
      updateUI();
}

static void game_window_click_config_provider(void *context) {
    ButtonId idSelect = BUTTON_ID_SELECT;  // The Select button
    ButtonId idUp = BUTTON_ID_UP; //The up button
    ButtonId idDown = BUTTON_ID_DOWN; //The down button
  
    uint16_t delay_ms_long_click_up = 500;         // Minimum time pressed to fire long click up
    //uint16_t delay_ms_long_click_down = 500;         // Minimum time pressed to fire long click down
    //uint16_t delay_ms_long_click_select = 1000;   // Minimum time pressed to fire long click select

  
  
    window_single_click_subscribe(idSelect, game_window_short_select_click_handler);
    window_single_click_subscribe(idUp, game_window_short_up_click_handler);
    window_single_click_subscribe(idDown,game_window_short_down_click_handler);
  
    window_long_click_subscribe(idUp, delay_ms_long_click_up, game_window_long_up_click_handler,NULL);
    //window_long_click_subscribe(idDown, delay_ms_long_click_down, long_down_click_handler,NULL);
    //window_long_click_subscribe(idSelect, delay_ms_long_click_select, long_select_click_handler,NULL);
  
}

static void game_window_load(Window *window) {
  
  home_score_text_buffer = malloc(sizeof(char) * 30);
  away_score_text_buffer = malloc(sizeof(char) * 30);
  C1_percentage_text_buffer = malloc(sizeof(char) * 30);
  C2_percentage_text_buffer = malloc(sizeof(char) * 30);
  C1_And_C2_percentage_text_buffer = malloc(sizeof(char) * 30);
  
  // Get information about the Window
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  
  //Creating the Setter text Layer 
  s_setter_layer = text_layer_create(
  GRect(0, 0 , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_setter_layer, GColorClear);
  text_layer_set_text_color(s_setter_layer, GColorBlack);
  computeAndDisplaySetterPosition();
  text_layer_set_text_alignment(s_setter_layer, GTextAlignmentCenter);
  text_layer_set_font(s_setter_layer,fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_setter_layer));
  
  //Creating the C1 text Layer 
  s_C1_layer = text_layer_create(
  GRect(0, 2*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C1_layer, GColorClear);
  text_layer_set_text_color(s_C1_layer, GColorBlack);
  text_layer_set_text(s_C1_layer,  complexNames[0]);
  text_layer_set_text_alignment(s_C1_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C1_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C1_layer));
  
  //Creating the C2 text Layer 
  s_C2_layer = text_layer_create(
  GRect(5*(bounds.size.w/10), 2*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C2_layer, GColorClear);
  text_layer_set_text_color(s_C2_layer, GColorBlack);
  text_layer_set_text(s_C2_layer, complexNames[1]);
  text_layer_set_text_alignment(s_C2_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C2_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C2_layer));
  
 //Creating the C1 percentage text Layer 

  s_C1_percentage_layer = text_layer_create(
  GRect(2*(bounds.size.w/10), 2*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C1_percentage_layer, GColorClear);
  computeAndDisplayC1Percentage();
  text_layer_set_text_alignment(s_C1_percentage_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C1_percentage_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C1_percentage_layer));
  
  //Creating the C2 percentage text Layer 
  s_C2_percentage_layer = text_layer_create(
  GRect(7*(bounds.size.w/10), 2*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C2_percentage_layer, GColorClear);
  computeAndDisplayC2Percentage();
  text_layer_set_text_alignment(s_C2_percentage_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C2_percentage_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C2_percentage_layer));
  
  
    
  //Creating the C1 and C2 text Layer 
  s_C1_C2_layer = text_layer_create(
  GRect((bounds.size.w/10), 4*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C1_C2_layer, GColorClear);
  text_layer_set_text_color(s_C1_C2_layer, GColorBlack);
  text_layer_set_text(s_C1_C2_layer, "C1 + C2");
  text_layer_set_text_alignment(s_C1_C2_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C1_C2_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C1_C2_layer));
  
  //Creating the C1 and C2 percentage text Layer 
  s_C1_C2_percentage_layer = text_layer_create(
  GRect(6*(bounds.size.w/10), 4*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C1_C2_percentage_layer, GColorClear);
  computeAndDisplayC1AndC2Percentage();
  text_layer_set_text_alignment(s_C1_C2_percentage_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C1_C2_percentage_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C1_C2_percentage_layer));
  
    
  //Creating the serve indication left text Layer 
  s_service_indication_left_layer = text_layer_create(
  GRect(0, 6*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_service_indication_left_layer, GColorClear);
  text_layer_set_text_color(s_service_indication_left_layer, GColorGreen);
  text_layer_set_text(s_service_indication_left_layer, "[--Serve--]");
  text_layer_set_text_alignment(s_service_indication_left_layer, GTextAlignmentLeft);
  text_layer_set_font(s_service_indication_left_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_service_indication_left_layer));
  
  //Creating the serve indication right text Layer 
  s_service_indication_right_layer = text_layer_create(
  GRect(0, 6*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_service_indication_right_layer, GColorClear);
  text_layer_set_text_color(s_service_indication_right_layer, GColorRed);
  text_layer_set_text(s_service_indication_right_layer, "[--Serve--]");
  text_layer_set_text_alignment(s_service_indication_right_layer, GTextAlignmentRight);
  text_layer_set_font(s_service_indication_right_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_service_indication_right_layer));

  
  computeAndDisplayServe();
    
  //Creating score home text Layer 
  s_home_team_score_layer = text_layer_create(
  GRect((bounds.size.w/10), 7*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_home_team_score_layer, GColorClear);
  text_layer_set_text_color(s_home_team_score_layer, GColorGreen);
  computeAndDisplayHomeScore();
  text_layer_set_text_alignment(s_home_team_score_layer, GTextAlignmentLeft);
  text_layer_set_font(s_home_team_score_layer,fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_home_team_score_layer));
  
  //Creating the score away text Layer 
  s_away_team_score_layer = text_layer_create(
  GRect(0, 7*(bounds.size.h/10) , 9*(bounds.size.w/10), bounds.size.h));
  
  text_layer_set_background_color(s_away_team_score_layer, GColorClear);
  text_layer_set_text_color(s_away_team_score_layer, GColorRed);
  computeAndDisplayAwayScore();
  text_layer_set_text_alignment(s_away_team_score_layer, GTextAlignmentRight);
  text_layer_set_font(s_away_team_score_layer,fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_away_team_score_layer));
  
  
  
}

static void game_window_unload(Window *window){
    text_layer_destroy(s_setter_layer);
    text_layer_destroy(s_C1_layer);
    text_layer_destroy(s_C2_layer);
    text_layer_destroy(s_C1_percentage_layer);
    text_layer_destroy(s_C2_percentage_layer);
    text_layer_destroy(s_service_indication_left_layer);
    text_layer_destroy(s_service_indication_right_layer);
    text_layer_destroy(s_home_team_score_layer);
    text_layer_destroy(s_away_team_score_layer);
  
    free(home_score_text_buffer);
    free(away_score_text_buffer);
    free(C1_percentage_text_buffer);
    free(C2_percentage_text_buffer);
    free(C1_And_C2_percentage_text_buffer);
}

void initialize_game_window(){
  //Creating window
  g_game_window = window_create();
  
  //Setting the click handler
  window_set_click_config_provider(g_game_window, game_window_click_config_provider);
  
  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(g_game_window, (WindowHandlers) {
    .load = game_window_load,
    .unload = game_window_unload
  });
  
}