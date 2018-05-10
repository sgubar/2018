#ifndef func_array.h
#define func_array.h


#include <stdio.h>
#include "func.h"

typedef struct tagTriangleArray
	{
		int number;
		int count;
		float *square;
		
		Triangle **Triangles;
	}TriangleArray;
	
	
	
	
TriangleArray *createArray(int aNumber);
void freeArray(TriangleArray *anArray);


int addElement(TriangleArray *anArray, Triangle *aTriangle, float square);
void writeArrayToJSON(FILE *aFile, TriangleArray *anArray);
void InsertionSort(TriangleArray *anArray);

#endif
