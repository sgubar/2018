//
// Created by vadim on 28.03.2018.
//

#ifndef ECLIPSE_ARRAY_H
#define ECLIPSE_ARRAY_H
#include "dk_elips.h"
typedef struct tagElipsArray
{
    int number;
    int count;
    float Arrea;
    Elips **Elipses;
}ElipsArray;

ElipsArray *createArray(int aNumber);
void freeArray(ElipsArray *anArray);
int addElement(ElipsArray *anArray, Elips *aElips);
void writeArrayToJSON(FILE *aFile, ElipsArray *anArray);
void writePointToJSON(FILE *aFile, Point *aPoint);
void insertionSort(ElipsArray *anArray);
#endif //WORK2_DK_ECLIPSE_ARRAY_H
