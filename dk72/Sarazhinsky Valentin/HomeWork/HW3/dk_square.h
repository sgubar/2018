#ifndef dk_line_h
#define dk_line_h

#include <stdio.h>

// Point description
typedef struct tagPoint
{
	int x;
	int y;
}Point;



// Square description
typedef struct tagSquare
{
	Point *A;
	Point *B;
	Point *C;
	Point *D;
}Square;

// Init interface

Square *createSquare(Point *A, Point *B, Point *C, Point *D;);
void destroySquare(Square *aSquare);

float areaSquare(Square *aSquare);
void printSquare(Square *aSquare);

void writeSquareToJSON(FILE *aFile, Square *aSquare);

#endif
