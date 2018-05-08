#ifndef DZ_5_SEARCH_H_INCLUDED
#define DZ_5_SEARCH_H_INCLUDED

#include <stdio.h>
#include "Dz_5.h"

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
