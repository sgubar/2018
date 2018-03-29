
#include <stdio.h>
#include <stdlib.h>
#include "dk_elips.h"
#include "dk_eclipse_array.h"

int main()
{
    ElipsArray *theArray = createArray(5);

    Point A = {-2, 0};//declaring points
    Point B = {0, 1};
    Point C = {2, 0};
    Point D = {0, -1};
    Point middle = {0,0};

    Point X = {-4, 0};//declaring points
    Point Y = {0, 2};
    Point Z = {4, 0};
    Point K = {0, -2};
    Point middle2 = {0,0};

    Elips *first = createElips(&A, &B, &C, &D,&middle);
    Elips *second = createElips(&X, &Y, &Z, &K,&middle2);



    addElement(theArray, first);
    addElement(theArray, second);

    FILE *theFile = fopen("test.json", "a+");

    writeArrayToJSON(theFile, theArray);

    fflush(theFile);
    fclose(theFile);

    freeArray(theArray);
}