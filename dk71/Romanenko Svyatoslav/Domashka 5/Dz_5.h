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

typedef struct tagKvadrat
{
	Point *A;
	Point *B;
	Point *C;
	Point *D;
}Kvadrat;

Kvadrat *createKvadrat(Point *A, Point *B, Point *C, Point *D);
void destroyKvadrat(Kvadrat *aKvadrat);

float IndKvadrat(Kvadrat *aKvadrat);

void writeSquareToJSON(FILE *aFile, Kvadrat *aKvadrat);
void writePointToJSON(FILE *aFile, Point *aPoint);

void enter_coordinates (int *X, int *Y);


#endif
