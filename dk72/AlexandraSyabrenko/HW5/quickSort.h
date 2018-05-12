#ifndef quickSort_h
#define quickSort_h

#include <stdio.h>
#include "functions2.h"
#include "functions.h"

int partitionIt(ArrayCircles *array, int leftIndex, int rightIndex, int pivot);

void quickSort(ArrayCircles *array, int leftIndex, int rightIndex);

int linearSearch(ArrayCircles *anArray, int key);
#endif /* quickSort_h */
