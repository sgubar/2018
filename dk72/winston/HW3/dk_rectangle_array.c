#include "dk_rectangle.h"
#include "dk_rectangle_array.h"

// init/dealloc
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
