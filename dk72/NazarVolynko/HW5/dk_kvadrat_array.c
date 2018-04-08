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



void quickSort( KvadratArray *anArray, int l, int r)
{
   int j;

   if( l < r )
   {
   	// divide and conquer
       j = partition( anArray, l, r);
       quickSort( anArray, l, j-1);
       quickSort( anArray, j+1, r);
   }

}

int partition(KvadratArray *anArray, int l, int r)
{
   int i, j;
   Kvadrat *t;
   int pivot = ploschaKvadrat(anArray->Kvadrats[l]);
   i = l; j = r+1;

   while( 1)
   {
   	do ++i; while( ploschaKvadrat(anArray->Kvadrats[i]) <= pivot && i <= r );
   	do --j; while( ploschaKvadrat(anArray->Kvadrats[j]) > pivot );
   	if( i >= j ) break;
   	t = anArray->Kvadrats[i]; anArray->Kvadrats[i] = anArray->Kvadrats[j]; anArray->Kvadrats[j] = t;
   }
   t = anArray->Kvadrats[l]; anArray->Kvadrats[l] = anArray->Kvadrats[j]; anArray->Kvadrats[j] = t;
   return j;
}

int linijnyj_poshuk(KvadratArray *anArray, float key)
{
    for (int i = 0; i < anArray->count; i++)
    {
        if (ploschaKvadrat(anArray->Kvadrats[i]) == key)
        return i+1;

    }

    return -1;

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
