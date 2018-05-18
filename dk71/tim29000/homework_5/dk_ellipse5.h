#ifndef DK_ELLIPSE5_H_INCLUDED
#define DK_ELLIPSE5_H_INCLUDED

#include <stdio.h>
#include <malloc.h>
#include <math.h>

typedef struct tagPoint
{
    int x;
    int y;
}Point;

typedef struct tagEllipse
{
    Point *A;
    Point *B;
    Point *C;
    Point *D;
    Point *Centre;
    float Area;
}Ellipse;

Ellipse *createEllipse(Point *A, Point *B, Point *C, Point *D, Point *Centre);

void destroyEllipse(Ellipse *eEllipse);

void writeEllipse(FILE *eFile, Ellipse *eEllipse);

float Ellipse_Area(Ellipse *eEllipse);


#endif // DK_ELLIPSE5_H_INCLUDED
