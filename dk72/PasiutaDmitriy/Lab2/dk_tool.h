//
// Created by dima on 18.05.18.
//

#ifndef LABA2_DK_TOOL_H
#define LABA2_DK_TOOL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void buble_sort(char *aray, int n);
void output_of_the_array(char* x, int size);
void insert_sort(char *aray, int size);
void selection_sort(char *aray, int size);
void record_to_file(char *aray, int size, char *name);
int GetLetterAmoutInFile (FILE* file);
int GetCharsAmoutInFile (FILE* file);
char* loadFile (char * path , int * size);

#endif //LABA2_DK_TOOL_H
