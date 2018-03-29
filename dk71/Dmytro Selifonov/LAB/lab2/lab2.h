#ifndef lab2_h
#define lab2_h
#include <stdio.h>
void scanFile(FILE *input);

void bubble(char strings[][32] ,int size, FILE *output );
void selection (char strings[][32] ,int size, FILE *output );
void insertion(char strings[][32] ,int size, FILE *output );
#endif
