//
// Created by Ihor on 11.04.2018.
//

#ifndef LW3_TOOLS_H
#define LW3_TOOLS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomSymbolFilling(char *array, int size);
void printArrToFile(char *array, int size, char* name);
int partitionIt(char *anArray, int aLeftIndex, int aRightIndex, int aPivot);
void quickSort(char *anArray, int aLeftIndex, int aRightIndex);
int binarySearch(char soughtValue, char anArray[], int size);

#endif //LW3_TOOLS_H
