#ifndef Dz_6_sort_h
#define Dz_6_sort_h

#include <stdio.h>
#include "Dz_6_SingleLinkedList.h"

int partitionIt(IntList *aList, int aLeftIndex, int aRightIndex, int aPivot);
void quickSort(IntList *aList, int aLeftIndex, int aRightIndex);

#endif
