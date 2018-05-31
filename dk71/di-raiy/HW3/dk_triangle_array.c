#include "dk_triangle_array.h"
#include <stdlib.h>
#include "dk_triangle2.h"


triangleArray *createArray(int aNumber)
{
	triangleArray *theResult = NULL;

	if (aNumber > 0)
	{
		theResult = (triangleArray *)malloc(sizeof(triangleArray));

		if (NULL != theResult)
		{
			theResult->triangles = (triangle_t **)malloc(sizeof(triangle_t *)*aNumber);

			if (NULL != theResult->triangles)
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

void destroyA(triangleArray *anArray)
{
	int i;
	if (NULL != anArray)
	{
		for (i = 0; i < anArray->count; i ++)
		{
			destroy_triangle(anArray->triangles[i]);
		}

		free(anArray->triangles);
		free(anArray);
	}
}


int addElement(triangleArray *anArray, triangle_t *atriangle)
{
	int theResult = -1;

	if (NULL != anArray && NULL != atriangle &&	anArray->count < anArray->number)
	{
		anArray->triangles[anArray->count] =
					create_triangle(atriangle->A, atriangle->B, atriangle->C);

		theResult = anArray->count;
		anArray->count ++;
	}

	return theResult;
}

void writeArrayToJSON(FILE *aFile, triangleArray *anArray)
{
	int i;
	if (NULL == anArray || NULL == aFile)
	{
		return ;
	}

	fprintf(aFile, "{\n\"number\" : %d,\n\"count\" : %d,\n",
    anArray->number, anArray->count);
    if(anArray->count  > 1)
        fprintf(aFile, "\"triangles\" : \n[\n");
	else if(anArray->count == 1)
        fprintf(aFile, "\"triangle\" : \n[\n");



	for (i = 0; i < anArray->count; i ++)
	{
		writetriangleToJSON(aFile, anArray->triangles[i]);

		if (i < anArray->count - 1)
		{
			fprintf(aFile, ",");
		}
		fprintf(aFile, "\n");
	}

	fprintf(aFile, "]\n}");
}
