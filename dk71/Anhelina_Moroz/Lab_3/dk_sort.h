#ifndef DK_SORT_H_INCLUDED
#define DK_SORT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>


void quickSort( char *array, int l, int r);
int partition( char *array, int l, int r);
int binarysearch(char key, char *array, int size) ;
void output_of_the_array(char* x, int size);
void record_to_file(char *aray, int size, char *name);
int FileSize (FILE* file);
char* loadFile (char * path , int * size);


#endif
