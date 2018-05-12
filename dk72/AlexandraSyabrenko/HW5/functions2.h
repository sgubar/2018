#ifndef functions2_h
#define functions2_h

#include "functions.h"
#include <stdio.h>

typedef struct tagArrayCircles
{
    int number;
    int count;
    
    Circle **circles;
} ArrayCircles;

ArrayCircles *createArray(int aNumber);

void freeArray(ArrayCircles *anArray);

int addElement(ArrayCircles *anArray, Circle *aCircle);

int addElementByIndex(ArrayCircles *anArray, Circle *aCircle, int index);

void writeArrayToJSON(FILE *aFile, ArrayCircles *anArray);

#endif /* functions2_h */
