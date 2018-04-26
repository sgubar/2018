
#ifndef dk_triangle_array
#define dk_triangle_array

#include <stdio.h>
#include "dk_triangle2.h"

typedef struct tagtriangleArray
{
	int number;
	int count;
	float *flat;
	
	triangle **triangles;
}triangleArray;


triangleArray *createArray(int aNumber);
void freeArray(triangleArray *anArray);
int addElement(triangleArray *anArray, triangle *atriangle, float flat);
void writeArrayToJSON(FILE *aFile, triangleArray *anArray);
void quick_sort(triangleArray *anArray, int first, int last);
void swap(int *one, int *two);
int line_search(triangleArray *anArray, float key);


#endif

