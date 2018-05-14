//
// Created by Ihor on 27.03.2018.
//

#ifndef UNTITLED_DK_ARRAY_H
#define UNTITLED_DK_ARRAY_H

#include <stdio.h>
#include <malloc.h>

#include "dk_rectangle.h"

typedef struct tagRectangleArray
{
    int number;
    int count;

    Rectangle **rectangles;
}RectangleArray;

RectangleArray *createArray(int aNumber);
int addElement(RectangleArray *anArray, Rectangle *aRectangle);
void freeArray(RectangleArray *anArray);
void writeArrayToJSON(FILE *aFile, RectangleArray *anArray);



#endif //UNTITLED_DK_ARRAY_H
