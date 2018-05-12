#ifndef sorting_h
#define sorting_h
#include <time.h>
#include <stdio.h>
char *getFromFileToArray(FILE *file);

void printArrayToScreen(char* array, int arrayLength);

int getSymbolsAmout(FILE *file);

void bubbleSort(char *array, int arrayLength);

void selectionSort(char *array,int arrayLength);

void insertionSort(char *array,int arrayLength);

void printArrayToFile(char *array, int arrayLength);

#endif /* sorting_h */
