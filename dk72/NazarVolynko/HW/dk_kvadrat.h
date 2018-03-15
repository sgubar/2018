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
void printKvadrat(Kvadrat *aKvadrat);

#endif // DK_KVADRAT_H_INCLUDED
