#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "dru_dz.h"

typedef struct tagTriangleArray
{
	int number;
	int count;
	struct tagTriangle **aTriangles;
}triangleArray;


triangleArray *createArray(int aNumber);
void freeArray(triangleArray *anArray);
int addElement(triangleArray *anArray, struct tagTriangle *atriangle);
void writeArrayToJSON(FILE *aFile, triangleArray *anArray);
void bubble_sort(triangleArray *anArray);
