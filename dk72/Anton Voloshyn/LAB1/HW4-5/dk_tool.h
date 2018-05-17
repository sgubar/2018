
#ifndef UNTITLED_DK_TRIANGLE_H
#define UNTITLED_DK_TRIANGLE_H

#include <stdio.h>

#include <math.h>

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
void quickSort( ArrayOfTriangle *anArray, int l, int r);
int partition( ArrayOfTriangle *anArray, int l, int r);
int AreaOfTriangle(Triangle *aTriangle);
Point *copyPointWithPoint(Point *aPoint);
void writeFileToJSON(FILE *aFile, Triangle *aTriangle);
void Bubble_Sort(int anArray[], int aSize);
int binary_find(ArrayOfTriangle *theArray, int search);


#endif
