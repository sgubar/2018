#ifndef dk_rectangle_array_h
#define dk_rectangle_array_h

#include <stdio.h>
#include "dk_rectangle.h"
typedef struct tagRectangleArray
{
	int number;
	int count;

	Point **rectangles;
	float *Ploscha;
}RectangleArray;

RectangleArray *createArray(int aNumber);
void freeArray(RectangleArray *anArray);
int addElement(RectangleArray *anArray, Rectangle *aLine,float Ploscha);
void writeArrayToJSON(FILE *aFile, RectangleArray *anArray);
int linear_search(RectangleArray *anArray, float key);
void shell_sort(RectangleArray *anArray);

#endif
