#include "circle.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Point *copyPointWithPoint(Point *aPoint);

Circle *createCircle(Point *A)
{
	Circle *theResult = NULL;
	
	if (NULL != A)
	{
		theResult = (Circle*)malloc(sizeof(Circle));
		if (NULL != theResult)
		{
			theResult->A = copyPointWithPoint(A);
		}
	}
	
	return theResult;
}

void FreeCircle(Circle *aCircle)
{
	if (NULL != aCircle)
	{
		free(aCircle->A);
		free(aCircle);
	}
}

float SquareCircle(Circle *aCircle)
{
	float theResult = 0.0;
	float R = sqrt(pow(aCircle->A->x, 2) + pow(aCircle->A->y, 2));
	theResult = 3.14*R*R;
	
	return theResult;
}

void printCircle(Circle *aCircle)
{
	float R = sqrt(pow(aCircle->A->x, 2) + pow(aCircle->A->y, 2));
	if (NULL != aCircle)
	{
		printf ("[Circle].\n Center(%d,%d),\n Radius = %f\n", aCircle->A->x, aCircle->A->y, R);
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

