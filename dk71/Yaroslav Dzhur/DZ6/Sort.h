#ifndef quickSort_h
#define quickSort_h

#include <stdio.h>
#include "dk_tool.h"

int partitionIt(doubleList *aList, int aLeftIndex, int aRightIndex, int aPivot);
void quickSort(doubleList *aList, int aLeftIndex, int aRightIndex);

#endif /* dk_tool_h */
