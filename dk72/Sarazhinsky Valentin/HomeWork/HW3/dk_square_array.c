#include "dk_square_array.h"
#include <stdlib.h>

// init/dealloc
SquareArray *createArray(int aNumber)
{
	SquareArray *theResult = NULL;
	
	if (aNumber > 0)
	{
		theResult = (SquareArray *)malloc(sizeof(SquareArray));
	
		if (NULL != theResult)
		{
			theResult->squares = (Square **)malloc(sizeof(Square *)*aNumber);
		
			if (NULL != theResult->squares)
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
	int i = 0;
	if (NULL != anArray)
	{
		for (i = 0; i < anArray->count; i ++)
		{
			destroySquare(anArray->squares[i]);
		}
	
		free(anArray->squares);
		free(anArray);
	}
}

//interface
//returns index of added element OR -1 if fail
int addElement(SquareArray *anArray, Square *aSquare)
{
	int theResult = -1;
	
	if (NULL != anArray && NULL != aSquare &&
				anArray->count < anArray->number)
	{
		anArray->squares[anArray->count] =
					createSquare(aSquare->A, aSquare->B);
	
		theResult = anArray->count;
		anArray->count ++;
	}
	
	return theResult;
}

void writeArrayToJSON(FILE *aFile, SquareArray *anArray)
{
	int i;
	if (NULL == anArray || NULL == aFile)
	{
		return ;
	}
	
	fprintf(aFile, "{\n\"number\" : %d,\n\"count\" : %d,\n",
			anArray->number, anArray->count);
	fprintf(aFile, "\"lines\" : \n[\n");
	
	for (i = 0; i < anArray->count; i ++)
	{
		writeSquareToJSON(aFile, anArray->squares[i]);
	
		if (i < anArray->count - 1)
		{
			fprintf(aFile, ",");
		}
		fprintf(aFile, "\n");
	}
	
	fprintf(aFile, "],\n}");
}
