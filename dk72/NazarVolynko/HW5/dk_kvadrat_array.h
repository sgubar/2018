#ifndef DK_KVADRAT_ARRAY_H_INCLUDED
#define DK_KVADRAT_ARRAY_H_INCLUDED

#include <stdio.h>
#include "dk_kvadrat.h"

typedef struct tagKvadratArray
{
	int number;
	int count;


	Kvadrat **Kvadrats;
}KvadratArray;


// init/dealloc
KvadratArray *createArray(int aNumber);
void freeArray(KvadratArray *anArray);

//interface
// returns index of added element OR -1 if fail
int addElement(KvadratArray *anArray, Kvadrat *aKvadrat);
void writeArrayToJSON(FILE *aFile, KvadratArray *anArray);

void quickSort( KvadratArray *anArray, int l, int r);
int partition( KvadratArray *anArray, int l, int r);
int linijnyj_poshuk(KvadratArray *anArray, float key);

void printKvadrat(Kvadrat *aKvadrat);//functsia dlz perevirky(dopomigna)

#endif // DK_KVADRAT_ARRAY_H_INCLUDED
