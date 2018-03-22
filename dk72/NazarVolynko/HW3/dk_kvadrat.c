#include "dk_kvadrat.h"

Point *copyPointWithPoint(Point *aPoint);

Kvadrat *createKvadrat(Point *A, Point *B, Point *C, Point *D)
{
    Kvadrat *theResult = NULL;

    if (NULL != A && NULL != B && NULL != C && NULL != D)
    {
        theResult = (Kvadrat *)malloc(sizeof(Kvadrat));

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

void destroyKvadrat(Kvadrat *aKvadrat)
{
	if (NULL != aKvadrat)
	{
		free(aKvadrat->A);
		free(aKvadrat->B);
		free(aKvadrat->C);
		free(aKvadrat->D);

		free(aKvadrat);
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

void VvidKoordynat (int *X, int *Y)
{
    printf("x=");
    scanf("%d",X);
    printf("y=");
    scanf("%d",Y);
}

void VvidKoordynaty_C (int *X, int *Y, int A_x, int A_y, int B_x, int B_y)
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
            printf("Pomylka! Nevirni koordynaty tochky C. Vedit sche raz!");
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

	fprintf(aFile, "{\"x\" : %d, \"y\" : %d}", aPoint->x, aPoint->y);
}

void writeKvadratToJSON(FILE *aFile, Kvadrat *aKvadrat)
{
	if (NULL == aKvadrat || NULL == aFile)
	{
		return ;
	}

	fprintf(aFile, "{\n\"A\" : ");
	writePointToJSON(aFile, aKvadrat->A);
	fprintf(aFile, ",\n\"B\" : ");
	writePointToJSON(aFile, aKvadrat->B);
	fprintf(aFile, ",\n\"C\" : ");
	writePointToJSON(aFile, aKvadrat->C);
	fprintf(aFile, ",\n\"D\" : ");
	writePointToJSON(aFile, aKvadrat->D);
	fprintf(aFile, "\n}");
}
