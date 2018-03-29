#ifndef sort_h
#define sort_h
#include <stdio.h>

void scan_file(FILE *input);
void sort_bubble(char strings[][32] ,int count, FILE *output );
void sort_choice (char strings[][32] ,int count, FILE *output );
void sort_pass(char strings[][32] ,int count, FILE *output );
#endif
