#include "dk_triangle.h"
#include <stdio.h>
#include <stdlib.h>
#define R 2.5

Point *copyPointWithPoint(Point *aPoint);

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

float flatTriangle(Triangle *atriangle)
{
    int theResult = 0.0;

    if (NULL != atriangle)
    {
        float A = (atriangle->A->x - atriangle->C->x);
        float B = (atriangle->B->y - atriangle->C->y);
        float C = (atriangle->A->y - atriangle->C->y);
        theResult = abs(((A*B*C)/(4*R)));
    }

    return theResult;
}

void printTriangle(Triangle *atriangle)
{
    if (NULL != atriangle)
    {
        printf ("\tCoordinates of vertices\n\n \t\tA(%d,%d)\n  \t\tB(%d,%d)\n  \t\tC(%d,%d)\n\n",
                atriangle->A->x, atriangle->A->y,
                atriangle->B->x, atriangle->B->y,
                atriangle->C->x, atriangle->C->y);
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

void destroyTriangle(Triangle *atriangle)
{
    if (NULL != atriangle)
    {
        free(atriangle->A);
        free(atriangle->B);
        free(atriangle->C);
        free(atriangle);
    }
}
