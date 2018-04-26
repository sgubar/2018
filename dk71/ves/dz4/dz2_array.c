#include "dz2_array.h"
#include <stdlib.h>
#include "dz2.h"

RactangleArray *createArray(int aNumber)
{
	RactangleArray *theResult = NULL;

	if (aNumber > 0)
	{
		theResult = (RactangleArray *)malloc(sizeof(RactangleArray));

		if (NULL != theResult)
		{
			theResult->ractangles = (Ractangle **)malloc(sizeof(Ractangle *)*aNumber);
			if (NULL != theResult->ractangles)
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

void freeArray(RactangleArray *anArray)
{
	if (NULL != anArray)
	{
		int i;
		for (i = 0; i< anArray->count; i++)
		{
			destroyRactangle(anArray->ractangles[i]);
		}

		free(anArray->ractangles);
		free(anArray);
	}
}

int addElement(RactangleArray *anArray, Ractangle *aRactangle)
{
	int theResult = -1;

	if (NULL != anArray && NULL != aRactangle && anArray->count < anArray->number)
	{
		anArray->ractangles[anArray->count] = createRactangle(aRactangle->A, aRactangle->B, aRactangle->C, aRactangle->D);

		theResult = anArray->count;
		anArray->count++;
	}
	return theResult;
}

//json format
void writeRactangleToJSON(FILE *aFile, Ractangle *aRactangle)
{
	if (NULL == aRactangle || NULL == aFile)
	{
		return;
	}

	fprintf(aFile, "{\n\"A\" : ");
	writePointToJSON(aFile, aRactangle->A);
	fprintf(aFile, ",\n\"B\" : ");
	writePointToJSON(aFile, aRactangle->B);
	fprintf(aFile, ",\n\"C\" : ");
	writePointToJSON(aFile, aRactangle->C);
	fprintf(aFile, ", \n\"D\" : ");
	writePointToJSON(aFile, aRactangle->D);
	fprintf(aFile, "\n}");
}

void writePointToJSON(FILE *aFile, Point *aPoint)
{
	if (NULL == aPoint || NULL == aFile)
	{
		return;
	}

	fprintf(aFile, "{\"x\" : %d, \"y\" : %d}", aPoint->x, aPoint->y);
}

void writeArrayToJSON(FILE *aFile, RactangleArray *anArray)
{
	if (NULL == anArray || NULL == aFile)
	{
		return;
	}

	fprintf(aFile, "{\n\"number\" : %d,\n\"count\" : %d,\n",
		anArray->number, anArray->count);
	fprintf(aFile, "\"ractangles\" : \n[\n");

	int i;
	for (i = 0; i < anArray->count; i++)
	{
		writeRactangleToJSON(aFile, anArray->ractangles[i]);

		if (i < anArray->count - 1)
		{
			fprintf(aFile, ",");
		}
		fprintf(aFile, "\n");
	}

	fprintf(aFile, "]\n}");
}
