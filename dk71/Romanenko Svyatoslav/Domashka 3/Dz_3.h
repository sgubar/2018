#ifndef Dz_3_h
#define Dz_3_h

#include <stdio.h>

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

void writeSquareToJSON(FILE *aFile, Square *aSquare);
void writePointToJSON(FILE *aFile, Point *aPoint);

void input_coordinates (int *X, int *Y);
void input_coordinates_C (int *X, int *Y, int A_x, int A_y, int B_x, int B_y);

#endif
