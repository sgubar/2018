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

    Point Ab = {-5, 5};
    Point Ac = {5, 5};
    Point Ad = {5, -5};
    Point Ae = {-5, -5};

    Point AA = {-40, 40};
    Point BB = {40, 40};
    Point CC = {40, -40};
    Point DD = {-40, -40};

    Rectangle *example1 = createRectangle(&A, &B, &C, &D);
    Rectangle *example2 = createRectangle(&X, &Y, &Z, &K);
    Rectangle *example3 = createRectangle(&F, &G, &H, &J);
    Rectangle *example4 = createRectangle(&Ab, &Ac, &Ad, &Ae);
    Rectangle *example5 = createRectangle(&AA, &BB, &CC, &DD);

    RectangleArray *RectBase = createArray(5);

    addElement(RectBase, example3);
    addElement(RectBase, example2);
    addElement(RectBase, example1);
    addElement(RectBase, example5);
    addElement(RectBase, example4);

    FILE *file1 = fopen("rectbase_unsorted.json", "w");

    writeArrayToJSON(file1, RectBase);

    fclose(file1);

    int select;
    printf("\nEnter 1 for selection sort, 2 - for Shell sort\n");
    scanf("%d", &select);

    if(select == 1)
    {
        selectionSort(RectBase, RectBase->count);
    }
    if(select == 2)
    {
        shellSort(RectBase, RectBase->count);
    }

    printf("\nresult - %d", binarySearch(64, RectBase, RectBase->count));

    FILE *file2 = fopen("rectbase_sorted.json", "w");

    writeArrayToJSON(file2, RectBase);

    fclose(file2);

    freeArray(RectBase);
}



