#include "circle.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Point *copyPointWithPoint(Point *aPoint);

Circle *createCircle(Point *C)
{
	Circle *theResult = NULL;
	
	if (NULL != C)
	{
		theResult = (Circle*)malloc(sizeof(Circle));
		if (NULL != theResult)
		{
			theResult->C = copyPointWithPoint(C);
		}
	}
	
	return theResult;
}

void destroyCircle(Circle *aCircle)
{
	if (NULL != aCircle)
	{
		free(aCircle->C);
		free(aCircle);
	}
}

float SquareCircle(Circle *aCircle)
{
	float theResult = 0.0;
	float R = sqrt(pow(aCircle->C->x, 2) + pow(aCircle->C->y, 2));
	theResult = 3.14*R*R;
	
	return theResult;
}

void printCircle(Circle *aCircle)
{
	float R = sqrt(pow(aCircle->C->x, 2) + pow(aCircle->C->y, 2));
	if (NULL != aCircle)
	{
		printf ("[Circle]. Center(%d,%d), Radius = %f\n", aCircle->C->x, aCircle->C->y, R);
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



