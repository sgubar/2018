#include<stdlib.h>
#include <math.h>
#include "dk_rectangle.h"

Point *copyCoordinateWithCoordinate(Point *Coordin);

Rectangle *createRectangle(Rectangle *A, Rectangle *B, Rectangle *C,Rectangle *D)
{
	Rectangle *theResult = NULL;

	if (NULL != A && NULL != B && NULL !=C && NULL !=D)
	{
		theResult = (Rectangle *)malloc(sizeof(Point));
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
void destroyRectangle(Rectangle *aLine)
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
float lenghLine(Point *A,Point *B)
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
void printRectangle(Rectangle *aPoint)
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
Point *copyCoordinateWithCoordinate(Point *Coordin)
{
	Point *theResult = (Point *)malloc(sizeof(Point));
	if (NULL != theResult)
	{
		theResult->x = Coordin->x;
		theResult->y = Coordin->y;
	}

	return theResult;
}
int checktherectangle(Point *A, Point *B, Point *C,Point *D)
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
float Ploscha(Rectangle *Rectan)
{
     float S=lenghLine(Rectan->A,Rectan->B)*lenghLine(Rectan->B,Rectan->C);
   return S;
}

void writeCoordinateToJSON(FILE *aFile, Point *aCoordinate)
{
	if (NULL == aCoordinate || NULL == aFile)
	{
		return ;
	}

	fprintf(aFile, "{\"x\" : %d, \"y\" : %d}", aCoordinate->x, aCoordinate->y);
}

void writeRectangleToJSON(FILE *aFile, Rectangle *aRectangle)
{
	if (NULL == aRectangle || NULL == aFile)
	{
		return ;
	}

	fprintf(aFile, "{\n\"A\" : ");
	writeCoordinateToJSON(aFile, aRectangle->A);
	fprintf(aFile, ", \n\"B\" : ");
	writeCoordinateToJSON(aFile, aRectangle->B);
	fprintf(aFile, ", \n\"C\" : ");
	writeCoordinateToJSON(aFile, aRectangle->C);
	fprintf(aFile, ", \n\"D\" : ");
	writeCoordinateToJSON(aFile, aRectangle->D);
	fprintf(aFile, "\n}");
}
void Enter_the_Coordinate(int *X, int *Y)
{
    printf("x=");
    scanf("%d",X);
    printf("y=");
    scanf("%d",Y);
}
