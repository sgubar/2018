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

Point *copyPointWithPoint(Point *aPoint);

void writeRectangleToJSON(FILE *aFile, Rectangle *aRectangle);
void writePointToJSON(FILE *aFile, Point *aPoint);

#endif //UNTITLED_DK_RECTANGLE_H
