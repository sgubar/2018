#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct tagPoint
{
	int x;
	int y;
}Point;

typedef struct Fig
{
	Point *A;
	Point *B;
	Point *C;
}Fig;

typedef struct tagParam
{
	float a;
	float b;
	float c;
	float S;
}Param;

Fig *createFig(Point *A, Point *B, Point *C);
void destroyFig(Fig *aFig);
Param *enterParam(Fig *aFig);
void printFig(Fig *aFig);
void printParam(Param *aParam);
void writePointToJSON(FILE *aFile, Point *aPoint);
void writeFigToJSON(FILE *aFile, Fig *aFig);

