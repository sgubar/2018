//
//  dk_ellipse.c
//  dz3
//
//  Created by Alexander Kovalenko on 4/04/18.
//  Copyright © 2018 Alexander Kovalenko. All rights reserved.
//

#include "dk_ellipse.h"
#include <stdlib.h>
#include <math.h>

Point *copyPointWithPoint(Point *aPoint);

Ellipse *createEllipse(Point *Centre, int *a, int *b)
{
	Ellipse *theResult = NULL;
	
	if (NULL != Centre && NULL != a && NULL !=b)
	{
		theResult = (Ellipse *)malloc(sizeof(Ellipse));
		if (NULL != theResult)
		{
			theResult->O = copyPointWithPoint(Centre);
			theResult->a = *a;
			theResult->b = *b;
		}
	}
	
	return theResult;
}

void destroyEllipse(Ellipse *aEllipse)
{
	if (NULL != aEllipse)
	{
		free(aEllipse->O);
		free(aEllipse);
	}
}

float SquareEllipse(Ellipse *aEllipse)
{
    float Pi = 3.14159265;
    float theResult = 0.0;
	
	if (NULL != aEllipse)
	{
		theResult = Pi * aEllipse->a * aEllipse->b;
	}
	
	return theResult;
}

void printEllipse(Ellipse *aEllipse)
{
	if (NULL != aEllipse)
	{
		printf ("[Ellipse]. Center(%d,%d), SemiMajorAxis = %d ,SemiMinorAxis = %d)\n",
					aEllipse->O->x, aEllipse->O->y,
					aEllipse->a, aEllipse->b);
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

void writePointToJSON(FILE *aFile, Point *aPoint)
{
	if (NULL == aPoint || NULL == aFile)
	{
		return ;
	}
	
	fprintf(aFile, "{\"x\" : %d, \"y\" : %d}", aPoint->x, aPoint->y);
}

void writeEllipseToJSON(FILE *aFile, Ellipse *aEllipse)
{
	if (NULL == aEllipse || NULL == aFile)
	{
		return ;
	}

	fprintf(aFile, "{\n\"O\" : ");
	writePointToJSON(aFile, aEllipse->O);
	fprintf(aFile, ", \n\"a\" : %d", aEllipse->a);
	fprintf(aFile, ", \n\"b\" : %d", aEllipse->b);
    fprintf(aFile, "\n}");
}

