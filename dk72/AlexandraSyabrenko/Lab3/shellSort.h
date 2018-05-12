#ifndef shellSort_h
#define shellSort_h

#include <stdio.h>

int getSymbolsAmout(FILE *file);

char *getFromFileToArray(FILE *file);

void shellSort(char array[], int count);

void printArray(char array[], int length);

void printArrayToFile(char *array, int arrayLength);

int linearSearch(char array[], char lookedValue, int size);
#endif /* shellSort_h */
