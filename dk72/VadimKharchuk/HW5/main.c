
#include <stdio.h>
#include <stdlib.h>
#include "dk_elips.h"
#include "dk_elipse_array.h"

int main()
{
    float WhatFind = 37.680000;
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

    Point a = {-6, 0};//declaring points
    Point b = {0, 2};
    Point c = {6, 0};
    Point d = {0, -2};
    Point middle3 = {0,0};

    Point aA = {-5, 0};//declaring points
    Point bB = {0, 6};
    Point cC = {5, 0};
    Point dD = {0, -6};
    Point middle4 = {0,0};

    Elips *first = createElips(&A, &B, &C, &D,&middle);
    Elips *second = createElips(&aA, &bB,&cC,&dD,&middle4);
    Elips *third = createElips(&X, &Y, &Z, &K,&middle2);
    Elips *fourth = createElips(&a, &b, &c, &d, &middle3);


    addElement(theArray, first);
    addElement(theArray, second);
    addElement(theArray, third);
    addElement(theArray, fourth);


    FILE *theFile = fopen("test.json", "a+");
    FILE *sortedFile = fopen("Sorted.json", "a+");

    writeArrayToJSON(theFile, theArray);
    shell_sort(theArray);
    writeArrayToJSON(sortedFile, theArray);

    lineSeach(theArray,WhatFind);

    fflush(theFile);
    fclose(theFile);

    fflush(sortedFile);
    fclose(sortedFile);

    freeArray(theArray);
}
