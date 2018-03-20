#ifndef dz2_h
#define dz2_h

#include <stdio.h>

// Point description
typedef struct tagPoint
{
	int x;
	int y;
}Point;

//Triangle description
typedef struct tagRectangle
{
	Point *A;
	Point *B;
	Point *C;
	Point *D;
}Rectangle;

// Init interface
Rectangle *createRectangle(Point *A, Point *B, Point *C, Point *D);
void destroyRectangle(Rectangle *aRectangle);

int squareRectangle(Rectangle *aRectangle);
void printRectangle(Rectangle *aRectangle);

#endif /* dz2_h */
