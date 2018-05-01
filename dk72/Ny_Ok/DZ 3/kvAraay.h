#ifndef KVARAAY_H_INCLUDED
#define KVARAAY_H_INCLUDED

#include <stdio.h>
#include <malloc.h>

#include "kvadratV3.h"

typedef struct tagKvadratArray
{
int num;
int count;
Kvadrat **kvadrats;
float S;
}KvadratArray;

KvadratArray *createArray(int);
int addElement(KvadratArray *anArray, Kvadrat *aKvadrat);
void freeArray(KvadratArray *anArray);
void writeArrayToJSON(FILE *aFile, KvadratArray *anArray);
/*void output_consoleKvadratArray(KvadratArray *anArray, Kvadrat *aKvadrat);*/
#endif // KVARAAY_H_INCLUDED
