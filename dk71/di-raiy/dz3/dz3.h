#ifndef dz3_H
#define dz3_H

#include <stdio.h>
#include "dz2.h"

typedef struct tagTrapezeArray
{
	int number;
	int count;

	Trapeze **trapezes;
}TrapezeArray;

TrapezeArray *createArray(int aNumber);
void freeArray(TrapezeArray *anArray);

int addElement(TrapezeArray *anArray, Trapeze *aTrapeze);
void writeArrayToJSON(FILE *aFile, TrapezeArray *anArray);
void writeTrapezeToJSON(FILE *aFile, Trapeze *aTrapeze);
void writePointToJSON(FILE *aFile, Point *aPoint);

#endif
