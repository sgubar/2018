#ifndef _DKSORT_H
#define _DKSORT_H
#include <stdio.h>
#include <time.h>


void swap (int *x, int *y);
void sortingtype( int arr[], int size, int selection);
void Selsort(int arr[], int size);
void Bubsort(int arr[], int size);
void Inssort(int arr[], int size);
void randsymbol(int arr[], int size);
void infile(int arr[], int size, char* name);

#endif
