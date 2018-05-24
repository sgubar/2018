#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "dru_dz.h"

typedef struct tegFigArr
{
	int num;
	int count;
	Fig **aFig;
	float *S;
}FigArr;

FigArr *createArr();
void addElement(FigArr *anArr, Fig *aFig, Param *fig_par);
void freeArr(FigArr *anArr);
void writeArrayToJSON(FILE *aFile, FigArr *anArr);
void bubbleSort(FigArr *anArray);
void TMP(FigArr *A1, FigArr *A2);
void printArr(FigArr *anArray);

