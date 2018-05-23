#ifndef tool_array
#define tool_array

#include <stdio.h>
#include "tool_array.h"

typedef struct tagtriangle_array
{
	int number;
	int count;
	float *flat;
	
	triangle **triangles;
	
}triangle_array;


triangle_array *createArray(int aNumber);
void free_array(triangle_array *anArray);
int add_element(triangle_array *anArray, triangle *atriangle, float flat);
void write_array_to_JSON(FILE *before, triangle_array *anArray);
void insertion_sort(triangle_array *anArray);
#endif

