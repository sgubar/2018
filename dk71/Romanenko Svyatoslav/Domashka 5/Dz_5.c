#include "Dz_5.h"

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

void enter_coordinates (int *X, int *Y)
{
    printf("x=");
    scanf("%d",X);
    printf("y=");
    scanf("%d",Y);
}

void writePointToJSON(FILE *aFile, Point *aPoint)
{
	if (NULL == aPoint || NULL == aFile)
	{
		return ;
	}

	fprintf(aFile, "{\"x\" : %d, \"y\" : %d}", aPoint->x, aPoint->y);
}

void writeSquareToJSON(FILE *aFile, Kvadrat *aKvadrat)
{
	if (NULL == aKvadrat || NULL == aFile)
	{
		return ;
	}

	fprintf(aFile, "{\n\"A\" : ");
	writePointToJSON(aFile, aKvadrat->A);
	fprintf(aFile, ",\n\"B\" : ");
	writePointToJSON(aFile, aKvadrat->B);
	fprintf(aFile, ",\n\"C\" : ");
	writePointToJSON(aFile, aKvadrat->C);
	fprintf(aFile, ",\n\"D\" : ");
	writePointToJSON(aFile, aKvadrat->D);
	fprintf(aFile, "\n Area : %f \n}",IndKvadrat(aKvadrat));
	
}

float areaSquare(Kvadrat *aKvadrat)
{
   float theResult = 0.0;

	if (NULL != aKvadrat)
	{
		float dX = (aKvadrat->A->x - aKvadrat->B->x);
		float dY = (aKvadrat->A->y - aKvadrat->B->y);
		theResult = sqrt(dX*dX + dY*dY)*sqrt(dX*dX + dY*dY);
	}
	return theResult;
}
