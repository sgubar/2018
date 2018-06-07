#include "dk_sort.h"

void selectionSort(TriangleArray *array, int size)
{
    for (int i = 0; i < size; i++) {
        int lover = i;
        for (int j = i+1; j < size; j++)
        {
            Triangle *firstOne = array->Triangles[j];
            Triangle *secondOne = array->Triangles[lover];
            if (TriangleArea(firstOne) > TriangleArea(secondOne))
                lover = j;
        }
        swap(array->Triangles[lover], array->Triangles[i]);
    }
}

void swap (Triangle *element1Ptr, Triangle *element2Ptr)
{
    Triangle temp = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = temp;
}
