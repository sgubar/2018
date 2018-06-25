#ifndef HW6_QUICKSORT_H
#define HW6_QUICKSORT_H
#include "list.h"

int partitionIt(IntList *aList, int aLeftIndex, int aRightIndex, int aPivot);
void SwapNodesByIndex(IntList *aList, int aLeftIndex, int aRightIndex);
void quickSort(IntList *aList, int aLeftIndex, int aRightIndex);
IntNode *IntValueAtIndex(IntList *aList, int anIndex);
int FindMin(IntList *aList);
#endif //HW6_QUICKSORT_H
