#ifndef LB_2_H_INCLUDED
#define LB_2_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

int enter_size_array();
void enter_data_to_array(char *array, int size);
void write_array_in_fail(char *aray, int size, char *name);
void sort_bulbashka(char *aray, int n);
void sort_vstavka(char *aray, int size);
void sort_vybora(char *aray, int size);

char* loadFile (char * path , int size);


#endif
