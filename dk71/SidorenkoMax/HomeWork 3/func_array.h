#ifndef func_array.h
#define func_array.h


#include <stdio.h>
#include "func.h"

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

#endif
