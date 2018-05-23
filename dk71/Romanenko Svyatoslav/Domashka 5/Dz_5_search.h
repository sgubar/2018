#ifndef DZ_5_SEARCH_H_INCLUDED
#define DZ_5_SEARCH_H_INCLUDED

#include <stdio.h>
#include "Dz_5.h"

typedef struct tagKvadratArray
{
	int number;
	int count;

	float *IndKvadrat;

	Kvadrat **Kvadrats;
}KvadratArray;

KvadratArray *createArray(int aNumber);
void freeArray(KvadratArray *anArray);

int addElement(KvadratArray *anArray, Kvadrat *aKvadrat, float Ind);
void writeArrayToJSON(FILE *aFile, KvadratArray *anArray);

void shellSort(KvadratArray *anArray);
int linear_search(KvadratArray *anArray, float key);
void printArray(KvadratArray *anArray);

#endif
