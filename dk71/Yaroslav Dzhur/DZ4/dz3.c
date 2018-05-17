#include "dz3.h"
#include <stdlib.h>


TriangleArray *createArray(int aNumber)
{
	TriangleArray *theResult = NULL;

	if (aNumber > 0)
	{
		theResult = (TriangleArray *)malloc(sizeof(TriangleArray));

		if (NULL != theResult)
		{
			theResult->Triangles = (Triangle **)malloc(sizeof(Triangle *)*aNumber);

			if (NULL != theResult->Triangles)
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

void freeArray(TriangleArray *anArray)
{
	if (NULL != anArray)
	{
		int i;
		for (i = 0; i < anArray->count; i ++)
		{
			destroyTriangle(anArray->Triangles[i]);
		}

		free(anArray->Triangles);
		free(anArray);
	}
}

int addElement(TriangleArray *anArray, Triangle *aTriangle)
{
	int theResult = -1;

	if (NULL != anArray && NULL != aTriangle &&
				anArray->count < anArray->number)
	{
		anArray->Triangles[anArray->count] =
					createTriangle(aTriangle->A, aTriangle->B, aTriangle->C);

		theResult = anArray->count;
		anArray->count ++;
	}

	return theResult;
}

void writeArrayToJSON(FILE *aFile, TriangleArray *anArray)
{
	if (NULL == anArray || NULL == aFile)
	{
		return ;
	}

	fprintf(aFile, "{\n\"number\" : %d,\n\"count\" : %d,\n",
			anArray->number, anArray->count);
	fprintf(aFile, "\"Triangles\" : \n[\n");

	int i;
	for ( i = 0; i < anArray->count; i ++)
	{
		writeTriangleToJSON(aFile, anArray->Triangles[i]);

		if (i < anArray->count - 1)
		{
			fprintf(aFile, ",");
		}
		fprintf(aFile, "\n");
	}

	fprintf(aFile, "]\n}");
}

void writeTriangleToJSON(FILE *aFile, Triangle *aTriangle)
{
	if (NULL == aTriangle || NULL == aFile)
	{
		return ;
	}

	fprintf(aFile, "{\n\"A\" : ");
	writePointToJSON(aFile, aTriangle->A);
	fprintf(aFile, ", \n\"B\" : ");
	writePointToJSON(aFile, aTriangle->B);
	fprintf(aFile, ",\n\"C\" : ");
	writePointToJSON(aFile, aTriangle->C);
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
