
#ifndef dk_triangle_array
#define dk_triangle_array

#include <stdio.h>
#include "dk_triangle2.h"

typedef struct tagtriangleArray
{
	int number;
	int count;

	triangle **triangles;
}triangleArray;


triangleArray *createArray(int aNumber);
void freeArray(triangleArray *anArray);
int addElement(triangleArray *anArray, triangle *atriangle);
void writeArrayToJSON(FILE *aFile, triangleArray *anArray);
#endif

