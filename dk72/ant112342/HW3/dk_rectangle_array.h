#ifndef dk_rectangle_array_h
#define dk_rectangle_array_h

#include <stdio.h>
#include "dk_rectangle.h"
typedef struct tagRectangleArray
{
	int number;
	int count;

	Point **rectangles;
}RectangleArray;

RectangleArray *createArray(int aNumber);
void freeArray(RectangleArray *anArray);
int addElement(RectangleArray *anArray, Point *aLine);
void writeArrayToJSON(FILE *aFile, RectangleArray *anArray);
#endif

