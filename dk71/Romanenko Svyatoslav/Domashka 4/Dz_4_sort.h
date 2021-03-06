#ifndef DZ_4_SORT_H_INCLUDED
#define DZ_4_SORT_H_INCLUDED

#include <stdio.h>
#include "Dz_4.h"

typedef struct tagSquareArray
{
	int number;
	int count;

	float *IndSquare;

	Square **Squares;
}SquareArray;

SquareArray *createArray(int aNumber);
void freeArray(SquareArray *anArray);

int addElement(SquareArray *anArray, Square *aSquare, float Ind);
void writeArrayToJSON(FILE *aFile, SquareArray *anArray);

void sort_vybora(SquareArray *anArray);
void printArray(SquareArray *anArray);

#endif
