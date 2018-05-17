#include <stdio.h>
#include "dk_rectangle.h"
#include "dk_rectangle_array.h"


RectangleArray *createArray(int aNumber)
{
	RectangleArray *theResult = NULL;

	if (aNumber > 0)
	{
		theResult = (RectangleArray *)malloc(sizeof(RectangleArray));

		if (NULL != theResult)
		{
			theResult->Rectangles = (Rectangle **)malloc(sizeof(Rectangle *)*aNumber);

			if (NULL != theResult->Rectangles)
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

void freeArray(RectangleArray *anArray)
{
	if (NULL != anArray)
	{
		for (int i = 0; i < anArray->count; i ++)
		{
			destroyRectangle(anArray->Rectangles[i]);
		}

		free(anArray->Rectangles);
		free(anArray);
	}
}

int addElement(RectangleArray *anArray, Rectangle *aRectangle)
{
	int theResult = -1;

	if (NULL != anArray && NULL != aRectangle &&
				anArray->count < anArray->number)
	{
		anArray->Rectangles[anArray->count] =
					createRectangle(aRectangle->A, aRectangle->B, aRectangle->C,aRectangle->D);

		theResult = anArray->count;
		anArray->count ++;
	}

	return theResult;
}

void writeArrayToJSON(FILE *aFile, RectangleArray *anArray)
{
	if (NULL == anArray || NULL == aFile)
	{
		return ;
	}

	fprintf(aFile, "{\n\"number\" : %d,\n\"count\" : %d,\n",
			anArray->number, anArray->count);
	fprintf(aFile, "\"Rectangles\" : \n[\n");

	for (int i = 0; i < anArray->count; i ++)
	{
		writeRectangleToJSON(aFile, anArray->Rectangles[i]);

		if (i < anArray->count - 1)
		{
			fprintf(aFile, ",");
		}
		fprintf(aFile, "\n");
	}

	fprintf(aFile, "]\n}");
}

void quickSort( RectangleArray *anArray, int l, int r)
{
   int j;

   if( l < r )
   {
       j = partition( anArray, l, r);
       quickSort( anArray, l, j-1);
       quickSort( anArray, j+1, r);
   }

}

int partition(RectangleArray *anArray, int l, int r)
{
   int i, j;
   Rectangle *t;
   int pivot = areaRectangle(anArray->Rectangles[l]);
   i = l; j = r+1;

   while( 1)
   {
   	do ++i; while( areaRectangle(anArray->Rectangles[i]) <= pivot && i <= r );
   	do --j; while( areaRectangle(anArray->Rectangles[j]) > pivot );
   	if( i >= j ) break;
   	t = anArray->Rectangles[i]; anArray->Rectangles[i] = anArray->Rectangles[j]; anArray->Rectangles[j] = t;
   }
   t = anArray->Rectangles[l]; anArray->Rectangles[l] = anArray->Rectangles[j]; anArray->Rectangles[j] = t;
   return j;
}


int binarysearch(int a, RectangleArray *anArray, int n)
{
    int low, high, middle;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        middle = (low + high) / 2;
        if (a < areaRectangle(anArray->Rectangles[middle]))
            high = middle - 1;
        else if (a > areaRectangle(anArray->Rectangles[middle]))
            low = middle + 1;
        else
            return middle;
    }
    return -1;
}
