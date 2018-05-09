#ifndef quickSort_h
#define quickSort_h

#include <stdio.h>
#include "SingleLinkedList.h"

int partitionIt(IntList *aList, int aLeftIndex, int aRightIndex, int aPivot);
void quickSort(IntList *aList, int aLeftIndex, int aRightIndex);

#endif