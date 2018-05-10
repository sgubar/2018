#ifndef dz2_h
#define dz2_h

#include <stdlib.h>
#include <stdio.h>

// Point description
typedef struct tagPoint
{
	int x;
	int y;
}Point;

//Rectangle description
typedef struct tagRactangle
{
	Point *A;
	Point *B;
	Point *C;
	Point *D;
}Ractangle;

// Init interface
Ractangle *createRactangle(Point *A, Point *B, Point *C, Point *D);
void destroyRactangle(Ractangle *aRactangle);

int squareRactangle(Ractangle *aRactangle);
void printRactangle(Ractangle *aRactangle);

#endif /* dz2_h */
