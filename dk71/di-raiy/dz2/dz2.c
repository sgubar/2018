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

Trapeze *createTrapeze(Point *A, Point *B, Point *C, Point *D)
{
	Trapeze *theResult = NULL;

	if (NULL != A && NULL != B && NULL != C && NULL != D)
	{
		theResult = (Trapeze *)malloc(sizeof(Trapeze));
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

void destroyLine(Line *aLine)
{
	if (NULL != aLine)
	{
		free(aLine->A);
		free(aLine->B);

		free(aLine);
	}
}

void destroyTrapeze(Trapeze *aTrapeze)
{
	if (NULL != aTrapeze)
	{
		free(aTrapeze->A);
		free(aTrapeze->B);
		free(aTrapeze->C);
		free(aTrapeze->D);

		free(aTrapeze);
	}
}

double areaTrapeze(Trapeze *aTrapeze)
{
	if(NULL != aTrapeze)
	{
		float sin, cos, area;
		float x1, x2, y1, y2, d1, d2;
		x1 = aTrapeze->C->x - aTrapeze->A->x;
		x2 = aTrapeze->D->x - aTrapeze->B->x;
		y1 = aTrapeze->C->y - aTrapeze->A->y;
		y2 = aTrapeze->D->y - aTrapeze->B->y;
		Line *CA;
		CA = createLine(aTrapeze->C,aTrapeze->A);
		Line *DB;
		DB = createLine(aTrapeze->D,aTrapeze->B);
		d1 =lenghLine(CA);
		d2 = lenghLine(DB)/2;
		cos = (x1 * x2 - y1 * y2) / (d1 * d2);
		sin = sqrt(1 - cos * cos);
		area =  d1 * d2 * sin;
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
					aLine->A->x,aLine->A->y,
					aLine->B->x, aLine->B->y);
	}
}

void printTrapeze(Trapeze *aTrapeze)
{
	if (NULL != aTrapeze)
	{
		printf ("[Trapeze]. A(%d,%d) - B(%d,%d) - C(%d,%d) - D(%d,%d)\n",
					aTrapeze->A->x,aTrapeze->A->y,
					aTrapeze->B->x, aTrapeze->B->y,
					aTrapeze->C->x, aTrapeze->C->y,
					aTrapeze->D->x, aTrapeze->D->y);
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

