#ifndef dz2_array_h
#define dz2_array_h

#include <stdlib.h>
#include <stdio.h>
#include "dz2.h"


typedef struct tagRactangleArray
{
	int number;
	int count;

	Ractangle **ractangles;
}RactangleArray;

RactangleArray *createArray(int aNumber);
void freeArray(RactangleArray *anArray);

int addElement(RactangleArray *anArray, Ractangle *aRactangle);
//json format 
void writeArrayToJSON(FILE *aFile, RactangleArray *anArray);
void writePointToJSON(FILE *aFile, Point *aPoint);
void writeRactangleToJSON(FILE *aFile, Ractangle *aRactangle);

#endif /* dz2_array_h */
