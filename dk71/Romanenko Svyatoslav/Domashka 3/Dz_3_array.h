#ifndef Dz_3_array_h
#define Dz_3_array_h

#include <stdio.h>
#include "Dz_3.h"

typedef struct tagSquareArray
{
	int number;
	int count;

	Square **Squares;
}SquareArray;


SquareArray *createArray(int aNumber);
void freeArray(SquareArray *anArray);

int addElement(SquareArray *anArray, Square *aSquare);
void writeArrayToJSON(FILE *aFile, SquareArray *anArray);

#endif
