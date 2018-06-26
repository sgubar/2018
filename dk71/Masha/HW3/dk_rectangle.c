#include<stdlib.h>
#include <math.h>
#include "dk_rectangle.h"

Coordinate *copyCoordinateWithCoordinate(Coordinate *Coordin);

Point *createRectangle(Coordinate *A, Coordinate *B, Coordinate *C,Coordinate *D)
{
	Point *theResult = NULL;

	if (NULL != A && NULL != B && NULL !=C && NULL !=D)
	{
		theResult = (Point *)malloc(sizeof(Point));
		if (NULL != theResult)
		{
			theResult->A = copyCoordinateWithCoordinate(A);
			theResult->B = copyCoordinateWithCoordinate(B);
			theResult->C = copyCoordinateWithCoordinate(C);
			theResult->D = copyCoordinateWithCoordinate(D);
		}
	}
	return theResult;
}
void destroyRectangle(Point *aLine)
{
	if (NULL != aLine)
	{
		free(aLine->A);
		free(aLine->B);
		free(aLine->C);
		free(aLine->D);

		free(aLine);
	}
}
float lenghLine(Coordinate *A,Coordinate *B)
{
	float theResult = 0.0;

	if (NULL != A&&NULL !=B)
	{
		float dX =abs(A->x - B->x);
		float dY =abs(A->y - B->y);
		theResult = sqrt(dX*dX + dY*dY);
	}

	return theResult;
}
void printRectangle(Point *aPoint)
{
	if (NULL != aPoint)
	{
		printf ("[Rectangle]. A(%d,%d) - B(%d,%d)- C(%d,%d)- D(%d,%d)\n\n",
					aPoint->A->x, aPoint->A->y,
					aPoint->B->x, aPoint->B->y,
					aPoint->C->x, aPoint->C->y,
					aPoint->D->x, aPoint->D->y);
	}
}
Coordinate *copyCoordinateWithCoordinate(Coordinate *Coordin)
{
	Coordinate *theResult = (Coordinate *)malloc(sizeof(Coordinate));
	if (NULL != theResult)
	{
		theResult->x = Coordin->x;
		theResult->y = Coordin->y;
	}

	return theResult;
}
int checktherectangle(Coordinate *A, Coordinate *B, Coordinate *C,Coordinate *D)
{
     int correct =0;
if (NULL != A&&NULL!=B&&NULL!=C&&NULL!=D)
	{
	    int firstside= lenghLine(A,B);
	    int secondside = lenghLine(B,C);
	    int thirdside = lenghLine(C,D);
	    int fourthside= lenghLine(D,A);
int DiagonalAC=lenghLine(A,C);
int DiagonalDB=lenghLine(D,B);
int theorydiagonalAC= sqrt(secondside*secondside+firstside*firstside);
int theorydiagonalBD = sqrt(thirdside*thirdside+fourthside*fourthside);
if((DiagonalAC==theorydiagonalAC)&&(DiagonalDB==theorydiagonalBD))
{
     correct=1;
}
else
    correct =0;
}
return correct;
}
float Ploscha(Point *Rectan)
{
     float S=lenghLine(Rectan->A,Rectan->B)*lenghLine(Rectan->B,Rectan->C);
   return S;
}

void writeCoordinateToJSON(FILE *aFile, Coordinate *aCoordinate)
{
	if (NULL == aCoordinate || NULL == aFile)
	{
		return ;
	}

	fprintf(aFile, "{\"x\" : %d, \"y\" : %d}", aCoordinate->x, aCoordinate->y);
}

void writeRectangleToJSON(FILE *aFile, Point *aRectangle)
{
	if (NULL == aRectangle || NULL == aFile)
	{
		return ;
	}

	fprintf(aFile, "{\n\"A\" : ");
	writeCoordinateToJSON(aFile, aRectangle->A);
	fprintf(aFile, ", \n\"B\" : ");
	writeCoordinateToJSON(aFile, aRectangle->B);
	fprintf(aFile, "\n}");
	fprintf(aFile, ", \n\"C\" : ");
	writeCoordinateToJSON(aFile, aRectangle->C);
	fprintf(aFile, ", \n\"D\" : ");
	writeCoordinateToJSON(aFile, aRectangle->D);
	fprintf(aFile, "\n}");
}
