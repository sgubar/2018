#ifndef DK_Elips_H
#define DK_Elips_H

#include <stdio.h>
#include <malloc.h>
#include <math.h>

typedef struct tagPoint
{
    int x;
    int y;
}Point;

typedef struct tagElips
{
    Point *A;
    Point *B;
    Point *C;
    Point *D;
    Point *middle;
    float Arrea;
}Elips;

Elips *createElips(Point *A, Point *B, Point *C, Point *D, Point *middle);
void destroyElips(Elips *aElips);
float ElipsArea(Elips *aElips);

void writeElipsToJSON(FILE *aFile, Elips *aElips);

#endif //UNTITLED_DK_Elips_H
