//
// Created by dima on 18.05.18.
//

#ifndef LABA3_DK_TOOL_H
#define LABA3_DK_TOOL_H



#include "stdio.h"
#include "stdlib.h"
#include <time.h>

void randomSymbolFilling(char *array, int size);
void printArrToFile(char *array, int size, char* name);
int partitionIt(char *anArray, int aLeftIndex, int aRightIndex, int aPivot);
void quickSort(char *anArray, int aLeftIndex, int aRightIndex);
int linearSearch(char anArray[], char aSymbol, int size);




#endif //LABA3_DK_TOOL_H
