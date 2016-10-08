#include <pebble.h>
#include "statByComplexWindow.h"
#include "data.h"
#include "gameWindow.h"
#include "matchOverWindow.h"

int previousWindowIsGameWindow;
int displayComplex = 1;
int setNumber;
static Window *g_stat_by_complex_window;
static TextLayer *s_set_label_layer;

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

char* s_set_label_text_buffer;

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

void computeAndDisplaySetLabel(){
  if(setNumber == 5){
    text_layer_set_text(s_set_label_layer, "Total");
  }
  else{
  //Displaying percentage
  snprintf(s_set_label_text_buffer, 30,"Set %d",(int)(setNumber+1));
  text_layer_set_text(s_set_label_layer, s_set_label_text_buffer);
  }

}

void computeAndDisplayS1(int complex,TextLayer *layer, char* text_buffer){
  //Computing percentage
  double numerator = (double)dataVariable[setNumber][0][complex][0];
  double denominator = numerator + (double)dataVariable[setNumber][0][complex][1];

  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 60){
    text_layer_set_text_color(layer, GColorRed);
  }
  else{
    text_layer_set_text_color(layer, GColorBlack);
  }

  //Displaying percentage
  snprintf(text_buffer, 30,"%d",(int)percentage);
  strcat(text_buffer,"%");
  text_layer_set_text(layer,text_buffer);

}
void computeAndDisplayS6(int complex,TextLayer *layer, char* text_buffer){
  //Computing percentage
  double numerator = (double)dataVariable[setNumber][5][complex][0];
  double denominator = numerator + (double)dataVariable[setNumber][5][complex][1];

  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 60){
    text_layer_set_text_color(layer, GColorRed);
  }
  else{
    text_layer_set_text_color(layer, GColorBlack);
  }

  //Displaying percentage
  snprintf(text_buffer, 30,"%d",(int)percentage);
  strcat(text_buffer,"%");
  text_layer_set_text(layer, text_buffer);
}
void computeAndDisplayS5(int complex,TextLayer *layer, char* text_buffer){
  //Computing percentage
  double numerator = (double)dataVariable[setNumber][4][complex][0];
  double denominator = numerator + (double)dataVariable[setNumber][4][complex][1];

  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 60){
    text_layer_set_text_color(layer, GColorRed);
  }
  else{
    text_layer_set_text_color(layer, GColorBlack);
  }

  //Displaying percentage
  snprintf(text_buffer, 30,"%d",(int)percentage);
  strcat(text_buffer,"%");
  text_layer_set_text(layer, text_buffer);
}
void computeAndDisplayS4(int complex,TextLayer *layer, char* text_buffer){
  //Computing percentage
  double numerator = (double)dataVariable[setNumber][3][complex][0];
  double denominator = numerator + (double)dataVariable[setNumber][3][complex][1];

  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 60){
    text_layer_set_text_color(layer, GColorRed);
  }
  else{
    text_layer_set_text_color(layer, GColorBlack);
  }

  //Displaying percentage
  snprintf(text_buffer, 30,"%d",(int)percentage);
  strcat(text_buffer,"%");
  text_layer_set_text(layer, text_buffer);
}
void computeAndDisplayS3(int complex,TextLayer *layer, char* text_buffer){
  //Computing percentage
  double numerator = (double)dataVariable[setNumber][2][complex][0];
  double denominator = numerator + (double)dataVariable[setNumber][2][complex][1];

  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 60){
    text_layer_set_text_color(layer, GColorRed);
  }
  else{
    text_layer_set_text_color(layer, GColorBlack);
  }

  //Displaying percentage
  snprintf(text_buffer, 30,"%d",(int)percentage);
  strcat(text_buffer,"%");
  text_layer_set_text(layer, text_buffer);
}
void computeAndDisplayS2(int complex,TextLayer *layer, char* text_buffer){
  //Computing percentage
  double numerator = (double)dataVariable[setNumber][1][complex][0];
  double denominator = numerator + (double)dataVariable[setNumber][1][complex][1];

  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 60){
    text_layer_set_text_color(layer, GColorRed);
  }
  else{
    text_layer_set_text_color(layer, GColorBlack);
  }

  //Displaying percentage
  snprintf(text_buffer, 30,"%d",(int)percentage);
  strcat(text_buffer,"%");
  text_layer_set_text(layer, text_buffer);
}

void computeAndDisplaySetter(int complex,TextLayer *layer, char* text_buffer){
  //Computing percentage
  double numerator = (double)dataVariable[setNumber][3][complex][0] + (double)dataVariable[setNumber][2][complex][0] + (double)dataVariable[setNumber][1][complex][0];
  double denominator = numerator + (double)dataVariable[setNumber][3][complex][1] + (double)dataVariable[setNumber][2][complex][1] + (double)dataVariable[setNumber][1][complex][1];

  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 60){
    text_layer_set_text_color(layer, GColorRed);
  }
  else{
    text_layer_set_text_color(layer, GColorBlack);
  }

  //Displaying percentage
  snprintf(text_buffer, 30,"%d",(int)percentage);
  strcat(text_buffer,"%");
  text_layer_set_text(layer, text_buffer);

}
void computeAndDisplayR2(int complex,TextLayer *layer, char* text_buffer){
  //Computing percentage
  double numerator = (double)dataVariable[setNumber][3][complex][0] + (double)dataVariable[setNumber][2][complex][0] + (double)dataVariable[setNumber][1][complex][0];
  double denominator = numerator + (double)dataVariable[setNumber][3][complex][1] + (double)dataVariable[setNumber][2][complex][1] + (double)dataVariable[setNumber][1][complex][1];

  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 60){
    text_layer_set_text_color(layer, GColorRed);
  }
  else{
    text_layer_set_text_color(layer, GColorBlack);
  }

  //Displaying percentage
  snprintf(text_buffer, 30,"%d",(int)percentage);
  strcat(text_buffer,"%");
  text_layer_set_text(layer, text_buffer);
}
void computeAndDisplayR5(int complex,TextLayer *layer, char* text_buffer){
  //Computing percentage
  double numerator = (double)dataVariable[setNumber][5][complex][0] + (double)dataVariable[setNumber][4][complex][0] + (double)dataVariable[setNumber][2][complex][0];
  double denominator = numerator + (double)dataVariable[setNumber][5][complex][1] + (double)dataVariable[setNumber][4][complex][1] + (double)dataVariable[setNumber][3][complex][1];

  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 60){
    text_layer_set_text_color(layer, GColorRed);
  }
  else{
    text_layer_set_text_color(layer, GColorBlack);
  }

  //Displaying percentage
  snprintf(text_buffer, 30,"%d",(int)percentage);
  strcat(text_buffer,"%");
  text_layer_set_text(layer, text_buffer);
}
void computeAndDisplayopposite(int complex,TextLayer *layer, char* text_buffer){
  //Computing percentage
  double numerator = (double)dataVariable[setNumber][0][complex][0] + (double)dataVariable[setNumber][5][complex][0] + (double)dataVariable[setNumber][4][complex][0];
  double denominator = numerator + (double)dataVariable[setNumber][0][complex][1] + (double)dataVariable[setNumber][5][complex][1] + (double)dataVariable[setNumber][4][complex][1];

  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 60){
    text_layer_set_text_color(layer, GColorRed);
  }
  else{
    text_layer_set_text_color(layer, GColorBlack);
  }

  //Displaying percentage
  snprintf(text_buffer, 30,"%d",(int)percentage);
  strcat(text_buffer,"%");
  text_layer_set_text(layer, text_buffer);
}
void computeAndDisplayM3(int complex,TextLayer *layer, char* text_buffer){
  //Computing percentage
  double numerator = (double)dataVariable[setNumber][1][complex][0] + (double)dataVariable[setNumber][0][complex][0] + (double)dataVariable[setNumber][5][complex][0];
  double denominator = numerator + (double)dataVariable[setNumber][1][complex][1] + (double)dataVariable[setNumber][0][complex][1] + (double)dataVariable[setNumber][5][complex][1];

  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 60){
    text_layer_set_text_color(layer, GColorRed);
  }
  else{
    text_layer_set_text_color(layer, GColorBlack);
  }

  //Displaying percentage
  snprintf(text_buffer, 30,"%d",(int)percentage);
  strcat(text_buffer,"%");
  text_layer_set_text(layer, text_buffer);
}
void computeAndDisplayM6(int complex,TextLayer *layer, char* text_buffer){
  //Computing percentage
  double numerator = (double)dataVariable[setNumber][4][complex][0] + (double)dataVariable[setNumber][3][complex][0] + (double)dataVariable[setNumber][2][complex][0];
  double denominator = numerator + (double)dataVariable[setNumber][4][complex][1] + (double)dataVariable[setNumber][3][complex][1] + (double)dataVariable[setNumber][2][complex][1];

  double percentage;
  if(denominator == 0){
    percentage = 0;
  }
  else{
    percentage = (numerator / denominator)*100;
  }
  if(percentage < 60){
    text_layer_set_text_color(layer, GColorRed);
  }
  else{
    text_layer_set_text_color(layer, GColorBlack);
  }

  //Displaying percentage
  snprintf(text_buffer, 30,"%d",(int)percentage);
  strcat(text_buffer,"%");
  text_layer_set_text(layer, text_buffer);
}

void display_static_text_player(){
  text_layer_set_text(s_S1_layer, "Set");
  text_layer_set_text(s_S6_layer, "M3");
  text_layer_set_text(s_S5_layer, "M6");
  text_layer_set_text(s_S4_layer, "Opp");
  text_layer_set_text(s_S3_layer, "R2");
  text_layer_set_text(s_S2_layer, "R5");

}
void display_static_text_complex(){
  text_layer_set_text(s_S1_layer, "S1");
  text_layer_set_text(s_S6_layer, "S6");
  text_layer_set_text(s_S5_layer, "S5");
  text_layer_set_text(s_S4_layer, "S4");
  text_layer_set_text(s_S3_layer, "S3");
  text_layer_set_text(s_S2_layer, "S2");

}

void display_stat_by_complex(){

  computeAndDisplaySetLabel();

  //Computing percentages for complex1
  computeAndDisplayS1(0, s_C1_S1_percentage_layer, s_C1_S1_percentage_text_buffer);
  computeAndDisplayS6(0, s_C1_S6_percentage_layer, s_C1_S6_percentage_text_buffer);
  computeAndDisplayS5(0, s_C1_S5_percentage_layer, s_C1_S5_percentage_text_buffer);
  computeAndDisplayS4(0, s_C1_S4_percentage_layer, s_C1_S4_percentage_text_buffer);
  computeAndDisplayS3(0, s_C1_S3_percentage_layer, s_C1_S3_percentage_text_buffer);
  computeAndDisplayS2(0, s_C1_S2_percentage_layer, s_C1_S2_percentage_text_buffer);

  //Computing percentages for complex2
  computeAndDisplayS1(1, s_C2_S1_percentage_layer, s_C2_S1_percentage_text_buffer);
  computeAndDisplayS6(1, s_C2_S6_percentage_layer, s_C2_S6_percentage_text_buffer);
  computeAndDisplayS5(1, s_C2_S5_percentage_layer, s_C2_S5_percentage_text_buffer);
  computeAndDisplayS4(1, s_C2_S4_percentage_layer, s_C2_S4_percentage_text_buffer);
  computeAndDisplayS3(1, s_C2_S3_percentage_layer, s_C2_S3_percentage_text_buffer);
  computeAndDisplayS2(1, s_C2_S2_percentage_layer, s_C2_S2_percentage_text_buffer);

  display_static_text_complex();

}

void display_stat_by_player(){

  computeAndDisplaySetLabel();

  computeAndDisplaySetter(0, s_C1_S1_percentage_layer, s_C1_S1_percentage_text_buffer);
  computeAndDisplayR2(0, s_C1_S3_percentage_layer, s_C1_S3_percentage_text_buffer);
  computeAndDisplayR5(0, s_C1_S2_percentage_layer, s_C1_S2_percentage_text_buffer);
  computeAndDisplayopposite(0, s_C1_S4_percentage_layer, s_C1_S4_percentage_text_buffer);
  computeAndDisplayM3(0, s_C1_S6_percentage_layer, s_C1_S6_percentage_text_buffer);
  computeAndDisplayM6(0, s_C1_S5_percentage_layer, s_C1_S5_percentage_text_buffer);

  computeAndDisplaySetter(1, s_C2_S1_percentage_layer, s_C2_S1_percentage_text_buffer);
  computeAndDisplayR2(1, s_C2_S3_percentage_layer, s_C2_S3_percentage_text_buffer);
  computeAndDisplayR5(1, s_C2_S2_percentage_layer, s_C2_S2_percentage_text_buffer);
  computeAndDisplayopposite(1, s_C2_S4_percentage_layer, s_C2_S4_percentage_text_buffer);
  computeAndDisplayM3(1, s_C2_S6_percentage_layer, s_C2_S6_percentage_text_buffer);
  computeAndDisplayM6(1, s_C2_S5_percentage_layer, s_C2_S5_percentage_text_buffer);

  display_static_text_player();
}

static void stat_by_complex_short_back_click_handler(ClickRecognizerRef recognizer, void *context) {
  if(previousWindowIsGameWindow){
    window_stack_pop(true);
    initialize_game_window();
  }
  else{
    window_stack_pop(true);
    initialize_match_over_window();
  }
}
static void stat_by_complex_short_select_click_handler(ClickRecognizerRef recognizer, void *context) {
  if(displayComplex){
  display_stat_by_player();
  displayComplex = 0;
  }
  else{
    display_stat_by_complex();
    displayComplex = 1;
  }
}
static void stat_by_complex_short_up_click_handler(ClickRecognizerRef recognizer, void *context) {
  if(setNumber == 0){
    setNumber = 5;
  }
  else{
    setNumber--;
  }
  if(displayComplex){
  display_stat_by_complex();
  }
  else{
    display_stat_by_player();
  }
}
static void stat_by_complex_short_down_click_handler(ClickRecognizerRef recognizer, void *context) {
  if(setNumber == 5){
    setNumber = 0;
  }
  else{
    setNumber++;
  }
  if(displayComplex){
  display_stat_by_complex();
  }
  else{
    display_stat_by_player();
  }
}


static void stat_by_complex_window_click_config_provider(void *context) {

    ButtonId idSelect = BUTTON_ID_SELECT; //The down button
    ButtonId idBack = BUTTON_ID_BACK; //The back button
    ButtonId idUp = BUTTON_ID_UP; //The up button
    ButtonId idDown = BUTTON_ID_DOWN; //The down butt

    window_single_click_subscribe(idBack,stat_by_complex_short_back_click_handler);
    window_single_click_subscribe(idSelect,stat_by_complex_short_select_click_handler);
    window_single_click_subscribe(idUp, stat_by_complex_short_up_click_handler);
    window_single_click_subscribe(idDown,stat_by_complex_short_down_click_handler);
}
void init_label(TextLayer *s_layer, GColor background_color, GColor text_color, GTextAlignment text_alignment, const char * font_key, const char* text, Layer *window_layer){

  text_layer_set_background_color(s_layer, background_color);
  text_layer_set_text_alignment(s_layer, text_alignment);
  text_layer_set_font(s_layer,fonts_get_system_font(font_key));
  text_layer_set_text_color(s_layer, text_color);
  if(text != NULL){
     text_layer_set_text(s_layer, text);
  }
  layer_add_child(window_layer, text_layer_get_layer(s_layer));
}
static void stat_by_complex_window_load(Window *window) {

  //Mallocing buffers
  s_set_label_text_buffer = malloc(sizeof(char) * 20);

  s_C1_S1_percentage_text_buffer = malloc(sizeof(char) * 10);
  s_C1_S2_percentage_text_buffer = malloc(sizeof(char) * 10);
  s_C1_S3_percentage_text_buffer = malloc(sizeof(char) * 10);
  s_C1_S4_percentage_text_buffer = malloc(sizeof(char) * 10);
  s_C1_S5_percentage_text_buffer = malloc(sizeof(char) * 10);
  s_C1_S6_percentage_text_buffer = malloc(sizeof(char) * 10);

  s_C2_S1_percentage_text_buffer = malloc(sizeof(char) * 10);
  s_C2_S2_percentage_text_buffer = malloc(sizeof(char) * 10);
  s_C2_S3_percentage_text_buffer = malloc(sizeof(char) * 10);
  s_C2_S4_percentage_text_buffer = malloc(sizeof(char) * 10);
  s_C2_S5_percentage_text_buffer = malloc(sizeof(char) * 10);
  s_C2_S6_percentage_text_buffer = malloc(sizeof(char) * 10);

  // Get information about the Window
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  /*
    UP PART OF THE SCREEN
  */


  //Creating the set label text Layer
  s_set_label_layer = text_layer_create(GRect(0,PBL_IF_ROUND_ELSE((bounds.size.h/10) ,0) , bounds.size.w, bounds.size.h));
  init_label(s_set_label_layer, GColorClear, GColorLiberty, GTextAlignmentCenter, FONT_KEY_GOTHIC_18_BOLD, NULL, window_layer);

  //Creating the C1 up text Layer
  s_C1_up_layer = text_layer_create(GRect(PBL_IF_ROUND_ELSE((bounds.size.w/10),0), 3*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  init_label(s_C1_up_layer, GColorClear, GColorBlack, GTextAlignmentLeft, FONT_KEY_GOTHIC_18_BOLD, "C1", window_layer);

  //Creating the C2 up text Layer
  s_C2_up_layer = text_layer_create(GRect(PBL_IF_ROUND_ELSE((bounds.size.w/10),0), 4*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  init_label(s_C2_up_layer, GColorClear, GColorBlack, GTextAlignmentLeft, FONT_KEY_GOTHIC_18_BOLD, "C2", window_layer);

  //Creating the S1 text Layer
  s_S1_layer = text_layer_create(GRect(bounds.size.w/4,PBL_IF_ROUND_ELSE(2*(bounds.size.h/10),(bounds.size.h/10)), bounds.size.w, bounds.size.h));
  init_label(s_S1_layer, GColorClear, GColorBlack, GTextAlignmentLeft, FONT_KEY_GOTHIC_18_BOLD, NULL, window_layer);

  //Creating the S6 text Layer
  s_S6_layer = text_layer_create(GRect(2*(bounds.size.w/4), PBL_IF_ROUND_ELSE(2*(bounds.size.h/10),(bounds.size.h/10)) , bounds.size.w, bounds.size.h));
  init_label(s_S6_layer, GColorClear, GColorBlack, GTextAlignmentLeft, FONT_KEY_GOTHIC_18_BOLD, NULL, window_layer);

  //Creating the S5 text Layer
  s_S5_layer = text_layer_create(GRect(3*(bounds.size.w/4), PBL_IF_ROUND_ELSE(2*(bounds.size.h/10),(bounds.size.h/10)) , bounds.size.w, bounds.size.h));
  init_label(s_S5_layer, GColorClear, GColorBlack, GTextAlignmentLeft, FONT_KEY_GOTHIC_18_BOLD, NULL, window_layer);

  //Creating the C1_S1 percentage text Layer
  s_C1_S1_percentage_layer = text_layer_create(GRect(bounds.size.w/4, 3*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  init_label(s_C1_S1_percentage_layer, GColorClear, GColorBlack, GTextAlignmentLeft, FONT_KEY_GOTHIC_14_BOLD, NULL, window_layer);

  //Creating the C2_S1 percentage text Layer
  s_C2_S1_percentage_layer = text_layer_create(GRect(bounds.size.w/4, 4*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  init_label(s_C2_S1_percentage_layer, GColorClear, GColorBlack, GTextAlignmentLeft, FONT_KEY_GOTHIC_14_BOLD, NULL, window_layer);

  //Creating the C1_S6 percentage text Layer
  s_C1_S6_percentage_layer = text_layer_create(GRect(2*(bounds.size.w/4), 3*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  init_label(s_C1_S6_percentage_layer, GColorClear, GColorBlack, GTextAlignmentLeft, FONT_KEY_GOTHIC_14_BOLD, NULL, window_layer);

  //Creating the C2_S6 percentage text Layer
  s_C2_S6_percentage_layer = text_layer_create(GRect(2*(bounds.size.w/4), 4*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  init_label(s_C2_S6_percentage_layer, GColorClear, GColorBlack, GTextAlignmentLeft, FONT_KEY_GOTHIC_14_BOLD, NULL, window_layer);

  //Creating the C1_S5 percentage text Layer
  s_C1_S5_percentage_layer = text_layer_create(GRect(3*(bounds.size.w/4), 3*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  init_label(s_C1_S5_percentage_layer, GColorClear, GColorBlack, GTextAlignmentLeft, FONT_KEY_GOTHIC_14_BOLD, NULL, window_layer);

  //Creating the C2_S5 percentage text Layer
  s_C2_S5_percentage_layer = text_layer_create(GRect(3*(bounds.size.w/4), 4*(bounds.size.h/10) , bounds.size.w, bounds.size.h));
  init_label(s_C2_S5_percentage_layer, GColorClear, GColorBlack, GTextAlignmentLeft, FONT_KEY_GOTHIC_14_BOLD, NULL, window_layer);

  /*
    DOWN PART OF THE SCREEN
  */

  //Creating the C1 down text Layer
  s_C1_down_layer = text_layer_create(GRect(PBL_IF_ROUND_ELSE((bounds.size.w/10),0), PBL_IF_ROUND_ELSE(6*(bounds.size.h/10),8*(bounds.size.h/10)) , bounds.size.w, bounds.size.h));
  init_label(s_C1_down_layer, GColorClear, GColorBlack, GTextAlignmentLeft, FONT_KEY_GOTHIC_18_BOLD, "C1", window_layer);

  //Creating the C2 down text Layer
  s_C2_down_layer = text_layer_create(GRect(PBL_IF_ROUND_ELSE((bounds.size.w/10),0), PBL_IF_ROUND_ELSE(7*(bounds.size.h/10),9*(bounds.size.h/10)) , bounds.size.w, bounds.size.h));
  init_label(s_C2_down_layer, GColorClear, GColorBlack, GTextAlignmentLeft, FONT_KEY_GOTHIC_18_BOLD, "C2", window_layer);

  //Creating the S4 text Layer
  s_S4_layer = text_layer_create(GRect(bounds.size.w/4, PBL_IF_ROUND_ELSE(5*(bounds.size.h/10),6*(bounds.size.h/10)), bounds.size.w, bounds.size.h));
  init_label(s_S4_layer, GColorClear, GColorBlack, GTextAlignmentLeft, FONT_KEY_GOTHIC_18_BOLD, NULL, window_layer);

  //Creating the S3 text Layer
  s_S3_layer = text_layer_create(GRect(2*(bounds.size.w/4), PBL_IF_ROUND_ELSE(5*(bounds.size.h/10),6*(bounds.size.h/10)) , bounds.size.w, bounds.size.h));
  init_label(s_S3_layer, GColorClear, GColorBlack, GTextAlignmentLeft, FONT_KEY_GOTHIC_18_BOLD, NULL, window_layer);

  //Creating the S2 text Layer
  s_S2_layer = text_layer_create(GRect(3*(bounds.size.w/4), PBL_IF_ROUND_ELSE(5*(bounds.size.h/10),6*(bounds.size.h/10)) , bounds.size.w, bounds.size.h));
  init_label(s_S2_layer, GColorClear, GColorBlack, GTextAlignmentLeft, FONT_KEY_GOTHIC_18_BOLD, NULL, window_layer);

  //Creating the C1_S4 percentage text Layer
  s_C1_S4_percentage_layer = text_layer_create(GRect(bounds.size.w/4, PBL_IF_ROUND_ELSE(6*(bounds.size.h/10),8*(bounds.size.h/10)) , bounds.size.w, bounds.size.h));
  init_label(s_C1_S4_percentage_layer, GColorClear, GColorBlack, GTextAlignmentLeft, FONT_KEY_GOTHIC_14_BOLD, NULL, window_layer);

  //Creating the C2_S4 percentage text Layer
  s_C2_S4_percentage_layer = text_layer_create(GRect(bounds.size.w/4, PBL_IF_ROUND_ELSE(7*(bounds.size.h/10),9*(bounds.size.h/10)) , bounds.size.w, bounds.size.h));
  init_label(s_C2_S4_percentage_layer, GColorClear, GColorBlack, GTextAlignmentLeft, FONT_KEY_GOTHIC_14_BOLD, NULL, window_layer);

  //Creating the C1_S3 percentage text Layer
  s_C1_S3_percentage_layer = text_layer_create( GRect(2*(bounds.size.w/4), PBL_IF_ROUND_ELSE(6*(bounds.size.h/10),8*(bounds.size.h/10)) , bounds.size.w, bounds.size.h));
  init_label(s_C1_S3_percentage_layer, GColorClear, GColorBlack, GTextAlignmentLeft, FONT_KEY_GOTHIC_14_BOLD, NULL, window_layer);

  //Creating the C2_S3 percentage text Layer
  s_C2_S3_percentage_layer = text_layer_create( GRect(2*(bounds.size.w/4), PBL_IF_ROUND_ELSE(7*(bounds.size.h/10),9*(bounds.size.h/10)) , bounds.size.w, bounds.size.h));
  init_label(s_C2_S3_percentage_layer, GColorClear, GColorBlack, GTextAlignmentLeft, FONT_KEY_GOTHIC_14_BOLD, NULL, window_layer);

  //Creating the C1_S2 percentage text Layer
  s_C1_S2_percentage_layer = text_layer_create(GRect(3*(bounds.size.w/4),PBL_IF_ROUND_ELSE(6*(bounds.size.h/10),8*(bounds.size.h/10)) , bounds.size.w, bounds.size.h));
  init_label(s_C1_S2_percentage_layer, GColorClear, GColorBlack, GTextAlignmentLeft, FONT_KEY_GOTHIC_14_BOLD, NULL, window_layer);

  //Creating the C2_S2 percentage text Layer
  s_C2_S2_percentage_layer = text_layer_create(GRect(3*(bounds.size.w/4), PBL_IF_ROUND_ELSE(7*(bounds.size.h/10),9*(bounds.size.h/10)) , bounds.size.w, bounds.size.h));
  init_label(s_C2_S2_percentage_layer, GColorClear, GColorBlack, GTextAlignmentLeft, FONT_KEY_GOTHIC_14_BOLD, NULL, window_layer);

  //Displaying all label text
  display_stat_by_complex();

}

static void stat_by_complex_window_unload(Window *window){

  text_layer_destroy(s_set_label_layer);

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

  free(s_set_label_text_buffer);

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
  
  window_destroy(g_stat_by_complex_window);

}

void initialize_stat_by_complex_window(int setNumberIn,int previousWindow){
  //Recording what the previous window was so that we can push that window back
  //on top of the stack when we are done checking the stats
  previousWindowIsGameWindow = previousWindow;

  //Recording the set number of the stats we want
  setNumber = setNumberIn;
  //Creating window
  g_stat_by_complex_window = window_create();

  //Setting the click handler
  window_set_click_config_provider(g_stat_by_complex_window, stat_by_complex_window_click_config_provider);

  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(g_stat_by_complex_window, (WindowHandlers) {
    .load = stat_by_complex_window_load,
    .unload = stat_by_complex_window_unload
  });
  
  window_stack_push(g_stat_by_complex_window, true);

}
