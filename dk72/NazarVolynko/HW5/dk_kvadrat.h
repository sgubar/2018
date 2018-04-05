#ifndef DK_KVADRAT_H_INCLUDED
#define DK_KVADRAT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Point description
typedef struct tagPoint
{
	int x;
	int y;
}Point;

// Kvadrat description
typedef struct tagLine
{
	Point *A;
	Point *B;
	Point *C;
	Point *D;
}Kvadrat;

// Init interface
Kvadrat *createKvadrat(Point *A, Point *B, Point *C, Point *D);
void destroyKvadrat(Kvadrat *aKvadrat);

float ploschaKvadrat(Kvadrat *aKvadrat);

void writeKvadratToJSON(FILE *aFile, Kvadrat *aKvadrat);
void writePointToJSON(FILE *aFile, Point *aPoint);

void VvidKoordynat (int *X, int *Y);
void VvidKoordynaty_C (int *X, int *Y, int A_x, int A_y, int B_x, int B_y);

#endif // DK_KVADRAT_H_INCLUDED
