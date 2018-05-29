#ifndef sort_h
#define sort_h
#include <stdio.h>

char *scan_file(FILE *input,  char **p);

char *quick_sort(char **array,  char **n);
void binary_find(char **n,char serch[32],FILE *output); 
#endif
