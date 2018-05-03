

//
// Created by dima on 26.04.18.
//

#ifndef HW3_DK_TRIANGLE_ARRAY_H
#define HW3_DK_TRIANGLE_ARRAY_H
#include <stdio.h>
#include "dk_triangle.h"

typedef struct tagTriangleArray
{
    int number;
    int count;

    Triangle **triangles;
}TriangleArray;


// init/dealloc
TriangleArray *createArray(int aNumber);
void freeArray(TriangleArray *anArray);

//interface
// returns index of added element OR -1 if fail
int addElement(TriangleArray *anArray, Triangle *atriangle);
void writeArrayToJSON(FILE *aFile, TriangleArray *anArray);


#endif //HW3_DK_TRIANGLE_ARRAY_H
