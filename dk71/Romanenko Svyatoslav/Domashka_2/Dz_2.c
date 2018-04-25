#include "Dz_2.h"
Point *copyPointWithPoint(Point *aPoint);

Kvadrat *createKvadrat(Point *A, Point *B, Point *C, Point *D)
{
    Kvadrat *theResult = NULL;

    if (NULL != A && NULL != B && NULL != C && NULL != D)
    {
        theResult = (Kvadrat *)malloc(sizeof(Kvadrat));

        if (NULL != theResult)
        {
            theResult->A = copyPointWithPoint(A);
            theResult->B = copyPointWithPoint(B);
            theResult->C = copyPointWithPoint(C);
            theResult->D = copyPointWithPoint(D);
        }
    }
    return theResult;
}

void destroyKvadrat(Kvadrat *aKvadrat)
{
	if (NULL != aKvadrat)
	{
		free(aKvadrat->A);
		free(aKvadrat->B);
		free(aKvadrat->C);
		free(aKvadrat->D);

		free(aKvadrat);
	}
}

float ploschaKvadrat(Kvadrat *aKvadrat)
{
   float theResult = 0.0;

	if (NULL != aKvadrat)
	{
		float dX = (aKvadrat->A->x - aKvadrat->B->x);
		float dY = (aKvadrat->A->y - aKvadrat->B->y);
		theResult = sqrt(dX*dX + dY*dY);
		theResult=pow(theResult,2);
	}
	return theResult;
}

void printKvadrat(Kvadrat *aKvadrat)
{
	if (NULL != aKvadrat)
	{
		printf ("[Kvadrat]. A(%d,%d) - B(%d,%d)- C(%d,%d)- D(%d,%d)\n\n",
					aKvadrat->A->x, aKvadrat->A->y,
					aKvadrat->B->x, aKvadrat->B->y,
					aKvadrat->C->x, aKvadrat->C->y,
					aKvadrat->D->x, aKvadrat->D->y);
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
