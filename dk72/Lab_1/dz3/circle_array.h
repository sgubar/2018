#ifndef circle_array
#define circle_array
#include <stdio.h>
#include "circle.h"

typedef struct tagCircleArray
{
	int number;
	int count;
	Circle **Circles;
} CircleArray;

CircleArray *CreateArray(int aNumber);
void freeArray(CircleArray *InstantArray);
void addElement(CircleArray *InstantArray, Circle *aCircle);
void writeArrayToJSON(FILE *aFile, CircleArray *InstantArray);

#endif
