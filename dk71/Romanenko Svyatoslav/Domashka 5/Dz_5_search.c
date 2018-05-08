#include "Dz_5_search.h"
#include <stdlib.h>

SquareArray *createArray(int aNumber)
{
	SquareArray *theResult = NULL;

	if (aNumber > 0)
	{
		theResult = (SquareArray *)malloc(sizeof(SquareArray));

		if (NULL != theResult)
		{
			theResult->Squares = (Square **)malloc(sizeof(Square *)*aNumber);
			theResult->areaSquare = malloc(sizeof(float)*aNumber);

			if (NULL != theResult->Squares)
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

void freeArray(SquareArray *anArray)
{
	if (NULL != anArray)
	{
		int i;
		for (i = 0; i < anArray->count; i ++)
		{
			destroySquare(anArray->Squares[i]);
		}

		free(anArray->Squares);
		free(anArray);
	}
}

int addElement(SquareArray *anArray, Square *aSquare, float area)
{
	int theResult = -1;

	if (NULL != anArray && NULL != aSquare &&
				anArray->count < anArray->number)
	{
		anArray->Squares[anArray->count] =
					createSquare(aSquare->A, aSquare->B, aSquare->C,aSquare->D);
		anArray->areaSquare[anArray->count] = area;

		theResult = anArray->count;
		anArray->count ++;
	}

	return theResult;
}

void writeArrayToJSON(FILE *aFile, SquareArray *anArray)
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
		writeSquareToJSON(aFile, anArray->Squares[i]);

		if (i < anArray->count - 1)
		{
			fprintf(aFile, ",");
		}
		fprintf(aFile, "\n");
	}

	fprintf(aFile, "]\n}");
}




void shellSort(SquareArray *anArray)
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
			Square *theTmp = anArray->Squares[theOuter];
			temp = anArray->areaSquare[theOuter];
			theInner = theOuter;

			while (theInner > theH-1 && anArray->areaSquare[theInner - theH] >= temp)
			{
				anArray->Squares[theInner] = anArray->Squares[theInner - theH];
				anArray->areaSquare[theInner] = anArray->areaSquare[theInner - theH];
				theInner -= theH;
			}
			anArray->areaSquare[theInner] = temp;
			anArray->Squares[theInner] = theTmp;
		}

		theH = (theH - 1) / 3; 
	}
}
int linear_search(SquareArray *anArray, float key)
{
	int i;
    for (i = 0; i < anArray->count; i++)
    {
        if (anArray->areaSquare[i] == key)
        return i+1;

    }

    return -1;

}
void printArray(SquareArray *anArray)
{
	if (NULL != anArray)
	{
		int i;
		for(i=0 ; i< anArray->count ; i++){
			printf ("[Square%d]. A(%d,%d) - B(%d,%d)- C(%d,%d)- D(%d,%d)\n", i+1,
					anArray->Squares[i]->A->x, anArray->Squares[i]->A->y,
					anArray->Squares[i]->B->x, anArray->Squares[i]->B->y,
					anArray->Squares[i]->C->x, anArray->Squares[i]->C->y,
					anArray->Squares[i]->D->x, anArray->Squares[i]->D->y);
		}
	} 
}
