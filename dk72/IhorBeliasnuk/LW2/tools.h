//
// Created by Ihor on 28.03.2018.
//

#ifndef LW2_TOOLS_H
#define LW2_TOOLS_H

#include <stdio.h>
#include <time.h>

void swap (int *element1Ptr, int *element2Ptr);
void selectionSort(int values[], int n);
void bubbleSort(int array[], int size);
void insertionSort(int array[], int size);
void randomSymbolFilling(int array[], int size);
void printArrToFile(int array[], int size, char* name);

#endif //LW2_TOOLS_H
