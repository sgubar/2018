#include "tool_array.h"
#include <stdlib.h>
#include "tool.h"


triangleArray *createArray(int aNumber)
{
	triangleArray *result = NULL;

	if(aNumber > 0)
	{
		result = (triangleArray *) malloc(sizeof(triangleArray));

		if(NULL != result)
		{
			result -> triangles = (triangle **) malloc(sizeof(triangle *)*aNumber);

			if(NULL != result -> triangles)
			{
				result -> number = aNumber;
				result -> count = 0;
			}
			else
			{
				free(result);
				result = NULL;
			}
		}
	}

	return result;
}

void freeArray(triangleArray *anArray)
{
	int i;
	if(NULL != anArray)
	{
		for (i = 0; i < anArray->count; i ++)
		{
			destroy_triangle(anArray -> triangles[i]);
		}

		free(anArray -> triangles);
		free(anArray);
	}
}


int addElement(triangleArray *anArray, triangle *atriangle)
{
	int result = -1;

	if(NULL != anArray && NULL != atriangle &&	anArray->count < anArray->number)
	{
		anArray -> triangles[anArray->count] = create_triangle(atriangle -> A, atriangle -> B, atriangle -> C);

		result = anArray -> count;
		anArray -> count ++;
	}

	return result;
}

void array_to_json(FILE *file, triangleArray *anArray)
{
	int i;
	if(NULL == anArray || NULL == file)
	{
		return ;
	}

	fprintf(file, "{\n\"number\" : %d,\n\"count\" : %d,\n", anArray -> number, anArray -> count);
	fprintf(file, "\"triangles\" : \n[\n");

	for(i = 0; i < anArray -> count; i ++)
	{
		triangle_to_json(file, anArray->triangles[i]);

		if(i < anArray->count - 1)
		{
			fprintf(file, ",");
		}
		fprintf(file, "\n");
	}

	fprintf(file, "]\n}");
}
