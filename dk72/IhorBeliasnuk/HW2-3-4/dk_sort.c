//
// Created by Ihor on 15.05.2018.
//

#include "dk_sort.h"

void selectionSort(RectangleArray *array, int size)
{
    for (int i = 0; i < size; i++) {
        int lover = i;
        for (int j = i+1; j < size; j++)
        {
            Rectangle *firstOne = array->rectangles[j];
            Rectangle *secondOne = array->rectangles[lover];
            if (rectangleArea(firstOne) < rectangleArea(secondOne))
                lover = j;
        }
        swap(array->rectangles[lover], array->rectangles[i]);
    }
}

void swap (Rectangle *element1Ptr, Rectangle *element2Ptr)
{
    Rectangle temp = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = temp;
}