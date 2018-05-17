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
	


void swap(int *a, int *b)
	{
	    int t = *a;
	    *a = *b;
	    *b = t;
	}
	
int partition(TriangleArray *anArray, int low, int high)
	{	
		int j;
	    int pivot = anArray->square[high];   
	    int i = (low - 1);  
	 
	    for ( j = low; j <= high - 1; j++)
		    {
	
		        if (anArray->square[j] <= pivot)              // here
		        {
		            i++;    
		            swap(&anArray->Triangles[i], &anArray->Triangles[j]);
		        }
		    }
	    swap(&anArray->Triangles[i + 1], &anArray->Triangles[high]);
	    return (i + 1);
	}

void quickSort(TriangleArray *anArray, int low, int high)
	{
	    if (low < high)
	    {
	        int pi = partition(anArray, low, high);
	        quickSort(anArray, low, pi - 1);
	        quickSort(anArray, pi + 1, high);
	    }
	}			
	
	
	
void lineSearch(TriangleArray *anArray, float key)
	{
		int i, result = 0;
	    for(i = 0; i < anArray->count; i++)
		    {
		         if (squareTriangle(anArray->Triangles[i]) == key)
			        	result = 1;
					
		    }
		if ( result == 1 ) printf("yes");
			else printf("nonon");
	}	
	
	
