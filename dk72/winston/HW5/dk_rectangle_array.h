#ifndef DK_RECTANGLE_ARRAY_H_INCLUDED
#define DK_RECTANGLE_ARRAY_H_INCLUDED

#include "dk_rectangle.h"

typedef struct tagRectangleArray
{
	int number;
	int count;

	Rectangle **Rectangles;

}RectangleArray;


RectangleArray *createArray(int aNumber);
void freeArray(RectangleArray *anArray);


int addElement(RectangleArray *anArray, Rectangle *aRectangle);
void writeArrayToJSON(FILE *aFile, RectangleArray *anArray);

void quickSort( RectangleArray *anArray, int l, int r);
int partition(RectangleArray *anArray, int l, int r);

int binarysearch(int a, RectangleArray *anArray, int n);


#endif // DK_RECTANGLE_ARRAY_H_INCLUDED
