#include <stdio.h>
#include "dk_tool.h"
#include "dk_triangle_array.h"
#define R 2.5

int main(int argc, const char * argv[])
{
    TriangleArray *theArray = createArray(4);

    Point A = {4, 0};
    Point B = {0, 0};
    Point C = {0, 4};

    Point D = {5, 0};
    Point E = {0, 0};
    Point G = {0, 5};

    Point K = {12, 0};
    Point X = {0, 0};
    Point Y = {0, 12};

    Point Q = {10, 0};
    Point W = {0, 0};
    Point T = {0, 10};

    Triangle ABC = {&A, &B, &C};
    Triangle DEG = {&D, &E, &G};
    Triangle KXY = {&K, &X,&Y};
    Triangle QWT = {&Q, &W,&T};

    addElement(theArray, &KXY);
    addElement(theArray, &ABC);
    addElement(theArray, &DEG);
    addElement(theArray, &QWT);

    int searchResult = (theArray, 12.5, theArray->count);
    printf("%d", searchResult);

    FILE *theFile = fopen("test_unsorted.json", "w");
    writeArrayToJSON(theFile, theArray);
    fflush(theFile);
    fclose(theFile);

    insertion_sort(theArray);
    
    FILE *theFile2 = fopen("test_sorted.json", "w");
    writeArrayToJSON(theFile, theArray);
    fflush(theFile2);
    fclose(theFile2);

    freeArray(theArray);

    return 0;
}
