#ifndef DK_SORT_H_INCLUDED
#define DK_SORT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

void shellSort(char *anArray, int aCount);
int binary_find(char *theArray, char search, int size);
void outArr(char* x, int size);
void inFile(char *aray, int size, char *name);
int GetCharsAmoutInFile (FILE* file);
char* loadFile (char * path , int * size);


#endif // DK_SORT_H_INCLUDED
