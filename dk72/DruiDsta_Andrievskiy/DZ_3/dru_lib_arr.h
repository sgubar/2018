#pragma once
#include <stdio.h>
#include "dru_lib.h"

typedef struct tegFigArr
{
	int num;
	int count;
	Fig **aFig;
	float S;
}FigArr;

FigArr *createArr();
int addElement(FigArr *anArr, Fig *aFig, Param *fig_par);
void freeArr(FigArr *anArr);
void writeArrayToJSON(FILE *aFile, FigArr *anArr);
