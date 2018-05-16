#ifndef quickSort_h
#define quickSort_h

#include <stdio.h>
#include "list.h"

int partitionIt(doubleList *aList, int aLeftIndex, int aRightIndex, int aPivot);
void quickSort(doubleList *aList, int aLeftIndex, int aRightIndex);

#endif /* list_h */