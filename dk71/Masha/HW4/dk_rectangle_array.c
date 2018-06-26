#include<stdio.h>
#include <stdlib.h>
#include "dk_rectangle_array.h"

RectangleArray *createArray(int aNumber)
{
	RectangleArray *theResult = NULL;

	if (aNumber > 0)
	{
		theResult = (RectangleArray *)malloc(sizeof(RectangleArray));

		if (NULL != theResult)
		{
			theResult->rectangles = (Point **)malloc(sizeof(Point *)*aNumber);
            theResult->Ploscha = malloc(sizeof(float)*aNumber);
			if (NULL != theResult->rectangles)
			{
				theResult->number = aNumber;
				theResult->count = 0;
			}
			else
			{
				free(theResult);
				theResult = NULL;
			}
		}
	}

	return theResult;
}

void freeArray(RectangleArray *anArray)
{
	if (NULL != anArray)
	{
		for (int i = 0; i < anArray->count; i ++)
		{
			destroyRectangle(anArray->rectangles[i]);
		}

		free(anArray->rectangles);
		free(anArray);
	}
}

int addElement(RectangleArray *anArray, Point *aRectangle,float Ploscha)
{
	int theResult = -1;

	if (NULL != anArray && NULL != aRectangle &&
				anArray->count < anArray->number)
	{
		anArray->rectangles[anArray->count] =
					createRectangle(aRectangle->A, aRectangle->B,aRectangle->C,aRectangle->D);

					anArray->Ploscha[anArray->count] = Ploscha;
		theResult = anArray->count;
		anArray->count ++;
	}

	return theResult;
}

void writeArrayToJSON(FILE *aFile, RectangleArray *anArray)
{
	if (NULL == anArray || NULL == aFile)
	{
		return ;
	}

	fprintf(aFile, "{\n\"number\" : %d,\n\"count\" : %d,\n",
			anArray->number, anArray->count);
	fprintf(aFile, "\"rectangle\" : \n[\n");

	for (int i = 0; i < anArray->count; i ++)
	{
		writeRectangleToJSON(aFile, anArray->rectangles[i]);

		if (i < anArray->count - 1)
		{
			fprintf(aFile, ",");
		}
		fprintf(aFile, "\n");
	}

	fprintf(aFile, "],\n}");
}
void inception_sort(RectangleArray *anArray)
{
    Point *newElement=NULL;
    int  i,j;
    for (j = 1; j <anArray->count ; j++) {
        newElement = anArray->rectangles[j];
        for (i = j;anArray->Ploscha[i-1] > anArray->Ploscha[i] && i > 0; i--) {
            anArray->rectangles[i] = anArray->rectangles[i-1];
        }
    anArray->rectangles[i] = newElement;

    }


}
