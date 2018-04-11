#include "dk_square.h"
#include <stdlib.h>

Point *copyPointWithPoint(Point *aPoint);
void writePointToJSON(FILE *aFile, Point *aPoint);

Square *createSquare(Point *A, Point *B, Point *C, Point *D)
{
	Square *theResult = NULL;
	
	if (NULL != A && NULL != B && NULL != C && NULL != D)
	{
		theResult = (Square *)malloc(sizeof(Square));
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

void destroySquare(Square *aSquare)
{
	if (NULL != aSquare)
	{
		free(aSquare->A);
		free(aSquare->B);
		free(aSquare->C);
		free(aSquare->D);
	
		free(aSquare);
	}
}

float areaSquare(Square *aSquare)
{
	float theResult = 0.0;
	
	if (NULL != aSquare)
	{
		float dX = (aSquare->A->x - aSquare->B->x);
		float dY = (aSquare->A->y - aSquare->B->y);
		theResult = sqrt(dX*dX + dY*dY)*sqrt(dX*dX + dY*dY);
	}
	
	return theResult;
}

void printSquare(Square *aSquare)
{
	if (NULL != aSquare)
	{
		printf ("[Square]. A(%d,%d) - B(%d,%d)\n ",
					aSquare->A->x,aSquare->A->y,
					aSquare->B->x, aSquare->B->y);
		printf ("         C(%d,%d) - D(%d,%d)\n ",
					aSquare->C->x,aSquare->C->y,
					aSquare->D->x, aSquare->D->y);
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

void writeSquareToJSON(FILE *aFile, Square *aSquare)
{
	if (NULL == aSquare || NULL == aFile)
	{
		return ;
	}

	fprintf(aFile, "{\n\"A\" : ");
	writePointToJSON(aFile, aSquare->A);
	fprintf(aFile, ", \n\"B\" : ");
	writePointToJSON(aFile, aSquare->B);
	fprintf(aFile, ", \n\"C\" : ");
	writePointToJSON(aFile, aSquare->C);
	fprintf(aFile, ", \n\"D\" : ");
	writePointToJSON(aFile, aSquare->D);
	fprintf(aFile, "\n}");
}
