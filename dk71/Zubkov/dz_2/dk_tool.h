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
}Elips;

Elips *createElips(Dot *A, Dot *B, Dot *C, Dot *D, Dot *middle);
void destroyElips(Elips *aElips);

int ElipsSquare(Elips *aElips);
void interface(void);

#endif 
