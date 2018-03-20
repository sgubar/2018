#include "dz2.h"
#include <stdlib.h>
#include <stdio.h>

Point *copyPointWithPoint(Point *aPoint);

Rectangle *createRectangle(Point *A, Point *B, Point *C, Point *D)
{
	Rectangle *theResult = NULL;
	
		theResult = (Rectangle *)malloc(sizeof(Rectangle));
		if (NULL != theResult)
		{
			theResult->A = copyPointWithPoint(A);
			theResult->B = copyPointWithPoint(B);
			theResult->C = copyPointWithPoint(C);
			theResult->D = copyPointWithPoint(D);
		}	
	return theResult;
}

void destroyRectangle(Rectangle *aRectangle)
{
	if (NULL != aRectangle)
	{
		free(aRectangle->A);
		free(aRectangle->B);
		free(aRectangle->C);
		free(aRectangle->D);
		
	
		free(aRectangle);
	}
}

int squareRectangle(Rectangle *aRectangle)
{
	
	int theResult = 0;
	if (NULL != aRectangle)
	{
		int a, b;
		int dX = (aRectangle->B->x - aRectangle->A->x);
		int dY = (aRectangle->B->y - aRectangle->A->y);
		a = sqrt(dX*dX + dY*dY);
		int dzX = (aRectangle->C->x - aRectangle->B->x);
		int dzY = (aRectangle->C->y - aRectangle->B->y);
		b = sqrt(dzX*dzX + dzY*dzY);
		 theResult=a*b;
	}
	return theResult;
	
}

void printRectangle(Rectangle *aRectangle)
{
	if (NULL != aRectangle)
	{
		printf ("[Rectangle]. A(%d,%d) - B(%d,%d) - C(%d,%d) - D(%d,%d)\n",
					aRectangle->A->x,aRectangle->A->y,
					aRectangle->B->x, aRectangle->B->y,
					aRectangle->C->x,aRectangle->C->y,
					aRectangle->D->x, aRectangle->D->y);
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

