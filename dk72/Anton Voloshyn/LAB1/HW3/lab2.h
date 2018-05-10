#ifndef LAB_H
#define LAB_H
#include "dk_tool.h"
typedef struct tagTriangleArray
{
    int number;
    int count;
    
    Triangle **Triangles;
}ArrayOfTriangle;

ArrayOfTriangle *createArray(int aNumber);
void freeArray(ArrayOfTriangle *anArray);
ArrayOfTriangle *createArray(int aNumber);
int addTriangle(ArrayOfTriangle *anArray, Triangle *aTriangle);
void writeArrayToJSON(FILE *aFile, ArrayOfTriangle *anArray);
void writePointToJSON(FILE *aFile, Point *aPoint);
#endif
