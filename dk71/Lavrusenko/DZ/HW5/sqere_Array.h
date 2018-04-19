#ifndef sqere_Array_h
#define sqere_Array_h

#include <stdio.h>
#include <stdlib.h>
#include "area.h"


typedef struct init_Array_Sqere
{
	int number;
	int counter;
	Sqere **sqere;
}ArraySqere;
ArraySqere *createArray(int Number);
int addElement(ArraySqere *array, Sqere *sqere);
void wrireToJSON(FILE *file, ArraySqere *array);
void freeArray(ArraySqere *array);
#endif
