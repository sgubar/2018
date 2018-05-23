#include "Dz_5_search.h"
#include <stdlib.h>

KvadratArray *createArray(int aNumber)
{
	KvadratArray *theResult = NULL;

	if (aNumber > 0)
	{
		theResult = (KvadratArray *)malloc(sizeof(KvadratArray));

		if (NULL != theResult)
		{
			theResult->Kvadrats = (Kvadrat **)malloc(sizeof(Kvadrat *)*aNumber);
			theResult->IndKvadrat = malloc(sizeof(float)*aNumber);

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
		int i;
		for (i = 0; i < anArray->count; i ++)
		{
			destroyKvadrat(anArray->Kvadrats[i]);
		}

		free(anArray->Kvadrats);
		free(anArray);
	}
}

int addElement(KvadratArray *anArray, Kvadrat *aKvadrat, float Ind)
{
	int theResult = -1;

	if (NULL != anArray && NULL != aKvadrat &&
				anArray->count < anArray->number)
	{
		anArray->Kvadrats[anArray->count] =
					createKvadrat(aKvadrat->A, aKvadrat->B, aKvadrat->C,aKvadrat->D);
		anArray->IndKvadrat[anArray->count] = Ind;

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
	fprintf(aFile, "\"Squares\" : \n[\n");
	int i;
	for (i = 0; i < anArray->count; i ++)
	{
		writeSquareToJSON(aFile, anArray->Kvadrats[i]);

		if (i < anArray->count - 1)
		{
			fprintf(aFile, ",");
		}
		fprintf(aFile, "\n");
	}

	fprintf(aFile, "]\n}");
}




void shellSort(KvadratArray *anArray)
{
	int theInner = 0;
	int theOuter = 0;
	int theH = 1; 

	while (theH <= anArray->count/3)
	{
		theH = theH*3 + 1; // 1, 4, 13, 40, 121, ....
	}

	float temp;
	while (theH > 0)
	{
		for (theOuter = theH; theOuter < anArray->count; theOuter ++)
		{
			Kvadrat *theTmp = anArray->Kvadrats[theOuter];
			temp = anArray->IndKvadrat[theOuter];
			theInner = theOuter;

			while (theInner > theH-1 && anArray->IndKvadrat[theInner - theH] >= temp)
			{
				anArray->Kvadrats[theInner] = anArray->Kvadrats[theInner - theH];
				anArray->IndKvadrat[theInner] = anArray->IndKvadrat[theInner - theH];
				theInner -= theH;
			}
			anArray->IndKvadrat[theInner] = temp;
			anArray->Kvadrats[theInner] = theTmp;
		}

		theH = (theH - 1) / 3; 
	}
}
int linear_search(KvadratArray *anArray, float key)
{
	int i;
    for (i = 0; i < anArray->count; i++)
    {
        if (anArray->IndKvadrat[i] == key)
        return i+1;

    }

    return -1;

}
void printArray(KvadratArray *anArray)
{
	if (NULL != anArray)
	{
		int i;
		for(i=0 ; i< anArray->count ; i++){
			printf ("[Square%d]. A(%d,%d) - B(%d,%d)- C(%d,%d)- D(%d,%d)\n", i+1,
					anArray->Kvadrats[i]->A->x, anArray->Kvadrats[i]->A->y,
					anArray->Kvadrats[i]->B->x, anArray->Kvadrats[i]->B->y,
					anArray->Kvadrats[i]->C->x, anArray->Kvadrats[i]->C->y,
					anArray->Kvadrats[i]->D->x, anArray->Kvadrats[i]->D->y);
		}
	} 
}
