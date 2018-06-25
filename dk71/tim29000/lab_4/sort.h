#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <stdio.h>
#include "SingleLinked_List.h"

int partitionIt(IntList *aList, int aLeftIndex, int aRightIndex, int aPivot);
void Sort(IntList *aList, int aLeftIndex, int aRightIndex);


#endif // SORT_H_INCLUDED
