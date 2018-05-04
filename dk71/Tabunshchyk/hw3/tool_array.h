#ifndef tool_array
#define tool_array

#include <stdio.h>
#include "tool.h"

typedef struct tagtriangleArray
{
	int number;
	int count;
	triangle **triangles;
	
} triangleArray;


triangleArray *createArray(int aNumber);

void freeArray(triangleArray *anArray);

int addElement(triangleArray *anArray, triangle *atriangle);

void array_to_json(FILE *file, triangleArray *anArray);




#endif

