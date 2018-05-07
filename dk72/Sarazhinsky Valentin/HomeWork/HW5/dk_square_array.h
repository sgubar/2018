#ifndef DK_SQUARE_ARRAY_H_INCLUDED
#define DK_SQUARE_ARRAY_H_INCLUDED

#include <stdio.h>
#include "dk_square.h"

typedef struct tagSquareArray
{
	int number;
	int count;

	float *areaSquare;

	Square **Squares;
}SquareArray;

SquareArray *createArray(int aNumber);
void freeArray(SquareArray *anArray);

int addElement(SquareArray *anArray, Square *aSquare, float area);
void writeArrayToJSON(FILE *aFile, SquareArray *anArray);

void shellSort(SquareArray *anArray);
int linear_search(SquareArray *anArray, float key);
void printArray(SquareArray *anArray);

#endif
