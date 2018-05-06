#include "dk_square_array.h"
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


void sort_vstavka(SquareArray *anArray)
{
    Square *newElement=NULL;
    int  location,i;
	
    for (i = 1; i < anArray->count; i++)
    {
        newElement = anArray->Squares[i];
        location = i - 1;
        while(location >= 0 && anArray->areaSquare[location] > anArray->areaSquare[i])
        {
            anArray->Squares[location+1] = anArray->Squares[location];
            location = location - 1;
        }
        anArray->Squares[location+1] = newElement;
    }
}

void sort_vybora(SquareArray *anArray)
{
    Square *temp=NULL;
    int dopomigna,i,j;
    float minArea;
    for(i = 0; i < anArray->count; ++i)
    {
        dopomigna = i;
        temp = anArray->Squares[i];
        minArea = anArray->areaSquare[i];
        for(j = i + 1; j < anArray->count; ++j)
        {
            if (anArray->areaSquare[j] < minArea)
            {
               dopomigna = j;
               temp = anArray->Squares[j];
               minArea = anArray->areaSquare[j];
            }
        }
        anArray->Squares[dopomigna] = anArray->Squares[i];
        anArray->areaSquare[dopomigna] = anArray->areaSquare[i];
        anArray->Squares[i] = temp;
        anArray->areaSquare[i] = minArea;
    }
}
void printSquare(Square *aSquare)
{
	if (NULL != aSquare)
	{
		printf ("[Square]. A(%d,%d) - B(%d,%d)- C(%d,%d)- D(%d,%d)\n\n",
					aSquare->A->x, aSquare->A->y,
					aSquare->B->x, aSquare->B->y,
					aSquare->C->x, aSquare->C->y,
					aSquare->D->x, aSquare->D->y);
	}
}
