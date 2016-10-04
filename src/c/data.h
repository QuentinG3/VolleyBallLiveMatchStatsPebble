#pragma once
#include "stack.h"

#define NUM_SETTER_POSITION 6
#define NUM_COMPLEX 2
#define NUM_MAX_SET 5

int currentSetterPositionIndex;
char* setterPositionNames[NUM_SETTER_POSITION];

int currentComplexIndex;
char* complexNames[NUM_COMPLEX];
char* serveNames[NUM_COMPLEX];

int currentSetIndex;

int dataVariable[NUM_MAX_SET+1][NUM_SETTER_POSITION][NUM_COMPLEX][2];

int setWon[NUM_MAX_SET];

stackT historicStack[NUM_MAX_SET];
void initializeHistoricStack();
void deinitializeHistoricStack();

int setIsFinished(int setIndex);
int computeHomeScore(int setIndex);
int computeAwayScore(int setIndex);

int next_setter_position();
int next_complex();
int gotoNextSet();
void undoLastAction();
int matchOver();
//void sendStats();