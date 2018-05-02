#include <stdio.h>
#include <stdlib.h>
#include "func.h"

Point *copyPointWithPoint(Point *aPoint);

Triangle *createTriangle(Point *A, Point *B, Point *C)
	{
		Triangle *theResult = NULL;
		
			theResult = (Triangle *)malloc(sizeof(Triangle));
			if (NULL != theResult)
				{
					theResult->A = copyPointWithPoint(A);
					theResult->B = copyPointWithPoint(B);
					theResult->C = copyPointWithPoint(C);
				}
			return theResult;
	}


void destroyTriangle(Triangle *aTriangle)
	{
		if (NULL != aTriangle)
		{
			free(aTriangle->A);
			free(aTriangle->B);
			free(aTriangle->C);
			
			free(aTriangle);
		}
	}
	
	
float squareTriangle(Triangle *aTriangle)
	{
		float theResult = 0;
		if (NULL != aTriangle)
			{
				float a,b,c;
				float dX = (aTriangle->B->x - aTriangle->A->x);
				float dY = (aTriangle->B->y - aTriangle->A->y);
				c = sqrt(dX*dX + dY*dY);
				float dzX = (aTriangle->C->x - aTriangle->A->x);
				float dzY = (aTriangle->C->y - aTriangle->A->y);
				b = sqrt(dzX*dzX + dzY*dzY);
				float dmX = (aTriangle->B->x - aTriangle->C->x);
				float dmY = (aTriangle->B->y - aTriangle->C->y);
				a = sqrt(dmX*dmX + dmY*dmY);
				theResult = sqrt((a+b+c)/2)*sqrt(((a+b+c)/2)-a)*sqrt(((a+b+c)/2)-b)*sqrt(((a+b+c)/2)-c);
				
			}
		return theResult;
	}
	
	
void printTriangle(Triangle *aTriangle)
	{
		if( NULL != aTriangle)
			{
				printf("[Triangle]. A(%d,%d) - B(%d,%d) - C(%d,%d) \n",
					aTriangle->A->x, aTriangle->A->y,
					aTriangle->B->x, aTriangle->B->y,
					aTriangle->C->x, aTriangle->C->y);
			}
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
	
void writeTriangleToJSON(FILE *aFile, Triangle *aTriangle)
	{
		if (NULL == aTriangle || NULL == aFile)
			{
				return ; 
			}
		fprintf(aFile, "{\n\"A\" : ");
		writePointToJSON(aFile, aTriangle->A);
		fprintf(aFile, ", \n\"B\" : ");
		writePointToJSON(aFile, aTriangle->B);
		fprintf(aFile, ", \n\"C\" : ");
		writePointToJSON(aFile, aTriangle->C);
		fprintf(aFile, "\n}");
	}
	
	
	
void enter(int *X, int *Y)
{
    printf("x=");
    scanf("%d",X);
    printf("y=");
    scanf("%d",Y);
}
