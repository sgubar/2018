#ifndef _DKTOOLS_H

#define _DKTOOLS_H



#include <stdio.h>

#include <time.h>



void swap (int *ELx, int *ELy);

void three_type_sort( int array[], int size, int selection);

void S_Sort(int array[], int size);

void B_Sort(int array[], int size);

void I_Sort(int array[], int size);

void random_letter(int array[], int size);

void Rec_To_File(int array[], int size, char* name);



#endif 
