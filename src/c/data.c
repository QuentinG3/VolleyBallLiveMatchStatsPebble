#include <pebble.h>
#include "data.h"
#include "stack.h"


#define NUM_SETTER_POSITION 6
#define NUM_COMPLEX 2
#define NUM_MAX_SET 5


  
int dataVariable[NUM_MAX_SET+1][NUM_SETTER_POSITION][NUM_COMPLEX][2] = {{{{0,0},{0,0}},{{0,0},{0,0}},{{0,0},{0,0}},{{0,0},{0,0}},{{0,0},{0,0}},{{0,0},{0,0}}},
                                                                     {{{0,0},{0,0}},{{0,0},{0,0}},{{0,0},{0,0}},{{0,0},{0,0}},{{0,0},{0,0}},{{0,0},{0,0}}},
                                                                     {{{0,0},{0,0}},{{0,0},{0,0}},{{0,0},{0,0}},{{0,0},{0,0}},{{0,0},{0,0}},{{0,0},{0,0}}},
                                                                     {{{0,0},{0,0}},{{0,0},{0,0}},{{0,0},{0,0}},{{0,0},{0,0}},{{0,0},{0,0}},{{0,0},{0,0}}},
                                                                     {{{0,0},{0,0}},{{0,0},{0,0}},{{0,0},{0,0}},{{0,0},{0,0}},{{0,0},{0,0}},{{0,0},{0,0}}},
                                                                      {{{0,0},{0,0}},{{0,0},{0,0}},{{0,0},{0,0}},{{0,0},{0,0}},{{0,0},{0,0}},{{0,0},{0,0}}}};


int  currentSetIndex = 0;
char*  serveNames[NUM_COMPLEX] = {"Opponent","Team"};
char*  complexNames[NUM_COMPLEX] = {"C1","C2"};
int  currentComplexIndex = 0;
char*  setterPositionNames[NUM_SETTER_POSITION] = {"Setter 1","Setter 2","Setter 3","Setter 4","Setter 5","Setter 6"};
int currentSetterPositionIndex = 0;

int setWon[NUM_MAX_SET] = {-1,-1,-1,-1,-1};

stackT historicStack[NUM_MAX_SET];
void initializeHistoricStack(){
  for(int i = 0;i<NUM_MAX_SET;i++){
    StackInit(&historicStack[i], 500);
  }
  
}
void deinitializeHistoricStack(){
  for(int i = 0;i<NUM_MAX_SET;i++){
    StackDestroy(&historicStack[i]);
  }
}
void reinitializeData(){
  for(int i = 0;i<6;i++){
    for(int j = 0;j<6;j++){
      for(int k = 0;k<2;k++){
        for(int l = 0;l<2;l++){
          dataVariable[i][j][k][l] = 0;
        }
      }
    }
  }
  
  currentSetIndex = 0;
  currentComplexIndex = 0;
  currentSetterPositionIndex = 0;
  for(int i = 0; i < 4;i++){
    setWon[i] = -1;
  }
  //Reset the historic
  deinitializeHistoricStack();
  initializeHistoricStack();
  
}

int setIsFinished(int setIndex){
  int homeScore = computeHomeScore(setIndex);
  int awayScore = computeAwayScore(setIndex);
  //If we are in the tie break score goes to 15
  if(setIndex == 4){
    if((homeScore >= 15 || awayScore >=15) && abs(homeScore-awayScore) > 1){
      return 1;
    }
    else{
      return 0;
    }
  }
  //Else we are in a normal set and score goes to 25
  else{
    if((homeScore >= 25 || awayScore >=25) && abs(homeScore-awayScore) > 1){
      return 1;
    }
    else{
      return 0;
    }
  }
}
int computeHomeScore(int setIndex){
    int sum = 0;
  //Computing the home score
  for(int i = 0;i < NUM_SETTER_POSITION;i++){
    for(int j = 0;j < NUM_COMPLEX;j++){
      sum += dataVariable[setIndex][i][j][0];
    }
  }
  return sum;
}

int computeAwayScore(int setIndex){
    int sum = 0;
  //Computing the home score
  for(int i = 0;i < NUM_SETTER_POSITION;i++){
    for(int j = 0;j < NUM_COMPLEX;j++){
      sum += dataVariable[setIndex][i][j][1];
    }
  }
  return sum;
}

int next_setter_position(){
  currentSetterPositionIndex--;
  if(currentSetterPositionIndex < 0){
    currentSetterPositionIndex = NUM_SETTER_POSITION-1;
  }
  return currentSetterPositionIndex;
}

int next_complex(){
  currentComplexIndex--;
  if(currentComplexIndex < 0){
    currentComplexIndex = NUM_COMPLEX-1;
  }
  return currentComplexIndex;
}

int gotoNextSet(){
  int homeScore = computeHomeScore(currentSetIndex);
  int awayScore = computeAwayScore(currentSetIndex);
  if(homeScore > awayScore){
    setWon[currentSetIndex] = 1;
  }
  else{
    setWon[currentSetIndex] = 0;
  }
  
  currentSetIndex++;
  currentSetterPositionIndex = 0;
  currentComplexIndex= 0;
  
  return currentSetIndex;
}

void undoLastAction(){
  if(!StackIsEmpty(&historicStack[currentSetIndex])){
      //Getting the historic stack element and restoring variables to old values
      stackElementT elem = StackPop(&historicStack[currentSetIndex]);
      currentSetterPositionIndex = elem.setterPosition;
      currentComplexIndex = elem.complex;
      dataVariable[currentSetIndex][currentSetterPositionIndex][currentComplexIndex][elem.win]--;
      dataVariable[5][currentSetterPositionIndex][currentComplexIndex][elem.win]--;
  }
}

int matchOver(){
  int numberWon = 0;
  int numberLost = 0;
  
  for(int i = 0; i<NUM_MAX_SET;i++){
    if(setWon[i] == 1){
      numberWon++;
    }
    else if(setWon[i] == 0){
      numberLost++;
    }
  }
  
  if(numberWon >=3 || numberLost >= 3){
    return 1;
  }
  else{
    return 0;
  }
}

