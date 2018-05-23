#include "tool_array.h"
#include <stdlib.h>
#include "tool.h"


triangle_array *createArray(int aNumber)
{
	triangle_array *Result = NULL;

	if (aNumber > 0)
	{
		theResult = (triangle_array *)malloc(sizeof(triangle_array));
		theResult->flat = malloc(sizeof(float)*aNumber);
		if (NULL != theResult)
		{
			theResult->triangles = (triangle **)malloc(sizeof(triangle *)*aNumber);

			if (NULL != theResult->triangles)
			{
				theResult->number = aNumber;
				theResult->count = 0;
			}
			else
			{
				free(theResult);
				Result = NULL;
			}
		}
	}

	return theResult;
}


void free_array(triangle_array *anArray)
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


int add_element(triangle_array *anArray, triangle *atriangle, float flat)
{
	int theResult = -1;

	if (NULL != anArray && NULL != atriangle &&	anArray->count < anArray->number)
	{
		anArray->triangles[anArray->count] =
					create_triangle(atriangle->A, atriangle->B, atriangle->C);
		anArray-> flat[anArray->count] = flat;
		theResult = anArray->count;
		anArray->count ++;
	}

	return theResult;
}


void write_array_to_JSON(FILE *before, triangleArray *anArray)
{
	int i;
	if (NULL == anArray || NULL == before)
	{
		return ;
	}

	fprintf(before, "{\n\"number\" : %d,\n\"count\" : %d,\n",
			anArray->number, anArray->count);
	fprintf(before, "\"triangles\" : \n[\n");

	for (i = 0; i < anArray->count; i ++)
	{
		write_array_to_JSON(before, anArray->triangles[i]);

		if (i < anArray->count - 1)
		{
			fprintf(before, ",");
		}
		fprintf(before, "\n");
	}

	fprintf(before, "]\n}");
}


void insertion_sort(triangle_array *anArray)
{
   int i, key, j;
   for (i = 1; i < anArray->count; i++)
   {
       key = anArray->triangles[i];
       j = i-1;
		
       while (j >= 0 && anArray->triangles[i] > key)
       {
           anArray->triangles[j+1] = anArray->triangles[j];
           j = j-1;
       }
       anArray->triangles[j+1] = key;
   }
}


