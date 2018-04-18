#ifndef _DKSORT_H

#define _DKSORT_H



#include <stdio.h>

#include <time.h>



void swap (int *ELx, int *ELy);

void Rec_To_File(int array[], int size, char* name);

void three_type_sort(int array[], int size, int selection);

void selectionSort(int array[], int size);

void bubbleSort(int array[], int size);

void insertionSort(int array[], int size);

void random_letter(int array[], int size);





#endif 
