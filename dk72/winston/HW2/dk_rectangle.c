#include "dk_rectangle.h"

Point *copyPointWithPoint(Point *aPoint);

Rectangle *createRectangle(Point *A, Point *B, Point *C, Point *D)
{
    Rectangle *theResult = NULL;

    if (NULL != A && NULL != B && NULL != C && NULL != D)
    {
        theResult = (Rectangle *)malloc(sizeof(Rectangle));

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

float areaRectangle(Rectangle *aRectangle)
{
   float theResult = 0.0, theResult_ =0.0;

	if (NULL != aRectangle)
	{
		float dX = (aRectangle->A->x - aRectangle->B->x);
		float dY = (aRectangle->A->y - aRectangle->B->y);
		theResult = sqrt(dX*dX + dY*dY);
		dX = (aRectangle->B->x - aRectangle->C->x);
		dY = (aRectangle->B->y - aRectangle->C->y);
		theResult_ = sqrt(dX*dX + dY*dY);
		theResult = theResult*theResult_;
	}
	return theResult;
}

void printRectangle(Rectangle *aRectangle)
{
	if (NULL != aRectangle)
	{
		printf ("[Rectangle]. A(%d,%d) - B(%d,%d)- C(%d,%d)- D(%d,%d)\n\n",
					aRectangle->A->x, aRectangle->A->y,
					aRectangle->B->x, aRectangle->B->y,
					aRectangle->C->x, aRectangle->C->y,
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

void Enter_Coordinate (int *X, int *Y)
{
    printf("x=");
    scanf("%d",X);
    printf("y=");
    scanf("%d",Y);
}

void Enter_Coordinate_Point_C (int *X, int *Y, int A_x, int A_y, int B_x, int B_y)
{
    int C_x,C_y;
    do
    {
        printf("x=");
        scanf("%d",&C_x);
        printf("y=");
        scanf("%d",&C_y);
        if(pow(A_x-B_x,2)+pow(A_y-B_y,2)+pow(C_x-B_x,2)+pow(C_y-B_y,2)!=pow(A_x-C_x,2)+pow(A_y-C_y,2))
        {
            printf("Error! Incorrect coordinates of point C. Enter again!");
        }
        printf("\n");

    }while(pow(A_x-B_x,2)+pow(A_y-B_y,2)+pow(C_x-B_x,2)+pow(C_y-B_y,2)!=pow(A_x-C_x,2)+pow(A_y-C_y,2));

           *X = C_x;
           *Y = C_y;
}
