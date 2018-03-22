#include "dz3.h"
#include <stdlib.h>


TrapezeArray *createArray(int aNumber)
{
	TrapezeArray *theResult = NULL;
	
	if (aNumber > 0)
	{
		theResult = (TrapezeArray *)malloc(sizeof(TrapezeArray));
	
		if (NULL != theResult)
		{
			theResult->trapezes = (Trapeze **)malloc(sizeof(Trapeze *)*aNumber);
		
			if (NULL != theResult->trapezes)
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

void freeArray(TrapezeArray *anArray)
{
	if (NULL != anArray)
	{
		int i;
		for (i = 0; i < anArray->count; i ++)
		{
			destroyTrapeze(anArray->trapezes[i]);
		}
	
		free(anArray->trapezes);
		free(anArray);
	}
}

int addElement(TrapezeArray *anArray, Trapeze *aTrapeze)
{
	int theResult = -1;
	
	if (NULL != anArray && NULL != aTrapeze &&
				anArray->count < anArray->number)
	{
		anArray->trapezes[anArray->count] =
					createTrapeze(aTrapeze->A, aTrapeze->B,aTrapeze->C,aTrapeze->D);
	
		theResult = anArray->count;
		anArray->count ++;
	}
	
	return theResult;
}

void writeArrayToJSON(FILE *aFile, TrapezeArray *anArray)
{
	if (NULL == anArray || NULL == aFile)
	{
		return ;
	}
	
	fprintf(aFile, "{\n\"number\" : %d,\n\"count\" : %d,\n",
			anArray->number, anArray->count);
	fprintf(aFile, "\"trapezes\" : \n[\n");
	
	int i;
	for ( i = 0; i < anArray->count; i ++)
	{
		writeTrapezeToJSON(aFile, anArray->trapezes[i]);
	
		if (i < anArray->count - 1)
		{
			fprintf(aFile, ",");
		}
		fprintf(aFile, "\n");
	}
	
	fprintf(aFile, "]\n}");
}

void writeTrapezeToJSON(FILE *aFile, Trapeze *aTrapeze)
{
	if (NULL == aTrapeze || NULL == aFile)
	{
		return ;
	}

	fprintf(aFile, "{\n\"A\" : ");
	writePointToJSON(aFile, aTrapeze->A);
	fprintf(aFile, ", \n\"B\" : ");
	writePointToJSON(aFile, aTrapeze->B);
	fprintf(aFile, ",\n\"C\" : ");
	writePointToJSON(aFile, aTrapeze->C);
	fprintf(aFile, ",\n\"D\" : ");
	writePointToJSON(aFile, aTrapeze->D);
	fprintf(aFile, "\n}");
}

void writePointToJSON(FILE *aFile, Point *aPoint)
{
	if (NULL == aPoint || NULL == aFile)
	{
		return ;
	}
	
	fprintf(aFile, "{\"x\" : %d, \"y\" : %d}", aPoint->x, aPoint->y);
}
