#include "dk_tool.h"
#include <stdlib.h>
Triangle *createTriangle(Point *A, Point *B, Point *C)
{
    Triangle *theResult = NULL;
    
    if(A != NULL && B != NULL && C != NULL)
    {
        if(abs(A->y) == abs(C->y) && abs(C->x) == abs(B->x))         //Check if correct of our figure
        {
            theResult = ( Triangle* )malloc(sizeof(Triangle));  //Allocating memory
            
            if(theResult != NULL)
            {
                theResult->A = copyPointWithPoint(A);
                theResult->B = copyPointWithPoint(B);
                theResult->C = copyPointWithPoint(C);
            }
        }
        
    }
    return theResult;
}

void destroyTriangle(Triangle *aTriangle)
{
    if(aTriangle != NULL)            //Checking for valid point
    {
        free(aTriangle->A);            //We are freeing memory
        free(aTriangle->B);
        free(aTriangle->C);
        free(aTriangle);
    }
}

int AreaOfTriangle(Triangle *aTriangle)
{
    int theResult = 0;
    
    if(aTriangle != NULL)
    {
        int FirstSide = (float)sqrt(pow(aTriangle->B->x - aTriangle->C->x, 2) + pow(aTriangle->B->y - aTriangle->C->y, 2));
        int SecondSide = (float)sqrt(pow(aTriangle->A->x - aTriangle->C->x, 2) + pow(aTriangle->A->y - aTriangle->C->y, 2));
        
        
        
        
        theResult = (FirstSide * SecondSide) / 2;                                //calculation of area of triangle
    }
    
    return theResult;
}

Point *copyPointWithPoint(Point *aPoint)
{
    Point *theResult = (Point *)malloc(sizeof(Point));
    if (NULL != theResult)
    {
        theResult->x = aPoint->x;
        theResult->y = aPoint->y;
    }
    
    return theResult;
}

void writePointToJSON(FILE *aFile, Point *aPoint)
{
    if (NULL == aPoint || NULL == aFile)
    {
        return ;
    }
    
    fprintf(aFile, "{\"x\" : %d, \"y\" : %d}", aPoint->x, aPoint->y);
}


void writeFileToJSON(FILE *aFile, Triangle *aTriangle)
{
    if (NULL == aTriangle|| NULL == aFile)
    {
        return ;
    }
    
    fprintf(aFile, "{\n\"A\" : ");
    writePointToJSON(aFile, aTriangle->A);
    fprintf(aFile, ", \n\"B\" : ");
    writePointToJSON(aFile, aTriangle->B);
    fprintf(aFile, ", \n\"C\" : ");
    writePointToJSON(aFile, aTriangle->C);
    fprintf(aFile, ", \n\"Area\" : %f,", AreaOfTriangle(aTriangle));
    fprintf(aFile, "\n}");
}



void Bubble_Sort(int anArray[], int aSize) 
{
	for (i = aSize - 1; i > 1; i --)
	{
		for (j = 0; j < i; j ++)
		{
			if (anArray[j] > anArray[j + 1])
			{
				int theTmp = anArray[j];
				anArray[j] = anArray[j + 1];
				anArray[j + 1] = theTmp;
			}
		}
	}
}

void quickSort( ArrayOfTriangle *anArray, int l, int r)
{
   int j;

   if( l < r )
   {
   	// divide and conquer
       j = partition( anArray, l, r);
       quickSort( anArray, l, j-1);
       quickSort( anArray, j+1, r);
   }

}

int partition(ArrayOfTriangle *anArray, int l, int r)
{
   int i, j;
   Triangle *t;
   int pivot = AreaOfTriangle(anArray->Triangles[l]);
   i = l; j = r+1;

   while( 1)
   {
   	do ++i; while( AreaOfTriangle(anArray->Triangles[i]) <= pivot && i <= r );
   	do --j; while( AreaOfTriangle(anArray->Triangles[j]) > pivot );
   	if( i >= j ) break;
   	t = anArray->Triangles[i]; anArray->Triangles[i] = anArray->Triangles[j]; anArray->Triangles[j] = t;
   }
   t = anArray->Triangles[l]; anArray->Triangles[l] = anArray->Triangles[j]; anArray->Triangles[j] = t;
   return j;
}

int binary_find(ArrayOfTriangle *theArray, int search)
{
	int i, left, right;
	left = 0; right = theArray->count-1;
	while (1)
 	{
  	  if (left > right) return (-1);
  	  i = left + (right - left) / 2;
  	  if (AreaOfTriangle(theArray->Triangles[i]) < search) left = i + 1;
   	 if (AreaOfTriangle(theArray->Triangles[i]) > search) right = i - 1;
   	 if (AreaOfTriangle(theArray->Triangles[i]) == search) return i+1;
 	}

}
