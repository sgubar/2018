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
float *S;
}KvadratArray;

KvadratArray *createArray(int);

int addElement(KvadratArray *anArray, Kvadrat *aKvadrat, float);
void freeArray(KvadratArray *anArray);
void writeArrayToJSON(FILE *aFile, KvadratArray *anArray);
void outputConsoleArrayKvadrats(KvadratArray* anArray);
void bubble(KvadratArray *anArray);
void shell(KvadratArray *anArray);
float demoS; /* демонстрационная переменная для сохранения площади квадрата*/
void find2(KvadratArray *anArray);
#endif // KVARAAY_H_INCLUDED
