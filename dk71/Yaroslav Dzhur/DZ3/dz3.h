#ifndef dz3_H
#define dz3_H

#include <stdio.h>
#include "dz2.h"

typedef struct tagTriangleArray
{
	int number;
	int count;

	Triangle **Triangles;
}TriangleArray;

TriangleArray *createArray(int aNumber);
void freeArray(TriangleArray *anArray);

int addElement(TriangleArray *anArray, Triangle *aTriangle);
void writeArrayToJSON(FILE *aFile, TriangleArray *anArray);
void writeTriangleToJSON(FILE *aFile, Triangle *aTriangle);
void writePointToJSON(FILE *aFile, Point *aPoint);

#endif
