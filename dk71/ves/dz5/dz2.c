#include "dz2.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

Point *copyPointWithPoint(Point *aPoint);

Ractangle *createRactangle(Point *A, Point *B, Point *C, Point *D)
{
	Ractangle *theResult = NULL;

	theResult = (Ractangle *)malloc(sizeof(Ractangle));
	if (NULL != theResult)
	{
		theResult->A = copyPointWithPoint(A);
		theResult->B = copyPointWithPoint(B);
		theResult->C = copyPointWithPoint(C);
		theResult->D = copyPointWithPoint(D);
	}
	return theResult;
}

void destroyRactangle(Ractangle *aRactangle)
{
	if (NULL != aRactangle)
	{
		free(aRactangle->A);
		free(aRactangle->B);
		free(aRactangle->C);
		free(aRactangle->D);


		free(aRactangle);
	}
}

int squareRactangle(Ractangle *aRactangle)
{
	int theResult = 0;
	if (NULL != aRactangle)
	{
		int a, b;
		int dX = (aRactangle->B->x - aRactangle->A->x);
		int dY = (aRactangle->B->y - aRactangle->A->y);
		a = sqrt(dX*dX + dY * dY);
		int dzX = (aRactangle->C->x - aRactangle->B->x);
		int dzY = (aRactangle->C->y - aRactangle->B->y);
		b = sqrt(dzX*dzX + dzY * dzY);
		theResult = a * b;
	}
	return theResult;

}

void printRactangle(Ractangle *aRactangle)
{
	if (NULL != aRactangle)
	{
		printf("[Ractangle]. A(%d,%d) - B(%d,%d) - C(%d,%d) - D(%d,%d)\n",
			aRactangle->A->x, aRactangle->A->y,
			aRactangle->B->x, aRactangle->B->y,
			aRactangle->C->x, aRactangle->C->y,
			aRactangle->D->x, aRactangle->D->y);
	}
}

Point *copyPointWithPoint(Point *aPoint)
{
	Point *theResult = (Point *)malloc(sizeof(Point));
	if (NULL != theResult)
	{
		theResult->x = aPoint->x;
		theResult->y = aPoint->y;
	}
	return theResult;
}
