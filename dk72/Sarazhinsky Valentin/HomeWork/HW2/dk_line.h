#ifndef dk_line_h
#define dk_line_h

#include <stdio.h>

// Point description
typedef struct tagPoint
{
	int x;
	int y;
}Point;

// Line description
typedef struct tagLine
{
	Point *A;
	Point *B;
}Line;

// square description
typedef struct tagSquare
{
	Point *A;
	Point *B;
	Point *C;
} Square;

// Init interface
Square *createSquare(Point *A, Point *B, Point *C);
void destroySquare(Square *aSquare);

float areaSquare(Square *aSquare);
void printSquare(Square *aSquare);

#endif
