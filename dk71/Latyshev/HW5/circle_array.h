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
void addElement(CircleArray *InstantArray, Circle *aCircle,float area);
void writeArrayToJSON(FILE *aFile, CircleArray *InstantArray);
void quick_sort(CircleArray *InstantArray, int first, int last);
int line_search(CircleArray *InstantArray, float key);






#endif
