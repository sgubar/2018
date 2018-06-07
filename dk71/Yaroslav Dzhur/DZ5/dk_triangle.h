#include <stdio.h>
#include <malloc.h>
#include <math.h>

#ifndef UNTITLED_DK_triangle_H
#define UNTITLED_DK_triangle_H

typedef struct tagPoint
{
    int x;
    int y;
}Point;

typedef struct tagTriangle
{
    Point *A;
    Point *B;
    Point *C;
}Triangle;

Triangle *createTriangle(Point *A, Point *B, Point *C);
void destroyTriangle(Triangle *aTriangle);

int TriangleArea(Triangle *aTriangle);

Point *copyPointWithPoint(Point *aPoint);

void writeTriangleToJSON(FILE *aFile, Triangle *aTriangle);
void writePointToJSON(FILE *aFile, Point *aPoint);

#endif //UNTITLED_DK_Triangle_H
