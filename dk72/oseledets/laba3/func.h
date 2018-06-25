//
// Created by Ihor on 20.06.2018.
//

#ifndef LAB2_FUNC_H
#define LAB2_FUNC_H

#include <stdio.h>

void shellSort(char *array, int aCount);
int binarySearch(char soughtValue, char *anArray, int size);

void readFromFileToArray(FILE *file, char* array);
void printArrToFile(char *array, int size, char* name);

#endif //LAB2_FUNC_H
