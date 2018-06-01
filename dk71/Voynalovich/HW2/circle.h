#ifndef _CIRCLE_H
#define _CIRCLE_H

#include <stdio.h>
#include <math.h>

//Point description
typedef struct tagPoint
{
	int x;
	int y;
}Point;

//Circle description
typedef struct tagCircle
{
     Point *A;
}Circle;

// Init interface
Circle *createCircle(Point *A);
void FreeCircle(Circle *aCircle);
float SquareCircle(Circle *aCircle);
void printCircle(Circle *aCircle);
Point *copyPointWithPoint(Point *aPoint);

#endif
