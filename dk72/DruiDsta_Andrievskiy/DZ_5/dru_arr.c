#include "dru_arr.h"

triangleArray *createArray(int aNumber)
{
	triangleArray *theResult = NULL;

	if (aNumber > 0)
	{
		theResult =(triangleArray *)malloc(sizeof(triangleArray));
		theResult->aTriangles = malloc(sizeof(triangle)*aNumber);
		if (NULL != theResult)
		{
			theResult->aTriangles = (triangle **)malloc(sizeof(triangle *)*aNumber);

			if (NULL != theResult->aTriangles)
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
			destroy_triangle(anArray->aTriangles[i]);
		}

		free(anArray->aTriangles);
		free(anArray);
	}
}


int addElement(triangleArray *anArray, triangle *atriangle)
{
	int theResult = -1;

	if (NULL != anArray && NULL != atriangle &&	anArray->count < anArray->number)
	{
		anArray->aTriangles[anArray->count]=create_triangle(atriangle->A, atriangle->B, atriangle->C);
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

	fprintf(aFile, "{\n\"number\" : %d,\n\"count\" : %d,\n", anArray->number, anArray->count);
	fprintf(aFile, "\"triangles\" : \n[\n");

	for (i = 0; i < anArray->count; i ++)
	{
		writetriangleToJSON(aFile, anArray->aTriangles[i]);

		if (i < anArray->count - 1)
		{
			fprintf(aFile, ",");
		}
		fprintf(aFile, "\n");
	}

	fprintf(aFile, "]\n}");
}


void bubble_sort(triangleArray *anArray)
{
	int theIn, theOut;
	printf("Sorting...\n\n");
	
	for (theOut = anArray->number - 1; theOut>=1; theOut--)
	{
		for (theIn=0; theIn<theOut; theIn++)
		{
			if (anArray->aTriangles[theIn]->S > anArray->aTriangles[theIn + 1]->S)	
			{
				triangle *temp = anArray->aTriangles[theIn];
    			anArray->aTriangles[theIn] = anArray->aTriangles[theIn + 1];
   				anArray->aTriangles[theIn + 1] = temp;
   				
			}
		}
	}
	printf("\n");
}

void shell_sort(triangleArray *anArray)
{
	int theInner, theOuter, theH = 1;
	
	printf("Sorting...\n\n");
	
	//	#1
	while (theH <= anArray->number/3)
	{
		theH = theH*3 + 1;
	}
	
	//	#2
	while (theH > 0)
	{
		for (theOuter = theH; theOuter < anArray->number; theOuter ++)
		{
			triangle *theTmp = anArray->aTriangles[theOuter];
			theInner = theOuter;
		
			while (theInner > theH-1 && anArray->aTriangles[theInner - theH]->S >= theTmp->S)
			{
				anArray->aTriangles[theInner] = anArray->aTriangles[theInner - theH];
				theInner -= theH;
			}
		
			anArray->aTriangles[theInner] = theTmp;
		}
	
		theH = (theH - 1) / 3;
	}
}

int search(triangleArray *anArray)
{
	float key;
	int i;
	printf("Enter search key: ");
	scanf("%f",&key);
	printf("Search...\n\n");
	
	for(i=0; i!=anArray->count; i++)
	{
		if(anArray->aTriangles[i]->S == key)
		{
			printf("Count array: %d\n", i);
			return i;
		}
	}
	printf("The desired value is not found!\n");
	return -1;
}
