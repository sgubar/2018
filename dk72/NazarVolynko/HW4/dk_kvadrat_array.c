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
			theResult->ploschaKvadrat = malloc(sizeof(float)*aNumber);

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
int addElement(KvadratArray *anArray, Kvadrat *aKvadrat, float ploscha)
{
	int theResult = -1;

	if (NULL != anArray && NULL != aKvadrat &&
				anArray->count < anArray->number)
	{
		anArray->Kvadrats[anArray->count] =
					createKvadrat(aKvadrat->A, aKvadrat->B, aKvadrat->C,aKvadrat->D);
		anArray->ploschaKvadrat[anArray->count] = ploscha;

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

void sort_bulbashka(KvadratArray *anArray)
{
  for(int k = 0; k < anArray->count ; k++)
  {
    int swaps = 0;
    for(int i = 0; i < anArray->count ; i++)
      {
        if(anArray->ploschaKvadrat[i] > anArray->ploschaKvadrat[i+1])
        {
          Kvadrat *temp =anArray->Kvadrats[i+1];
          anArray->Kvadrats[i+1] = anArray->Kvadrats[i];
          anArray->Kvadrats[i] = temp;
          swaps++;
        }
      }
    if(!swaps)
      break;
  }
}

void sort_vstavka(KvadratArray *anArray)
{
    Kvadrat *newElement=NULL;
    int  location;

    for (int i = 1; i < anArray->count; i++)
    {
        newElement = anArray->Kvadrats[i];
        location = i - 1;
        while(location >= 0 && anArray->ploschaKvadrat[location] > anArray->ploschaKvadrat[i])
        {
            anArray->Kvadrats[location+1] = anArray->Kvadrats[location];
            location = location - 1;
        }
        anArray->Kvadrats[location+1] = newElement;
    }
}
//functsia dlz perevirky(dopomigna)
void printKvadrat(Kvadrat *aKvadrat)
{
	if (NULL != aKvadrat)
	{
		printf ("[Kvadrat]. A(%d,%d) - B(%d,%d)- C(%d,%d)- D(%d,%d)\n\n",
					aKvadrat->A->x, aKvadrat->A->y,
					aKvadrat->B->x, aKvadrat->B->y,
					aKvadrat->C->x, aKvadrat->C->y,
					aKvadrat->D->x, aKvadrat->D->y);
	}
}
