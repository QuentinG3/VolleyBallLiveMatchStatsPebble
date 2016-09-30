#include <pebble.h>
#include "statByPlayerWindow.h"
#include "windows.h"
#include "data.h"

static TextLayer *s_C1_up_layer;
static TextLayer *s_C2_up_layer;

static TextLayer *s_C1_down_layer;
static TextLayer *s_C2_down_layer;

static TextLayer *s_setter_layer;
static TextLayer *s_R2_layer;
static TextLayer *s_R5_layer;
static TextLayer *s_opposite_layer;
static TextLayer *s_M3_layer;
static TextLayer *s_M6_layer;

static TextLayer *s_C1_setter_percentage_layer;
static TextLayer *s_C1_M6_percentage_layer;
static TextLayer *s_C1_M3_percentage_layer;
static TextLayer *s_C1_opposite_percentage_layer;
static TextLayer *s_C1_R5_percentage_layer;
static TextLayer *s_C1_R2_percentage_layer;

static TextLayer *s_C2_setter_percentage_layer;
static TextLayer *s_C2_M6_percentage_layer;
static TextLayer *s_C2_M3_percentage_layer;
static TextLayer *s_C2_opposite_percentage_layer;
static TextLayer *s_C2_R5_percentage_layer;
static TextLayer *s_C2_R2_percentage_layer;

char* s_C1_setter_percentage_text_buffer;
char* s_C1_M6_percentage_text_buffer;
char* s_C1_M3_percentage_text_buffer;
char* s_C1_opposite_percentage_text_buffer;
char* s_C1_R5_percentage_text_buffer;
char* s_C1_R2_percentage_text_buffer;

char* s_C2_setter_percentage_text_buffer;
char* s_C2_M6_percentage_text_buffer;
char* s_C2_M3_percentage_text_buffer;
char* s_C2_opposite_percentage_text_buffer;
char* s_C2_R5_percentage_text_buffer;
char* s_C2_R2_percentage_text_buffer;


void computeAndDisplayC1Setter(){
  //Computing percentage
  double numerator = (double)dataVariable[currentSetIndex][3][0][0] + (double)dataVariable[currentSetIndex][2][0][0] + (double)dataVariable[currentSetIndex][1][0][0];
  double denominator = numerator + (double)dataVariable[currentSetIndex][3][0][1] + (double)dataVariable[currentSetIndex][2][0][1] + (double)dataVariable[currentSetIndex][1][0][1];
    
  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 60){
    text_layer_set_text_color(s_C1_setter_percentage_layer, GColorRed);
  }
  else{
    text_layer_set_text_color(s_C1_setter_percentage_layer, GColorBlack);
  }
  
  //Displaying percentage
  snprintf(s_C1_setter_percentage_text_buffer, 30,"%d",(int)percentage);
  strcat(s_C1_setter_percentage_text_buffer,"%");
  text_layer_set_text(s_C1_setter_percentage_layer, s_C1_setter_percentage_text_buffer);
  
}
void computeAndDisplayC1R2(){
  //Computing percentage
  double numerator = (double)dataVariable[currentSetIndex][3][0][0] + (double)dataVariable[currentSetIndex][2][0][0] + (double)dataVariable[currentSetIndex][1][0][0];
  double denominator = numerator + (double)dataVariable[currentSetIndex][3][0][1] + (double)dataVariable[currentSetIndex][2][0][1] + (double)dataVariable[currentSetIndex][1][0][1];
  
  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 60){
    text_layer_set_text_color(s_C1_R2_percentage_layer, GColorRed);
  }
  else{
    text_layer_set_text_color(s_C1_R2_percentage_layer, GColorBlack);
  }
  
  //Displaying percentage
  snprintf(s_C1_R2_percentage_text_buffer, 30,"%d",(int)percentage);
  strcat(s_C1_R2_percentage_text_buffer,"%");
  text_layer_set_text(s_C1_R2_percentage_layer, s_C1_R2_percentage_text_buffer);
}
void computeAndDisplayC1R5(){
  //Computing percentage
  double numerator = (double)dataVariable[currentSetIndex][5][0][0] + (double)dataVariable[currentSetIndex][4][0][0] + (double)dataVariable[currentSetIndex][2][0][0];
  double denominator = numerator + (double)dataVariable[currentSetIndex][5][0][1] + (double)dataVariable[currentSetIndex][4][0][1] + (double)dataVariable[currentSetIndex][3][0][1];
  
  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 60){
    text_layer_set_text_color(s_C1_R5_percentage_layer, GColorRed);
  }
  else{
    text_layer_set_text_color(s_C1_R5_percentage_layer, GColorBlack);
  }
  
  //Displaying percentage
  snprintf(s_C1_R5_percentage_text_buffer, 30,"%d",(int)percentage);
  strcat(s_C1_R5_percentage_text_buffer,"%");
  text_layer_set_text(s_C1_R5_percentage_layer, s_C1_R5_percentage_text_buffer);
}
void computeAndDisplayC1opposite(){
  //Computing percentage
  double numerator = (double)dataVariable[currentSetIndex][0][0][0] + (double)dataVariable[currentSetIndex][5][0][0] + (double)dataVariable[currentSetIndex][4][0][0];
  double denominator = numerator + (double)dataVariable[currentSetIndex][0][0][1] + (double)dataVariable[currentSetIndex][5][0][1] + (double)dataVariable[currentSetIndex][4][0][1];
  
  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 60){
    text_layer_set_text_color(s_C1_opposite_percentage_layer, GColorRed);
  }
  else{
    text_layer_set_text_color(s_C1_opposite_percentage_layer, GColorBlack);
  }
  
  //Displaying percentage
  snprintf(s_C1_opposite_percentage_text_buffer, 30,"%d",(int)percentage);
  strcat(s_C1_opposite_percentage_text_buffer,"%");
  text_layer_set_text(s_C1_opposite_percentage_layer, s_C1_opposite_percentage_text_buffer);
}
void computeAndDisplayC1M3(){
  //Computing percentage
  double numerator = (double)dataVariable[currentSetIndex][1][0][0] + (double)dataVariable[currentSetIndex][0][0][0] + (double)dataVariable[currentSetIndex][5][0][0];
  double denominator = numerator + (double)dataVariable[currentSetIndex][1][0][1] + (double)dataVariable[currentSetIndex][0][0][1] + (double)dataVariable[currentSetIndex][5][0][1];
  
  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 60){
    text_layer_set_text_color(s_C1_M3_percentage_layer, GColorRed);
  }
  else{
    text_layer_set_text_color(s_C1_M3_percentage_layer, GColorBlack);
  }
  
  //Displaying percentage
  snprintf(s_C1_M3_percentage_text_buffer, 30,"%d",(int)percentage);
  strcat(s_C1_M3_percentage_text_buffer,"%");
  text_layer_set_text(s_C1_M3_percentage_layer, s_C1_M3_percentage_text_buffer);
}
void computeAndDisplayC1M6(){
  //Computing percentage
  double numerator = (double)dataVariable[currentSetIndex][4][0][0] + (double)dataVariable[currentSetIndex][3][0][0] + (double)dataVariable[currentSetIndex][2][0][0];
  double denominator = numerator + (double)dataVariable[currentSetIndex][4][0][1] + (double)dataVariable[currentSetIndex][3][0][1] + (double)dataVariable[currentSetIndex][2][0][1];
  
  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 60){
    text_layer_set_text_color(s_C1_M6_percentage_layer, GColorRed);
  }
  else{
    text_layer_set_text_color(s_C1_M6_percentage_layer, GColorBlack);
  }
  
  //Displaying percentage
  snprintf(s_C1_M6_percentage_text_buffer, 30,"%d",(int)percentage);
  strcat(s_C1_M6_percentage_text_buffer,"%");
  text_layer_set_text(s_C1_M6_percentage_layer, s_C1_M6_percentage_text_buffer);
}


void computeAndDisplayC2Setter(){
  //Computing percentage
  double numerator = (double)dataVariable[currentSetIndex][3][1][0] + (double)dataVariable[currentSetIndex][2][1][0] + (double)dataVariable[currentSetIndex][1][1][0];
  double denominator = numerator + (double)dataVariable[currentSetIndex][3][1][1] + (double)dataVariable[currentSetIndex][2][1][1] + (double)dataVariable[currentSetIndex][1][1][1];
  
  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 40){
    text_layer_set_text_color(s_C2_setter_percentage_layer, GColorRed);
  }
  else{
    text_layer_set_text_color(s_C2_setter_percentage_layer, GColorBlack);
  }
  
  //Displaying percentage
  snprintf(s_C2_setter_percentage_text_buffer, 30,"%d",(int)percentage);
  strcat(s_C2_setter_percentage_text_buffer,"%");
  text_layer_set_text(s_C2_setter_percentage_layer, s_C2_setter_percentage_text_buffer);
}
void computeAndDisplayC2R2(){
  //Computing percentage
  double numerator = (double)dataVariable[currentSetIndex][2][1][0] + (double)dataVariable[currentSetIndex][1][1][0] + (double)dataVariable[currentSetIndex][0][1][0];
  double denominator = numerator + (double)dataVariable[currentSetIndex][2][1][1] + (double)dataVariable[currentSetIndex][1][1][1] + (double)dataVariable[currentSetIndex][0][1][1];
  
  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 40){
    text_layer_set_text_color(s_C2_R2_percentage_layer, GColorRed);
  }
  else{
    text_layer_set_text_color(s_C2_R2_percentage_layer, GColorBlack);
  }
  
  //Displaying percentage
  snprintf(s_C2_R2_percentage_text_buffer, 30,"%d",(int)percentage);
  strcat(s_C2_R2_percentage_text_buffer,"%");
  text_layer_set_text(s_C2_R2_percentage_layer, s_C2_R2_percentage_text_buffer);
}
void computeAndDisplayC2R5(){
  //Computing percentage
  double numerator = (double)dataVariable[currentSetIndex][5][1][0] + (double)dataVariable[currentSetIndex][4][1][0] + (double)dataVariable[currentSetIndex][3][1][0];
  double denominator = numerator + (double)dataVariable[currentSetIndex][5][1][1] + (double)dataVariable[currentSetIndex][4][1][1] + (double)dataVariable[currentSetIndex][3][1][1];
  
  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 40){
    text_layer_set_text_color(s_C2_R5_percentage_layer, GColorRed);
  }
  else{
    text_layer_set_text_color(s_C2_R5_percentage_layer, GColorBlack);
  }
  
  //Displaying percentage
  snprintf(s_C2_R5_percentage_text_buffer, 30,"%d",(int)percentage);
  strcat(s_C2_R5_percentage_text_buffer,"%");
  text_layer_set_text(s_C2_R5_percentage_layer, s_C2_R5_percentage_text_buffer);
}
void computeAndDisplayC2opposite(){
  //Computing percentage
  double numerator = (double)dataVariable[currentSetIndex][0][1][0] + (double)dataVariable[currentSetIndex][5][1][0] + (double)dataVariable[currentSetIndex][4][1][0];
  double denominator = numerator + (double)dataVariable[currentSetIndex][0][1][1] + (double)dataVariable[currentSetIndex][5][1][1] + (double)dataVariable[currentSetIndex][4][1][1];
  
  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 40){
    text_layer_set_text_color(s_C2_opposite_percentage_layer, GColorRed);
  }
  else{
    text_layer_set_text_color(s_C2_opposite_percentage_layer, GColorBlack);
  }
  
  //Displaying percentage
  snprintf(s_C2_opposite_percentage_text_buffer, 30,"%d",(int)percentage);
  strcat(s_C2_opposite_percentage_text_buffer,"%");
  text_layer_set_text(s_C2_opposite_percentage_layer, s_C2_opposite_percentage_text_buffer);
}
void computeAndDisplayC2M3(){
  //Computing percentage
  double numerator = (double)dataVariable[currentSetIndex][1][1][0] + (double)dataVariable[currentSetIndex][0][1][0] + (double)dataVariable[currentSetIndex][5][1][0];
  double denominator = numerator + (double)dataVariable[currentSetIndex][1][1][1] + (double)dataVariable[currentSetIndex][0][1][1] + (double)dataVariable[currentSetIndex][5][1][1];
  
  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 40){
    text_layer_set_text_color(s_C2_M3_percentage_layer, GColorRed);
  }
  else{
    text_layer_set_text_color(s_C2_M3_percentage_layer, GColorBlack);
  }
  
  //Displaying percentage
  snprintf(s_C2_M3_percentage_text_buffer, 30,"%d",(int)percentage);
  strcat(s_C2_M3_percentage_text_buffer,"%");
  text_layer_set_text(s_C2_M3_percentage_layer, s_C2_M3_percentage_text_buffer);
}
void computeAndDisplayC2M6(){
  //Computing percentage
  double numerator = (double)dataVariable[currentSetIndex][4][1][0] + (double)dataVariable[currentSetIndex][3][1][0] + (double)dataVariable[currentSetIndex][2][1][0];
  double denominator = numerator + (double)dataVariable[currentSetIndex][4][1][1] + (double)dataVariable[currentSetIndex][3][1][1] + (double)dataVariable[currentSetIndex][2][1][1];
  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  
  if(percentage < 40){
    text_layer_set_text_color(s_C2_M6_percentage_layer, GColorRed);
  }
  else{
    text_layer_set_text_color(s_C2_M6_percentage_layer, GColorBlack);
  }
  //Displaying percentage
  snprintf(s_C2_M6_percentage_text_buffer, 30,"%d",(int)percentage);
  strcat(s_C2_M6_percentage_text_buffer,"%");
  text_layer_set_text(s_C2_M6_percentage_layer, s_C2_M6_percentage_text_buffer);
}


static void stat_by_player_short_up_click_handler(ClickRecognizerRef recognizer, void *context) {
  //TO SMTH
}


static void stat_by_player_window_click_config_provider(void *context) {
  
    ButtonId idUp = BUTTON_ID_UP; //The down button
  
    window_single_click_subscribe(idUp,stat_by_player_short_up_click_handler);
  
}

static void stat_by_player_window_load(Window *window) {
  
  //Mallocing buffers
  s_C1_setter_percentage_text_buffer = malloc(sizeof(char) * 30);
  s_C1_M6_percentage_text_buffer = malloc(sizeof(char) * 30);
  s_C1_M3_percentage_text_buffer = malloc(sizeof(char) * 30);
  s_C1_opposite_percentage_text_buffer = malloc(sizeof(char) * 30);
  s_C1_R5_percentage_text_buffer = malloc(sizeof(char) * 30);
  s_C1_R2_percentage_text_buffer = malloc(sizeof(char) * 30);
  
  s_C2_setter_percentage_text_buffer = malloc(sizeof(char) * 30);
  s_C2_M6_percentage_text_buffer = malloc(sizeof(char) * 30);
  s_C2_M3_percentage_text_buffer = malloc(sizeof(char) * 30);
  s_C2_opposite_percentage_text_buffer = malloc(sizeof(char) * 30);
  s_C2_R5_percentage_text_buffer = malloc(sizeof(char) * 30); 
  s_C2_R2_percentage_text_buffer = malloc(sizeof(char) * 30);
  
  // Get information about the Window
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  
  /*
    UP PART OF THE SCREEN
  */
  
  //Creating the C1 up text Layer 
  s_C1_up_layer = text_layer_create(
  GRect(0, 2*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C1_up_layer, GColorClear);
  text_layer_set_text_color(s_C1_up_layer, GColorBlack);
  text_layer_set_text(s_C1_up_layer, "C1");
  text_layer_set_text_alignment(s_C1_up_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C1_up_layer,fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C1_up_layer));
  
    //Creating the C2 up text Layer 
  s_C2_up_layer = text_layer_create(
  GRect(0, 3*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C2_up_layer, GColorClear);
  text_layer_set_text_color(s_C2_up_layer, GColorBlack);
  text_layer_set_text(s_C2_up_layer, "C2");
  text_layer_set_text_alignment(s_C2_up_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C2_up_layer,fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C2_up_layer));
  
  //Creating the Setter text Layer 
  s_setter_layer = text_layer_create(
  GRect(bounds.size.w/4, 0, bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_setter_layer, GColorClear);
  text_layer_set_text_color(s_setter_layer, GColorBlack);
  text_layer_set_text(s_setter_layer, "Set");
  text_layer_set_text_alignment(s_setter_layer, GTextAlignmentLeft);
  text_layer_set_font(s_setter_layer,fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_setter_layer));
  
  //Creating the R2 text Layer 
  s_R2_layer = text_layer_create(
  GRect(2*(bounds.size.w/4), 0 , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_R2_layer, GColorClear);
  text_layer_set_text_color(s_R2_layer, GColorBlack);
  text_layer_set_text(s_R2_layer, "R2");
  text_layer_set_text_alignment(s_R2_layer, GTextAlignmentLeft);
  text_layer_set_font(s_R2_layer,fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_R2_layer));
  
  //Creating the R5 text Layer 
  s_R5_layer = text_layer_create(
  GRect(3*(bounds.size.w/4), 0 , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_R5_layer, GColorClear);
  text_layer_set_text_color(s_R5_layer, GColorBlack);
  text_layer_set_text(s_R5_layer, "R5");
  text_layer_set_text_alignment(s_R5_layer, GTextAlignmentLeft);
  text_layer_set_font(s_R5_layer,fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_R5_layer));
  
  //Creating the C1_setter percentage text Layer 
  s_C1_setter_percentage_layer = text_layer_create(
  GRect(bounds.size.w/4, 2*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C1_setter_percentage_layer, GColorClear);
  computeAndDisplayC1Setter();
  text_layer_set_text_alignment(s_C1_setter_percentage_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C1_setter_percentage_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C1_setter_percentage_layer));
  
  //Creating the C2_setter percentage text Layer 
  s_C2_setter_percentage_layer = text_layer_create(
  GRect(bounds.size.w/4, 3*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C2_setter_percentage_layer, GColorClear);
  computeAndDisplayC2Setter();
  text_layer_set_text_alignment(s_C2_setter_percentage_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C2_setter_percentage_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C2_setter_percentage_layer));
  
  //Creating the C1_R2 percentage text Layer 
  s_C1_R2_percentage_layer = text_layer_create(
  GRect(2*(bounds.size.w/4), 2*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C1_R2_percentage_layer, GColorClear);
  computeAndDisplayC1R2();
  text_layer_set_text_alignment(s_C1_R2_percentage_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C1_R2_percentage_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C1_R2_percentage_layer));
  
    //Creating the C2_R2 percentage text Layer 
  s_C2_R2_percentage_layer = text_layer_create(
  GRect(2*(bounds.size.w/4), 3*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C2_R2_percentage_layer, GColorClear);
  computeAndDisplayC2R2();
  text_layer_set_text_alignment(s_C2_R2_percentage_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C2_R2_percentage_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C2_R2_percentage_layer));
  
  //Creating the C1_R5 percentage text Layer 
  s_C1_R5_percentage_layer = text_layer_create(
  GRect(3*(bounds.size.w/4), 2*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C1_R5_percentage_layer, GColorClear);
  computeAndDisplayC1R5();
  text_layer_set_text_alignment(s_C1_R5_percentage_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C1_R5_percentage_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C1_R5_percentage_layer));

  //Creating the C2_R5 percentage text Layer
  
  s_C2_R5_percentage_layer = text_layer_create(
  GRect(3*(bounds.size.w/4), 3*(bounds.size.h/10) , bounds.size.w, bounds.size.h));

  text_layer_set_background_color(s_C2_R5_percentage_layer, GColorClear);
  computeAndDisplayC2R5();
  text_layer_set_text_alignment(s_C2_R5_percentage_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C2_R5_percentage_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C2_R5_percentage_layer));
  
  /*
    DOWN PART OF THE SCREEN
  */
  
  //Creating the C1 down text Layer 
  s_C1_down_layer = text_layer_create(
  GRect(0, 7*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C1_down_layer, GColorClear);
  text_layer_set_text_color(s_C1_down_layer, GColorBlack);
  text_layer_set_text(s_C1_down_layer, "C1");
  text_layer_set_text_alignment(s_C1_down_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C1_down_layer,fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C1_down_layer));
  
  
    //Creating the C2 down text Layer 
  s_C2_down_layer = text_layer_create(
  GRect(0, 8*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C2_down_layer, GColorClear);
  text_layer_set_text_color(s_C2_down_layer, GColorBlack);
  text_layer_set_text(s_C2_down_layer, "C2");
  text_layer_set_text_alignment(s_C2_down_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C2_down_layer,fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C2_down_layer));
  
  
  //Creating the Opposite text Layer 
  
  s_opposite_layer = text_layer_create(
  GRect(bounds.size.w/4, 5*(bounds.size.h/10), bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_opposite_layer, GColorClear);
  text_layer_set_text_color(s_opposite_layer, GColorBlack);
  text_layer_set_text(s_opposite_layer, "Opp");
  text_layer_set_text_alignment(s_opposite_layer, GTextAlignmentLeft);
  text_layer_set_font(s_opposite_layer,fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_opposite_layer));

  //Creating the M3 text Layer 
  s_M3_layer = text_layer_create(
  GRect(2*(bounds.size.w/4), 5*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_M3_layer, GColorClear);
  text_layer_set_text_color(s_M3_layer, GColorBlack);
  text_layer_set_text(s_M3_layer, "M3");
  text_layer_set_text_alignment(s_M3_layer, GTextAlignmentLeft);
  text_layer_set_font(s_M3_layer,fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_M3_layer));
  
  //Creating the M6 text Layer 
  s_M6_layer = text_layer_create(
  GRect(3*(bounds.size.w/4), 5*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_M6_layer, GColorClear);
  text_layer_set_text_color(s_M6_layer, GColorBlack);
  text_layer_set_text(s_M6_layer, "M6");
  text_layer_set_text_alignment(s_M6_layer, GTextAlignmentLeft);
  text_layer_set_font(s_M6_layer,fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_M6_layer));
  
    //Creating the C1_opposite percentage text Layer 
  s_C1_opposite_percentage_layer = text_layer_create(
  GRect(bounds.size.w/4, 7*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C1_opposite_percentage_layer, GColorClear);
  computeAndDisplayC1opposite();
  text_layer_set_text_alignment(s_C1_opposite_percentage_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C1_opposite_percentage_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C1_opposite_percentage_layer));
  
  //Creating the C2_opposite percentage text Layer 
  s_C2_opposite_percentage_layer = text_layer_create(
  GRect(bounds.size.w/4, 8*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C2_opposite_percentage_layer, GColorClear);
  computeAndDisplayC2opposite();
  text_layer_set_text_alignment(s_C2_opposite_percentage_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C2_opposite_percentage_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C2_opposite_percentage_layer));
  
  //Creating the C1_M3 percentage text Layer 
  s_C1_M3_percentage_layer = text_layer_create(
  GRect(2*(bounds.size.w/4), 7*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C1_M3_percentage_layer, GColorClear);
  computeAndDisplayC1M3();
  text_layer_set_text_alignment(s_C1_M3_percentage_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C1_M3_percentage_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C1_M3_percentage_layer));
  
    //Creating the C2_M3 percentage text Layer 
  s_C2_M3_percentage_layer = text_layer_create(
  GRect(2*(bounds.size.w/4), 8*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C2_M3_percentage_layer, GColorClear);
  computeAndDisplayC2M3();
  text_layer_set_text_alignment(s_C2_M3_percentage_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C2_M3_percentage_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C2_M3_percentage_layer));
  
  
  //Creating the C1_M6 percentage text Layer 
  s_C1_M6_percentage_layer = text_layer_create(
  GRect(3*(bounds.size.w/4), 7*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C1_M6_percentage_layer, GColorClear);
  computeAndDisplayC1M6();
  text_layer_set_text_alignment(s_C1_M6_percentage_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C1_M6_percentage_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C1_M6_percentage_layer));
  
  //Creating the C2_M6 percentage text Layer 
  s_C2_M6_percentage_layer = text_layer_create(
  GRect(3*(bounds.size.w/4), 8*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C2_M6_percentage_layer, GColorClear);
  computeAndDisplayC2M6();
  text_layer_set_text_alignment(s_C2_M6_percentage_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C2_M6_percentage_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C2_M6_percentage_layer));
  
}

static void stat_by_player_window_unload(Window *window){
  
  text_layer_destroy(s_C1_up_layer);
  text_layer_destroy(s_C2_up_layer);
  
  text_layer_destroy(s_C1_down_layer);
  text_layer_destroy(s_C2_down_layer);
  
  text_layer_destroy(s_setter_layer);
  text_layer_destroy(s_R2_layer);
  text_layer_destroy(s_R5_layer);
  text_layer_destroy(s_opposite_layer);
  text_layer_destroy(s_M3_layer);
  text_layer_destroy(s_M6_layer);
  
  text_layer_destroy(s_C1_setter_percentage_layer);
  text_layer_destroy(s_C1_M6_percentage_layer);
  text_layer_destroy(s_C1_M3_percentage_layer);
  text_layer_destroy(s_C1_opposite_percentage_layer);
  text_layer_destroy(s_C1_R5_percentage_layer);
  text_layer_destroy(s_C1_R2_percentage_layer);
  
  text_layer_destroy(s_C2_setter_percentage_layer);
  text_layer_destroy(s_C2_M6_percentage_layer);
  text_layer_destroy(s_C2_M3_percentage_layer);
  text_layer_destroy(s_C2_opposite_percentage_layer);
  text_layer_destroy(s_C2_R5_percentage_layer);
  text_layer_destroy(s_C2_R2_percentage_layer);
  
  free(s_C1_setter_percentage_text_buffer);
  free(s_C1_M6_percentage_text_buffer);
  free(s_C1_M3_percentage_text_buffer);
  free(s_C1_opposite_percentage_text_buffer);
  free(s_C1_R5_percentage_text_buffer);
  free(s_C1_R2_percentage_text_buffer);
  
  free(s_C2_setter_percentage_text_buffer);
  free(s_C2_M6_percentage_text_buffer);
  free(s_C2_M3_percentage_text_buffer);
  free(s_C2_opposite_percentage_text_buffer);
  free(s_C2_R5_percentage_text_buffer);
  free(s_C2_R2_percentage_text_buffer);
  
}

void initialize_stat_by_player_window(){
  //Creating window
  g_stat_by_player_window = window_create();
  
  //Setting the click handler
  window_set_click_config_provider(g_stat_by_player_window, stat_by_player_window_click_config_provider);
  
  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(g_stat_by_player_window, (WindowHandlers) {
    .load = stat_by_player_window_load,
    .unload = stat_by_player_window_unload
  });
  
}