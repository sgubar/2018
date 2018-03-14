//
// Created by Ihor on 12.03.2018.
//

#include <stdio.h>
#include <malloc.h>
#include <math.h>

#ifndef UNTITLED_DK_RECTANGLE_H
#define UNTITLED_DK_RECTANGLE_H

typedef struct tagPoint
{
    int x;
    int y;
}Point;

typedef struct tagRectangle
{
    Point *A;
    Point *B;
    Point *C;
    Point *D;
}Rectangle;

Rectangle *createRectangle(Point *A, Point *B, Point *C, Point *D);
void destroyRectangle(Rectangle *aRectangle);

int rectangleArea(Rectangle *aRectangle);

#endif //UNTITLED_DK_RECTANGLE_H
