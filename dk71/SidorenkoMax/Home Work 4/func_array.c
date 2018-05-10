#include "func_array.h"
#include <stdlib.h>


TriangleArray *createArray(int aNumber)
	{
		TriangleArray *theResult = NULL;
		
		if ( aNumber > 0 )
			{
				theResult = (TriangleArray *)malloc(sizeof(TriangleArray));
				theResult->square = malloc(sizeof(float)*aNumber);
				if (NULL != theResult)
					{
						theResult->Triangles = (Triangle **)malloc(sizeof(Triangle *)* aNumber);
						
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
		int i;
		if (NULL != anArray)
			{
				for ( i = 0; i < anArray->count; i ++)
					{
						destroyTriangle(anArray->Triangles[i]);
					}
					
				free(anArray->Triangles);
				free(anArray);
			}
	}
	
int addElement(TriangleArray *anArray, Triangle *aTriangle, float square)
	{
		int theResult = -1;
		
		if (NULL != anArray && NULL != aTriangle && anArray->count < anArray->number)
			{
				anArray->Triangles[anArray->count] = createTriangle(aTriangle->A, aTriangle->B, aTriangle->C);
				anArray-> square[anArray->count] 	=  square;
				theResult = anArray->count;
				anArray->count ++;
			}
			
		return theResult;
	}
	
void writeArrayToJSON(FILE *aFile, TriangleArray *anArray)
	{	
		int i=0;
		if (NULL == anArray || NULL == aFile)
			{
				return ;
			}
		fprintf(aFile, "{\n\"number\" : %d,\n\"count\" : %d,\n",anArray->number, anArray->count);
		fprintf(aFile, "\"triangles\" : \n[\n");
		
		for ( i = 0; i < anArray->count; i++)
			{
				writeTriangleToJSON(aFile, anArray->Triangles[i]);
				
				if( i < anArray->count - 1)
					{
						fprintf(aFile, ",");
					}
				fprintf(aFile, "\n");
			}
		fprintf(aFile, "],\n}");
	}
	
	
void InsertionSort(TriangleArray *anArray)
	{
	    Triangle *newElement = NULL;
	    int location;
		int j;
	    for (j = 1; j < anArray->count; j++)
	    {
	        newElement = anArray->Triangles[j];
	        location = j - 1;
	        while(location >= 0 && anArray->square[location] > anArray->square[j])
	        {
	            anArray->Triangles[location+1] = anArray->Triangles[location];
	            location = location - 1;
	        }
	        anArray->Triangles[location+1] = newElement;
	    }
	}
	
