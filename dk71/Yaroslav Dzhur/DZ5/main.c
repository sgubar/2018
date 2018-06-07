#include <stdio.h>
#include "dk_triangle.h"
#include "dk_array.h"
#include "dk_sort.h"

int main()
{


    Point A = {-1, 2};//declaring points
    Point B = {1, -1};
    Point C = {-1, -1};

    Point X = {-2, 4};//declaring points
    Point Y = {2, -2};
    Point Z = {-2, -2};

    Point F = {-4, 4};//declaring points
    Point G = {4, -4};
    Point H = {-4, -4};

    Triangle *example1 = createTriangle(&A, &B, &C);
    Triangle *example2 = createTriangle(&X, &Y, &Z);
    Triangle *example3 = createTriangle(&F, &G, &H);


    TriangleArray *TriBase = createArray(3);

    addElement(TriBase, example2);
    addElement(TriBase, example1);
    addElement(TriBase, example3);


    FILE *file1 = fopen("unsorted.json", "w");

    writeArrayToJSON(file1, TriBase);

    fclose(file1);

    shellSort(TriBase, TriBase->count);

    printf("\nresult - %d", binarySearch(6, TriBase, TriBase->count));

    FILE *file2 = fopen("sorted.json", "w");

    writeArrayToJSON(file2, TriBase);

    fclose(file2);

    freeArray(TriBase);
}



