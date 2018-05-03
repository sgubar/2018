#ifndef circle_array
#define circle_array
#include <stdio.h>
#include "circle.h"



typedef struct tagCircleArray
{
	int number;
	int count;
	float *area;
	
	Circle **Circles;
	
} CircleArray;



CircleArray *CreateArray(int aNumber);

void freeArray(CircleArray *InstantArray);

void addElement(CircleArray *InstantArray, Circle *aCircle, float area);

void insertion_sort(CircleArray *InstantArray);

void writeArrayToJSON(FILE *aFile, CircleArray *InstantArray);



#endif
