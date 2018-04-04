#ifndef DK_KVADRAT_ARRAY_H_INCLUDED
#define DK_KVADRAT_ARRAY_H_INCLUDED

#include <stdio.h>
#include "dk_kvadrat.h"

typedef struct tagKvadratArray
{
	int number;
	int count;

	float *ploschaKvadrat;

	Kvadrat **Kvadrats;
}KvadratArray;


// init/dealloc
KvadratArray *createArray(int aNumber);
void freeArray(KvadratArray *anArray);

//interface
// returns index of added element OR -1 if fail
int addElement(KvadratArray *anArray, Kvadrat *aKvadrat, float ploscha);
void writeArrayToJSON(FILE *aFile, KvadratArray *anArray);

void sort_vstavka(KvadratArray *anArray);
void printKvadrat(Kvadrat *aKvadrat);//functsia dlz perevirky(dopomigna)

#endif // DK_KVADRAT_ARRAY_H_INCLUDED
