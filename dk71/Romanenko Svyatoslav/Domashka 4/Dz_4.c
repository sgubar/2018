#include "Dz_4.h"

Point *copyPointWithPoint(Point *aPoint);

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

void enter_coordinates (int *X, int *Y)
{
    printf("x=");
    scanf("%d",X);
    printf("y=");
    scanf("%d",Y);
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
	fprintf(aFile, ",\n\"B\" : ");
	writePointToJSON(aFile, aSquare->B);
	fprintf(aFile, ",\n\"C\" : ");
	writePointToJSON(aFile, aSquare->C);
	fprintf(aFile, ",\n\"D\" : ");
	writePointToJSON(aFile, aSquare->D);
	fprintf(aFile, "\n Area : %f \n}",areaSquare(aSquare));
	
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
