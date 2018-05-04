#ifndef laba_h
#define laba_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int size_f();
void enter_array(int *en_array, int en_size);
void write_to_file(int *wtf_arr, int wtf_size, char name_file[10]);
void read_file(char *rf_tname);
//void QuickSort(int *QS_arr, int first, int second);
void buble_sort(int *bub_arr, int bub_size);
void insertion_sort(int* is_arr, int is_size);
void sort_chose(int* sc_arr, int sc_size);
#endif /*laba_h*/