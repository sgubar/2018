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
void QuickSort(int *QS_arr, int first, int second);
int bin_search(char *bn_arr, int bn_size, char bn_el);
#endif /*laba_h*/
