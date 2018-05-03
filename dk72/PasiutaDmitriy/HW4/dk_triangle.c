//
// Created by dima on 03.05.18.
//

//
// Created by dima on 03.05.18.
//

//
// Created by dima on 26.04.18.
//

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
        //size of - calculate  size of memory,take virazhenie and back size
        theResult = (Triangle *)malloc(sizeof(Triangle));// take block of memory and back pointer on start block
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

Point *copyPointWithPoint(Point *aPoint)//because strong type,did easy type from strong
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

void writePointToJSON(FILE *aFile, Point *aPoint)
{
    if (NULL == aPoint || NULL == aFile)
    {
        return ;
    }

    fprintf(aFile, "{\"x\" : %d, \"y\" : %d}", aPoint->x, aPoint->y);
}

void writeTriangleToJSON(FILE *aFile, Triangle *atriangle)
{
    if (NULL == atriangle || NULL == aFile)
    {
        return ;
    }

    fprintf(aFile, "{\n\"A\" : ");
    writePointToJSON(aFile, atriangle->A);
    fprintf(aFile, ",\n\"B\" : ");
    writePointToJSON(aFile, atriangle->B);
    fprintf(aFile, ",\n\"C\" : ");
    writePointToJSON(aFile, atriangle->C);
    fprintf(aFile, "\n}");
}


void enter(int *X, int *Y)
{
    printf("x=");
    scanf("%d",X);
    printf("y=");
    scanf("%d",Y);
}
