#include "dk_kvadrat_array.h"
#include <stdlib.h>

// init/dealloc
KvadratArray *createArray(int aNumber)
{
	KvadratArray *theResult = NULL;

	if (aNumber > 0)
	{
		theResult = (KvadratArray *)malloc(sizeof(KvadratArray));

		if (NULL != theResult)
		{
			theResult->Kvadrats = (Kvadrat **)malloc(sizeof(Kvadrat *)*aNumber);

			if (NULL != theResult->Kvadrats)
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

void freeArray(KvadratArray *anArray)
{
	if (NULL != anArray)
	{
		for (int i = 0; i < anArray->count; i ++)
		{
			destroyKvadrat(anArray->Kvadrats[i]);
		}

		free(anArray->Kvadrats);
		free(anArray);
	}
}

//interface
//returns index of added element OR -1 if fail
int addElement(KvadratArray *anArray, Kvadrat *aKvadrat)
{
	int theResult = -1;

	if (NULL != anArray && NULL != aKvadrat &&
				anArray->count < anArray->number)
	{
		anArray->Kvadrats[anArray->count] =
					createKvadrat(aKvadrat->A, aKvadrat->B, aKvadrat->C,aKvadrat->D);

		theResult = anArray->count;
		anArray->count ++;
	}

	return theResult;
}

void writeArrayToJSON(FILE *aFile, KvadratArray *anArray)
{
	if (NULL == anArray || NULL == aFile)
	{
		return ;
	}

	fprintf(aFile, "{\n\"number\" : %d,\n\"count\" : %d,\n",
			anArray->number, anArray->count);
	fprintf(aFile, "\"Kvadrats\" : \n[\n");

	for (int i = 0; i < anArray->count; i ++)
	{
		writeKvadratToJSON(aFile, anArray->Kvadrats[i]);

		if (i < anArray->count - 1)
		{
			fprintf(aFile, ",");
		}
		fprintf(aFile, "\n");
	}

	fprintf(aFile, "]\n}");
}
