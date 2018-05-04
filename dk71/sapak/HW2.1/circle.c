#include "circle.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Point *copyPointWithPoint(Point *aPoint);

Circle *createCircle(Point *Center,Point *Rad)
{
	Circle *theResult = NULL;
	
	if (NULL != Center && NULL != Rad)
	{
		theResult = (Circle*)malloc(sizeof(Circle));
		if (NULL != theResult)
		{
			theResult->Center = copyPointWithPoint(Center);
			theResult->Rad = copyPointWithPoint(Rad);
		}
	}
	
	return theResult;
}

void FreeCircle(Circle *aCircle)
{
	if (NULL != aCircle)
	{
		free(aCircle->Center);
		free(aCircle->Rad);
		free(aCircle);
	}
}

float SquareCircle(Circle *aCircle)
{
	float theResult = 0.0;
	float R = sqrt(pow((aCircle->Rad->x - aCircle->Center->x), 2) + pow((aCircle->Rad->y - aCircle->Center->y), 2));
	theResult = 3.14*R*R;
	
	return theResult;
}

void printCircle(Circle *aCircle)
{

	if (NULL != aCircle)
	{
		printf ("[Circle].\n Center(%i,%i),\n Radius = (%i,%i)\n", aCircle->Center->x, aCircle->Center->y, aCircle->Rad->x,aCircle->Rad->y);
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



