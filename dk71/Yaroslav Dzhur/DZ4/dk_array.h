#ifndef UNTITLED_DK_ARRAY_H
#define UNTITLED_DK_ARRAY_H

#include <stdio.h>
#include <malloc.h>

#include "dk_triangle.h"

typedef struct tagTriangleArray
{
    int number;
    int count;

    Triangle **Triangles;
}TriangleArray;

TriangleArray *createArray(int aNumber);
int addElement(TriangleArray *anArray, Triangle *aTriangle);
void freeArray(TriangleArray *anArray);
void writeArrayToJSON(FILE *aFile, TriangleArray *anArray);



#endif //UNTITLED_DK_ARRAY_H
