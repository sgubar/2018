#ifndef DZ_5_H_INCLUDED
#define DZ_5_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct tagPoint
{
	int x;
	int y;
}Point;

typedef struct tagSquare
{
	Point *A;
	Point *B;
	Point *C;
	Point *D;
}Square;

Square *createSquare(Point *A, Point *B, Point *C, Point *D);
void destroySquare(Square *aSquare);

float areaSquare(Square *aSquare);

void writeSquareToJSON(FILE *aFile, Square *aSquare);
void writePointToJSON(FILE *aFile, Point *aPoint);

void enter_coordinates (int *X, int *Y);


#endif
