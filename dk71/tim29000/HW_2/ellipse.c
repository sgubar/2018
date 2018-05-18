#include "ellipse.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Ellipse *createEllipse(Point *A, Point *B, Point *C, Point *D, Point *Centre)
{
    Ellipse *Result = NULL;

    if(A != NULL && B != NULL && C != NULL && D != NULL && Centre != NULL)
    {
       if(abs(A->x) == abs(C->x) && abs(B->y) == abs(D->y) && A->y == C->y && B->x == D->x)
        {
           Result = ( Ellipse* )malloc(sizeof(Ellipse));

            if(Result != NULL)
            {
                Result->A = A;
                Result->B = B;
                Result->C = C;
                Result->D = D;
                Result-> Centre = Centre;
            }
        }

    }

    return Result;
}

void destroyEllipse(Ellipse *eEllipse)
{
    if(eEllipse != NULL)
    {
        free(eEllipse->A);
        free(eEllipse->B);
        free(eEllipse->C);
        free(eEllipse->D);
        free(eEllipse->Centre);
        free(eEllipse);
    }
}

int Ellipse_Area(Ellipse *eEllipse)
{
    int Result = 0;

    if(eEllipse != NULL)
    {
        int Part1 = (int)sqrt(pow(eEllipse->C->x - eEllipse->Centre->x, 2)+pow(eEllipse->C->y - eEllipse->Centre->y ,2));
        int Part2 = (int)sqrt(pow(eEllipse->B->x - eEllipse->Centre->x, 2)+pow(eEllipse->B->y - eEllipse->Centre->y ,2));
        Result = 3.14*Part1 * Part2;
    }

    return Result;
}
