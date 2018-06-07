#ifndef UNTITLED_DK_Elips_H
#define UNTITLED_DK_Elips_H

#include <stdio.h>
#include <malloc.h>
#include <math.h>

typedef struct tagDot
{
    int x;
    int y;
}Dot;

typedef struct tagElips
{
    Dot *A;
    Dot *B;
    Dot *C;
    Dot *D;
    Dot *middle;
    float Arrea;
}Elips;
typedef struct ElipsArray
{
    int number;
    int count;

    Elips **Elipses;
}ElipsArray;
Elips *createElips(Dot *A, Dot *B, Dot *C, Dot *D, Dot *middle);
void destroyElips(Elips *aElips);

int ElipsSquare(Elips *aElips);
ElipsArray *createArray(int aNumber);
void freeArray(ElipsArray *anArray);
ElipsArray *createArray(int aNumber);
int addElement(ElipsArray *anArray, Elips *aElips);
void ArrToJSON(FILE *aFile, ElipsArray *anArray);
void dotToJSON(FILE *aFile, Dot *aPoint);
void interface(void);
void interfaceArray(void);




#endif //UNTITLED_DK_Elips_H
