#ifndef _DKSORT_H
#define _DKSORT_H
#include <stdio.h>
#include <time.h>


void swap (int *x, int *y);
void TypeOfSorting( int mass[], int size, int selection);
void SelectionSort(int mass[], int size);
void BubbleSort(int mass[], int size);
void InsertSort(int mass[], int size);
void randsymbol(int mass[], int size);
void WriteToFile(int mass[], int size, char* name);

#endif
