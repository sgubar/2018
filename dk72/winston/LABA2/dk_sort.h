#ifndef DK_SORT_H_INCLUDED
#define DK_SORT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

void buble_sort(char *aray, int n);
void output_of_the_array(char* x, int size);
void sort_insert(char *aray, int size);
void sort_selection(char *aray, int size);
void record_to_file(char *aray, int size, char *name);
int GetLetterAmoutInFile (FILE* file);
int GetCharsAmoutInFile (FILE* file);
char* loadFile (char * path , int * size);


#endif // DK_SORT_H_INCLUDED
