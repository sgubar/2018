#ifndef LAB2_FUNC_H
#define LAB2_FUNC_H

#include <stdio.h>

void selectionSort(char *array, int size);
void insertionSort(char *array, int size);
void bubbleSort(char *array, int size);

void readFromFileToArray(FILE *file, char* array);
void printArrToFile(char *array, int size, char* name);

#endif //LAB2_FUNC_H
