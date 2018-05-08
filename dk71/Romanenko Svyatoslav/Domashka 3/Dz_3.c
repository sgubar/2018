#include "Dz_3.h"

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

void input_coordinates (int *X, int *Y)
{
    printf("x=");
    scanf("%d",X);
    printf("y=");
    scanf("%d",Y);
}

void input_coordinates_C (int *X, int *Y, int A_x, int A_y, int B_x, int B_y)
{
    int I,J;
    do
    {
        printf("x=");
        scanf("%d",&I);
        printf("y=");
        scanf("%d",&J);
        if(pow(A_x-B_x,2)+pow(A_y-B_y,2)+pow(I-B_x,2)+pow(J-B_y,2)!=pow(A_x-I,2)+pow(A_y-J,2)||
           pow(A_x-B_x,2)+pow(J-B_y,2)!=pow(I-B_x,2)+pow(J-B_y,2))
        {
            printf("ERROR! Invalid coordinates of point C.\n Enter a different value!");
        }
        printf("\n");
    }while(pow(A_x-B_x,2)+pow(A_y-B_y,2)+pow(I-B_x,2)+pow(J-B_y,2)!=pow(A_x-I,2)+pow(A_y-J,2)||
           pow(A_x-B_x,2)+pow(A_y-B_y,2)!=pow(I-B_x,2)+pow(J-B_y,2));

           *X=I;
           *Y=J;
}

void writePointToJSON(FILE *aFile, Point *aPoint)
{
	if (NULL == aPoint || NULL == aFile)
	{
		return ;
	}

	fprintf(aFile, "(x = %d, y = %d)", aPoint->x, aPoint->y);
}

void writeSquareToJSON(FILE *aFile, Square *aSquare)
{
	if (NULL == aSquare || NULL == aFile)
	{
		return ;
	}

	fprintf(aFile, "{\n A : ");
	writePointToJSON(aFile, aSquare->A);
	fprintf(aFile, "\n B : ");
	writePointToJSON(aFile, aSquare->B);
	fprintf(aFile, "\n C : ");
	writePointToJSON(aFile, aSquare->C);
	fprintf(aFile, "\n D : ");
	writePointToJSON(aFile, aSquare->D);
	fprintf(aFile, "\n}");
}
