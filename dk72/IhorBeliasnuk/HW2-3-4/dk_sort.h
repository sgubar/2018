//
// Created by Ihor on 15.05.2018.
//

#ifndef UNTITLED_DK_SORT_H
#define UNTITLED_DK_SORT_H

#include <stdio.h>
#include "dk_rectangle.h"
#include "dk_array.h"

void swap (Rectangle *element1Ptr, Rectangle *element2Ptr);
void selectionSort(RectangleArray *array, int size);
void shellSort(RectangleArray *array, int aCount);
int binarySearch(int soughtValue, RectangleArray *anArray, int size);


#endif //UNTITLED_DK_SORT_H
