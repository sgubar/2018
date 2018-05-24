#ifndef _DKSORT_H

#define _DKSORT_H



#include <stdio.h>
#include <time.h>



void swap (int *ELx, int *ELy);
void random_letter(int array[], int size);
void Rec_To_File(int array[], int size, char* name);
void quick_sort(int *array, int first, int last);
int binary_search(int *array, int size, int el);


#endif 
