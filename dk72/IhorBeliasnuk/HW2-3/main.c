#include <stdio.h>
#include "dk_rectangle.h"
#include "dk_array.h"
#include "dk_sort.h"

int main()
{


    Point A = {-1, 2};//declaring points
    Point B = {1, 2};
    Point C = {1, -1};
    Point D = {-1, -1};

    Point X = {-2, 4};//declaring points
    Point Y = {2, 4};
    Point Z = {2, -2};
    Point K = {-2, -2};

    Point F = {-4, 4};//declaring points
    Point G = {4, 4};
    Point H = {4, -4};
    Point J = {-4, -4};

    Rectangle *example1 = createRectangle(&A, &B, &C, &D);
    Rectangle *example2 = createRectangle(&X, &Y, &Z, &K);
    Rectangle *example3 = createRectangle(&F, &G, &H, &J);

    RectangleArray *RectBase = createArray(3);

    addElement(RectBase, example3);
    addElement(RectBase, example2);
    addElement(RectBase, example1);

    FILE *file1 = fopen("rectbase_unsorted.json", "w");

    writeArrayToJSON(file1, RectBase);

    fclose(file1);

    selectionSort(RectBase, RectBase->count);

    FILE *file2 = fopen("rectbase_sorted.json", "w");

    writeArrayToJSON(file2, RectBase);

    fclose(file2);

    freeArray(RectBase);
}



