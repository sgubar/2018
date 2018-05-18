#include "dz2.h"
#include <stdlib.h>
#include <math.h>

Point *copyPointWithPoint(Point *aPoint);

Line *createLine(Point *A, Point *B)
{
	Line *theResult = NULL;

	if (NULL != A && NULL != B)
	{
		theResult = (Line *)malloc(sizeof(Line));
		if (NULL != theResult)
		{
			theResult->A = copyPointWithPoint(A);
			theResult->B = copyPointWithPoint(B);
		}
	}

	return theResult;
}

Triangle *createTriangle(Point *A, Point *B, Point *C)
{
	Triangle *theResult = NULL;

	if (NULL != A && NULL != B && NULL != C)
	{
		theResult = (Triangle *)malloc(sizeof(Triangle));
		if (NULL != theResult)
		{
			theResult->A = copyPointWithPoint(A);
			theResult->B = copyPointWithPoint(B);
			theResult->C = copyPointWithPoint(C);
		}
	}

	return theResult;
}

void destroyLine(Line *aLine)
{
	if (NULL != aLine)
	{
		free(aLine->A);
		free(aLine->B);

		free(aLine);
	}
}

void destroyTriangle(Triangle *aTriangle)
{
	if (NULL != aTriangle)
	{
		free(aTriangle->A);
		free(aTriangle->B);
		free(aTriangle->C);


		free(aTriangle);
	}
}

float areaTriangle(Triangle *aTriangle)
{
	if(NULL != aTriangle)
	{
		float area, k1, k2;
		Line *CA;
		CA = createLine(aTriangle->C,aTriangle->A);
		Line *CB;
		CB = createLine(aTriangle->C,aTriangle->B);
		k1 = lenghLine(CA);
		k2 = lenghLine(CB);
		area = k1 * k2 / 2;
		return area;
	}
}


float lenghLine(Line *aLine)
{
	float theResult = 0.0;

	if (NULL != aLine)
	{
		float dX = (aLine->A->x - aLine->B->x);
		float dY = (aLine->A->y - aLine->B->y);
		theResult = sqrt(dX*dX + dY*dY);
	}

	return theResult;
}

void printLine(Line *aLine)
{
	if (NULL != aLine)
	{
		printf ("[Line]. A(%d,%d) - B(%d,%d)\n",
					aLine->A->x, aLine->A->y,
					aLine->B->x, aLine->B->y);
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
