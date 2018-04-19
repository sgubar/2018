#include <stdio.h>
#include <stdlib.h>
#include "sqere_Array.h"


ArraySqere *createArray(int Number) {
	
	ArraySqere *result = NULL;
	
	if (Number > 0)	{
		result = (ArraySqere *)malloc(sizeof(ArraySqere));
			if (NULL != result)
		{
			result->sqere = (Sqere **)malloc(Number*sizeof(Sqere *));
		
			if (NULL != result->sqere)
			{
				result->number = Number;
				result->counter = 0;
				
			}
			else
			{
				free(result);
				result = NULL;
			}
		}
	}
	
	
	return result;}
	
	int addElement(ArraySqere *array, Sqere *sqere)
{
	int result = -1;
	
	if (NULL != array && NULL != sqere && array->counter < array->number)
	{
		array->sqere[array->counter] = create_sqere(sqere->A,sqere->B,sqere->C,sqere->D);
	
		result = array->counter;
		array->counter ++;
	
	}
	
	return result;
}
	void wrireToJSON(FILE *file, ArraySqere *array)
{ 
	int i;
	if (NULL == array || NULL == file)
	{
		printf("Error");
		
	}
	
	fprintf(file, "{\n\"number\" : %d,\n\"counter\" : %d,\n",
			array->number, array->counter);
	fprintf(file, "\"squares\" : \n[\n");
	
	for (i=0;i<array->counter;i++)
	{
		
		fprintf(file,"{ \n");
		fprintf(file,"\"A\": {\"x\":%d,\"y\":%d},\n",array->sqere[i]->A->x,array->sqere[i]->A->y);
			fprintf(file,"\"B\": {\"x\":%d,\"y\":%d},\n",array->sqere[i]->B->x,array->sqere[i]->B->y);
				fprintf(file,"\"C\": {\"x\":%d,\"y\":%d},\n",array->sqere[i]->C->x,array->sqere[i]->C->y);
					fprintf(file,"\"D\": {\"x\":%d,\"y\":%d}\n",array->sqere[i]->D->x,array->sqere[i]->D->y);
						fprintf(file,"}");
		if (i < array->counter - 1)
		{
			fprintf(file, ",");
		}
		fprintf(file, "\n");
	}
	
	fprintf(file, "]\n}");
}


void freeArray(ArraySqere *array)
{
	int i;
	if (NULL != array)
	{
		for (i=0;i< array->counter;i++)
		{
			free_all(array->sqere[i]);
		}
	
		free(array->sqere);
		free(array);
	}
}
