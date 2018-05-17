#include "dk_triangle_array.h"
#include <stdlib.h>
#include "dk_triangle.h"


triangleArray *createArray(int aNumber)
{
	triangleArray *theResult = NULL;

	if (aNumber > 0)
	{
		theResult = (triangleArray *)malloc(sizeof(triangleArray));
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
				theResult = NULL;
			}
		}
	}

	return theResult;
}

void freeArray(triangleArray *anArray)
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


int addElement(triangleArray *anArray, triangle *atriangle, float flat)
{
	int theResult = -1;

	if (NULL != anArray && NULL != atriangle &&	anArray->count < anArray->number)
	{
		anArray->triangles[anArray->count] =
					create_triangle(atriangle->A, atriangle->B, atriangle->C);
		anArray->flat[anArray->count] = flat;
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
	fprintf(aFile, "\"triangles\" : \n[\n");

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


int line_search(triangleArray *anArray, float key)
{
	int i;
	int pos;
    for(i = 0; i < anArray->count; i++)
    {
         if (flat_triangle(anArray->triangles[i]) == key)
        {
		printf("\n\n\tFIND!\n");
		pos=i;
		return pos+1;
		}
    }	
    return -1;
}



void quick_sort(triangleArray *anArray, int first, int last)
{
int mid, left, right;
	
  left = first;
  right = last;
  
  mid = anArray->flat[(left + right) / 2];
  while (left <= right)
  {
    while (anArray->flat[left] < mid) left++;
      
    while (anArray->flat[right] > mid) right--;
      
    if (left <= right)
	{
        swap(&anArray->triangles[left], &anArray->triangles[right]);
        left++;
        right--;
	}
  }
  if (first < right) quick_sort(anArray, first, right);
    
  if (left < last) quick_sort(anArray, left, last);
    
}


void swap(int *one, int *two)
{
	int three = *one;
	*one = *two;
	*two = three;
}

