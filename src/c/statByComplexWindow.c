#include <pebble.h>
#include "statByComplexWindow.h"
#include "windows.h"
#include "data.h"

static TextLayer *s_C1_up_layer;
static TextLayer *s_C2_up_layer;

static TextLayer *s_C1_down_layer;
static TextLayer *s_C2_down_layer;

static TextLayer *s_S1_layer;
static TextLayer *s_S2_layer;
static TextLayer *s_S3_layer;
static TextLayer *s_S4_layer;
static TextLayer *s_S5_layer;
static TextLayer *s_S6_layer;

static TextLayer *s_C1_S1_percentage_layer;
static TextLayer *s_C1_S2_percentage_layer;
static TextLayer *s_C1_S3_percentage_layer;
static TextLayer *s_C1_S4_percentage_layer;
static TextLayer *s_C1_S5_percentage_layer;
static TextLayer *s_C1_S6_percentage_layer;

static TextLayer *s_C2_S1_percentage_layer;
static TextLayer *s_C2_S2_percentage_layer;
static TextLayer *s_C2_S3_percentage_layer;
static TextLayer *s_C2_S4_percentage_layer;
static TextLayer *s_C2_S5_percentage_layer;
static TextLayer *s_C2_S6_percentage_layer;

char* s_C1_S1_percentage_text_buffer;
char* s_C1_S2_percentage_text_buffer;
char* s_C1_S3_percentage_text_buffer;
char* s_C1_S4_percentage_text_buffer;
char* s_C1_S5_percentage_text_buffer;
char* s_C1_S6_percentage_text_buffer;

char* s_C2_S1_percentage_text_buffer;
char* s_C2_S2_percentage_text_buffer;
char* s_C2_S3_percentage_text_buffer;
char* s_C2_S4_percentage_text_buffer;
char* s_C2_S5_percentage_text_buffer;
char* s_C2_S6_percentage_text_buffer;


void computeAndDisplayC1S1(){
  //Computing percentage
  double numerator = (double)dataVariable[currentSetIndex][0][0][0];
  double denominator = numerator + (double)dataVariable[currentSetIndex][0][0][1];
    
  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 60){
    text_layer_set_text_color(s_C1_S1_percentage_layer, GColorRed);
  }
  else{
    text_layer_set_text_color(s_C1_S1_percentage_layer, GColorBlack);
  }
  
  //Displaying percentage
  snprintf(s_C1_S1_percentage_text_buffer, 30,"%d",(int)percentage);
  strcat(s_C1_S1_percentage_text_buffer,"%");
  text_layer_set_text(s_C1_S1_percentage_layer, s_C1_S1_percentage_text_buffer);
  
}
void computeAndDisplayC1S6(){
  //Computing percentage
  double numerator = (double)dataVariable[currentSetIndex][5][0][0];
  double denominator = numerator + (double)dataVariable[currentSetIndex][5][0][1];
  
  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 60){
    text_layer_set_text_color(s_C1_S6_percentage_layer, GColorRed);
  }
  else{
    text_layer_set_text_color(s_C1_S6_percentage_layer, GColorBlack);
  }
  
  //Displaying percentage
  snprintf(s_C1_S6_percentage_text_buffer, 30,"%d",(int)percentage);
  strcat(s_C1_S6_percentage_text_buffer,"%");
  text_layer_set_text(s_C1_S6_percentage_layer, s_C1_S6_percentage_text_buffer);
}
void computeAndDisplayC1S5(){
  //Computing percentage
  double numerator = (double)dataVariable[currentSetIndex][4][0][0];
  double denominator = numerator + (double)dataVariable[currentSetIndex][4][0][1];
  
  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 60){
    text_layer_set_text_color(s_C1_S5_percentage_layer, GColorRed);
  }
  else{
    text_layer_set_text_color(s_C1_S5_percentage_layer, GColorBlack);
  }
  
  //Displaying percentage
  snprintf(s_C1_S5_percentage_text_buffer, 30,"%d",(int)percentage);
  strcat(s_C1_S5_percentage_text_buffer,"%");
  text_layer_set_text(s_C1_S5_percentage_layer, s_C1_S5_percentage_text_buffer);
}
void computeAndDisplayC1S4(){
  //Computing percentage
  double numerator = (double)dataVariable[currentSetIndex][3][0][0];
  double denominator = numerator + (double)dataVariable[currentSetIndex][3][0][1];
  
  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 60){
    text_layer_set_text_color(s_C1_S4_percentage_layer, GColorRed);
  }
  else{
    text_layer_set_text_color(s_C1_S4_percentage_layer, GColorBlack);
  }
  
  //Displaying percentage
  snprintf(s_C1_S4_percentage_text_buffer, 30,"%d",(int)percentage);
  strcat(s_C1_S4_percentage_text_buffer,"%");
  text_layer_set_text(s_C1_S4_percentage_layer, s_C1_S4_percentage_text_buffer);
}
void computeAndDisplayC1S3(){
  //Computing percentage
  double numerator = (double)dataVariable[currentSetIndex][2][0][0];
  double denominator = numerator + (double)dataVariable[currentSetIndex][2][0][1];
  
  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 60){
    text_layer_set_text_color(s_C1_S3_percentage_layer, GColorRed);
  }
  else{
    text_layer_set_text_color(s_C1_S3_percentage_layer, GColorBlack);
  }
  
  //Displaying percentage
  snprintf(s_C1_S3_percentage_text_buffer, 30,"%d",(int)percentage);
  strcat(s_C1_S3_percentage_text_buffer,"%");
  text_layer_set_text(s_C1_S3_percentage_layer, s_C1_S3_percentage_text_buffer);
}
void computeAndDisplayC1S2(){
  //Computing percentage
  double numerator = (double)dataVariable[currentSetIndex][1][0][0];
  double denominator = numerator + (double)dataVariable[currentSetIndex][1][0][1];
  
  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 60){
    text_layer_set_text_color(s_C1_S2_percentage_layer, GColorRed);
  }
  else{
    text_layer_set_text_color(s_C1_S2_percentage_layer, GColorBlack);
  }
  
  //Displaying percentage
  snprintf(s_C1_S2_percentage_text_buffer, 30,"%d",(int)percentage);
  strcat(s_C1_S2_percentage_text_buffer,"%");
  text_layer_set_text(s_C1_S2_percentage_layer, s_C1_S2_percentage_text_buffer);
}


void computeAndDisplayC2S1(){
  //Computing percentage
  double numerator = (double)dataVariable[currentSetIndex][0][1][0];
  double denominator = numerator + (double)dataVariable[currentSetIndex][0][1][1];
  
  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 40){
    text_layer_set_text_color(s_C2_S1_percentage_layer, GColorRed);
  }
  else{
    text_layer_set_text_color(s_C2_S1_percentage_layer, GColorBlack);
  }
  
  //Displaying percentage
  snprintf(s_C2_S1_percentage_text_buffer, 30,"%d",(int)percentage);
  strcat(s_C2_S1_percentage_text_buffer,"%");
  text_layer_set_text(s_C2_S1_percentage_layer, s_C2_S1_percentage_text_buffer);
}
void computeAndDisplayC2S6(){
  //Computing percentage
  double numerator = (double)dataVariable[currentSetIndex][5][1][0];
  double denominator = numerator + (double)dataVariable[currentSetIndex][5][1][1];
  
  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 40){
    text_layer_set_text_color(s_C2_S6_percentage_layer, GColorRed);
  }
  else{
    text_layer_set_text_color(s_C2_S6_percentage_layer, GColorBlack);
  }
  
  //Displaying percentage
  snprintf(s_C2_S6_percentage_text_buffer, 30,"%d",(int)percentage);
  strcat(s_C2_S6_percentage_text_buffer,"%");
  text_layer_set_text(s_C2_S6_percentage_layer, s_C2_S6_percentage_text_buffer);
}
void computeAndDisplayC2S5(){
  //Computing percentage
  double numerator = (double)dataVariable[currentSetIndex][4][1][0];
  double denominator = numerator + (double)dataVariable[currentSetIndex][4][1][1];
  
  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 40){
    text_layer_set_text_color(s_C2_S5_percentage_layer, GColorRed);
  }
  else{
    text_layer_set_text_color(s_C2_S5_percentage_layer, GColorBlack);
  }
  
  //Displaying percentage
  snprintf(s_C2_S5_percentage_text_buffer, 30,"%d",(int)percentage);
  strcat(s_C2_S5_percentage_text_buffer,"%");
  text_layer_set_text(s_C2_S5_percentage_layer, s_C2_S5_percentage_text_buffer);
}
void computeAndDisplayC2S4(){
  //Computing percentage
  double numerator = (double)dataVariable[currentSetIndex][3][1][0];
  double denominator = numerator + (double)dataVariable[currentSetIndex][3][1][1];
  
  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 40){
    text_layer_set_text_color(s_C2_S4_percentage_layer, GColorRed);
  }
  else{
    text_layer_set_text_color(s_C2_S4_percentage_layer, GColorBlack);
  }
  
  //Displaying percentage
  snprintf(s_C2_S4_percentage_text_buffer, 30,"%d",(int)percentage);
  strcat(s_C2_S4_percentage_text_buffer,"%");
  text_layer_set_text(s_C2_S4_percentage_layer, s_C2_S4_percentage_text_buffer);
}
void computeAndDisplayC2S3(){
  //Computing percentage
  double numerator = (double)dataVariable[currentSetIndex][2][1][0];
  double denominator = numerator + (double)dataVariable[currentSetIndex][2][1][1];
  
  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 40){
    text_layer_set_text_color(s_C2_S3_percentage_layer, GColorRed);
  }
  else{
    text_layer_set_text_color(s_C2_S3_percentage_layer, GColorBlack);
  }
  
  //Displaying percentage
  snprintf(s_C2_S3_percentage_text_buffer, 30,"%d",(int)percentage);
  strcat(s_C2_S3_percentage_text_buffer,"%");
  text_layer_set_text(s_C2_S3_percentage_layer, s_C2_S3_percentage_text_buffer);
}
void computeAndDisplayC2S2(){
  //Computing percentage
  double numerator = (double)dataVariable[currentSetIndex][1][1][0];
  double denominator = numerator + (double)dataVariable[currentSetIndex][1][1][1];
  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  
  if(percentage < 40){
    text_layer_set_text_color(s_C2_S2_percentage_layer, GColorRed);
  }
  else{
    text_layer_set_text_color(s_C2_S2_percentage_layer, GColorBlack);
  }
  //Displaying percentage
  snprintf(s_C2_S2_percentage_text_buffer, 30,"%d",(int)percentage);
  strcat(s_C2_S2_percentage_text_buffer,"%");
  text_layer_set_text(s_C2_S2_percentage_layer, s_C2_S2_percentage_text_buffer);
}


static void stat_by_complex_short_down_click_handler(ClickRecognizerRef recognizer, void *context) {
  window_stack_push(g_stat_by_player_window, true);
}


static void stat_by_complex_window_click_config_provider(void *context) {
  
    ButtonId idDown = BUTTON_ID_DOWN; //The down button
  
    window_single_click_subscribe(idDown,stat_by_complex_short_down_click_handler);
  
}

static void stat_by_complex_window_load(Window *window) {
  
  //Mallocing buffers
  s_C1_S1_percentage_text_buffer = malloc(sizeof(char) * 30);
  s_C1_S2_percentage_text_buffer = malloc(sizeof(char) * 30);
  s_C1_S3_percentage_text_buffer = malloc(sizeof(char) * 30);
  s_C1_S4_percentage_text_buffer = malloc(sizeof(char) * 30);
  s_C1_S5_percentage_text_buffer = malloc(sizeof(char) * 30);
  s_C1_S6_percentage_text_buffer = malloc(sizeof(char) * 30);
  
  s_C2_S1_percentage_text_buffer = malloc(sizeof(char) * 30);
  s_C2_S2_percentage_text_buffer = malloc(sizeof(char) * 30);
  s_C2_S3_percentage_text_buffer = malloc(sizeof(char) * 30);
  s_C2_S4_percentage_text_buffer = malloc(sizeof(char) * 30);
  s_C2_S5_percentage_text_buffer = malloc(sizeof(char) * 30); 
  s_C2_S6_percentage_text_buffer = malloc(sizeof(char) * 30);
  
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
  
  //Creating the S1 text Layer 
  s_S1_layer = text_layer_create(
  GRect(bounds.size.w/4, 0, bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_S1_layer, GColorClear);
  text_layer_set_text_color(s_S1_layer, GColorBlack);
  text_layer_set_text(s_S1_layer, "S1");
  text_layer_set_text_alignment(s_S1_layer, GTextAlignmentLeft);
  text_layer_set_font(s_S1_layer,fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_S1_layer));
  
  //Creating the S6 text Layer 
  s_S6_layer = text_layer_create(
  GRect(2*(bounds.size.w/4), 0 , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_S6_layer, GColorClear);
  text_layer_set_text_color(s_S6_layer, GColorBlack);
  text_layer_set_text(s_S6_layer, "S6");
  text_layer_set_text_alignment(s_S6_layer, GTextAlignmentLeft);
  text_layer_set_font(s_S6_layer,fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_S6_layer));
  
  //Creating the S5 text Layer 
  s_S5_layer = text_layer_create(
  GRect(3*(bounds.size.w/4), 0 , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_S5_layer, GColorClear);
  text_layer_set_text_color(s_S5_layer, GColorBlack);
  text_layer_set_text(s_S5_layer, "S5");
  text_layer_set_text_alignment(s_S5_layer, GTextAlignmentLeft);
  text_layer_set_font(s_S5_layer,fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_S5_layer));
  
  //Creating the C1_S1 percentage text Layer 
  s_C1_S1_percentage_layer = text_layer_create(
  GRect(bounds.size.w/4, 2*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C1_S1_percentage_layer, GColorClear);
  computeAndDisplayC1S1();
  text_layer_set_text_alignment(s_C1_S1_percentage_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C1_S1_percentage_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C1_S1_percentage_layer));
  
  //Creating the C2_S1 percentage text Layer 
  s_C2_S1_percentage_layer = text_layer_create(
  GRect(bounds.size.w/4, 3*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C2_S1_percentage_layer, GColorClear);
  computeAndDisplayC2S1();
  text_layer_set_text_alignment(s_C2_S1_percentage_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C2_S1_percentage_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C2_S1_percentage_layer));
  
  //Creating the C1_S6 percentage text Layer 
  s_C1_S6_percentage_layer = text_layer_create(
  GRect(2*(bounds.size.w/4), 2*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C1_S6_percentage_layer, GColorClear);
  computeAndDisplayC1S6();
  text_layer_set_text_alignment(s_C1_S6_percentage_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C1_S6_percentage_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C1_S6_percentage_layer));
  
    //Creating the C2_S6 percentage text Layer 
  s_C2_S6_percentage_layer = text_layer_create(
  GRect(2*(bounds.size.w/4), 3*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C2_S6_percentage_layer, GColorClear);
  computeAndDisplayC2S6();
  text_layer_set_text_alignment(s_C2_S6_percentage_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C2_S6_percentage_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C2_S6_percentage_layer));
  
  
  //Creating the C1_S5 percentage text Layer 
  s_C1_S5_percentage_layer = text_layer_create(
  GRect(3*(bounds.size.w/4), 2*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C1_S5_percentage_layer, GColorClear);
  computeAndDisplayC1S5();
  text_layer_set_text_alignment(s_C1_S5_percentage_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C1_S5_percentage_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C1_S5_percentage_layer));
  
  //Creating the C2_S5 percentage text Layer 
  s_C2_S5_percentage_layer = text_layer_create(
  GRect(3*(bounds.size.w/4), 3*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C2_S5_percentage_layer, GColorClear);
  computeAndDisplayC2S5();
  text_layer_set_text_alignment(s_C2_S5_percentage_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C2_S5_percentage_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C2_S5_percentage_layer));
  
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
  
  //Creating the S4 text Layer 
  s_S4_layer = text_layer_create(
  GRect(bounds.size.w/4, 5*(bounds.size.h/10), bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_S4_layer, GColorClear);
  text_layer_set_text_color(s_S4_layer, GColorBlack);
  text_layer_set_text(s_S4_layer, "S4");
  text_layer_set_text_alignment(s_S4_layer, GTextAlignmentLeft);
  text_layer_set_font(s_S4_layer,fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_S4_layer));
  
  //Creating the S3 text Layer 
  s_S3_layer = text_layer_create(
  GRect(2*(bounds.size.w/4), 5*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_S3_layer, GColorClear);
  text_layer_set_text_color(s_S3_layer, GColorBlack);
  text_layer_set_text(s_S3_layer, "S3");
  text_layer_set_text_alignment(s_S3_layer, GTextAlignmentLeft);
  text_layer_set_font(s_S3_layer,fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_S3_layer));
  
  //Creating the S2 text Layer 
  s_S2_layer = text_layer_create(
  GRect(3*(bounds.size.w/4), 5*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_S2_layer, GColorClear);
  text_layer_set_text_color(s_S2_layer, GColorBlack);
  text_layer_set_text(s_S2_layer, "S2");
  text_layer_set_text_alignment(s_S2_layer, GTextAlignmentLeft);
  text_layer_set_font(s_S2_layer,fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_S2_layer));
  
    //Creating the C1_S4 percentage text Layer 
  s_C1_S4_percentage_layer = text_layer_create(
  GRect(bounds.size.w/4, 7*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C1_S4_percentage_layer, GColorClear);
  computeAndDisplayC1S4();
  text_layer_set_text_alignment(s_C1_S4_percentage_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C1_S4_percentage_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C1_S4_percentage_layer));
  
  //Creating the C2_S4 percentage text Layer 
  s_C2_S4_percentage_layer = text_layer_create(
  GRect(bounds.size.w/4, 8*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C2_S4_percentage_layer, GColorClear);
  computeAndDisplayC2S4();
  text_layer_set_text_alignment(s_C2_S4_percentage_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C2_S4_percentage_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C2_S4_percentage_layer));
  
  //Creating the C1_S3 percentage text Layer 
  s_C1_S3_percentage_layer = text_layer_create(
  GRect(2*(bounds.size.w/4), 7*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C1_S3_percentage_layer, GColorClear);
  computeAndDisplayC1S3();
  text_layer_set_text_alignment(s_C1_S3_percentage_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C1_S3_percentage_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C1_S3_percentage_layer));
  
    //Creating the C2_S3 percentage text Layer 
  s_C2_S3_percentage_layer = text_layer_create(
  GRect(2*(bounds.size.w/4), 8*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C2_S3_percentage_layer, GColorClear);
  computeAndDisplayC2S3();
  text_layer_set_text_alignment(s_C2_S3_percentage_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C2_S3_percentage_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C2_S3_percentage_layer));
  
  
  //Creating the C1_S2 percentage text Layer 
  s_C1_S2_percentage_layer = text_layer_create(
  GRect(3*(bounds.size.w/4), 7*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C1_S2_percentage_layer, GColorClear);
  computeAndDisplayC1S2();
  text_layer_set_text_alignment(s_C1_S2_percentage_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C1_S2_percentage_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C1_S2_percentage_layer));
  
  //Creating the C2_S2 percentage text Layer 
  s_C2_S2_percentage_layer = text_layer_create(
  GRect(3*(bounds.size.w/4), 8*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  
  text_layer_set_background_color(s_C2_S2_percentage_layer, GColorClear);
  computeAndDisplayC2S2();
  text_layer_set_text_alignment(s_C2_S2_percentage_layer, GTextAlignmentLeft);
  text_layer_set_font(s_C2_S2_percentage_layer,fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  
  layer_add_child(window_layer, text_layer_get_layer(s_C2_S2_percentage_layer));
  
}

static void stat_by_complex_window_unload(Window *window){
  
  text_layer_destroy(s_C1_up_layer);
  text_layer_destroy(s_C2_up_layer);
  
  text_layer_destroy(s_C1_down_layer);
  text_layer_destroy(s_C2_down_layer);
  
  text_layer_destroy(s_S1_layer);
  text_layer_destroy(s_S2_layer);
  text_layer_destroy(s_S3_layer);
  text_layer_destroy(s_S4_layer);
  text_layer_destroy(s_S5_layer);
  text_layer_destroy(s_S6_layer);
  
  text_layer_destroy(s_C1_S1_percentage_layer);
  text_layer_destroy(s_C1_S2_percentage_layer);
  text_layer_destroy(s_C1_S3_percentage_layer);
  text_layer_destroy(s_C1_S4_percentage_layer);
  text_layer_destroy(s_C1_S5_percentage_layer);
  text_layer_destroy(s_C1_S6_percentage_layer);
  
  text_layer_destroy(s_C2_S1_percentage_layer);
  text_layer_destroy(s_C2_S2_percentage_layer);
  text_layer_destroy(s_C2_S3_percentage_layer);
  text_layer_destroy(s_C2_S4_percentage_layer);
  text_layer_destroy(s_C2_S5_percentage_layer);
  text_layer_destroy(s_C2_S6_percentage_layer);
  
  free(s_C1_S1_percentage_text_buffer);
  free(s_C1_S2_percentage_text_buffer);
  free(s_C1_S3_percentage_text_buffer);
  free(s_C1_S4_percentage_text_buffer);
  free(s_C1_S5_percentage_text_buffer);
  free(s_C1_S6_percentage_text_buffer);
  
  free(s_C2_S1_percentage_text_buffer);
  free(s_C2_S2_percentage_text_buffer);
  free(s_C2_S3_percentage_text_buffer);
  free(s_C2_S4_percentage_text_buffer);
  free(s_C2_S5_percentage_text_buffer);
  free(s_C2_S6_percentage_text_buffer);
  
}

void initialize_stat_by_complex_window(){
  //Creating window
  g_stat_by_complex_window = window_create();
  
  //Setting the click handler
  window_set_click_config_provider(g_stat_by_complex_window, stat_by_complex_window_click_config_provider);
  
  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(g_stat_by_complex_window, (WindowHandlers) {
    .load = stat_by_complex_window_load,
    .unload = stat_by_complex_window_unload
  });
  
}