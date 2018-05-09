#include "circle.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Point *copyPointWithPoint (Point *aPoint);
Circle *createCircle(Point *Center,Point *Radius)
{
	Circle *theResult = NULL;
	if (NULL != Center && NULL != Radius)
	{
		theResult = (Circle*)malloc(sizeof(Circle));
		if (NULL != theResult)
		{
			theResult->Center = copyPointWithPoint(Center);
			theResult->Radius = copyPointWithPoint(Radius);
		}
	}
	return theResult;
}

void FreeCircle(Circle *aCircle)
{
	if (NULL != aCircle)
	{
		free(aCircle->Center);
		free(aCircle->Radius);
		free(aCircle);
	}
}

float SquareCircle(Circle *aCircle)
{
	float theResult = 0.0;
	float R = sqrt(pow((aCircle->Radius->x - aCircle->Center->x), 2) + pow((aCircle->Radius->y - aCircle->Center->y), 2));
	theResult = 3.14*R*R;

	return theResult;
}

void printCircle(Circle *aCircle)
{
	if (NULL != aCircle)	printf ("[Circle].\n Center(%i,%i),\n Radius = (%i,%i)\n", aCircle->Center->x, aCircle->Center->y, aCircle->Radius->x,aCircle->Radius->y);
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
    if (NULL != aPoint || NULL != aFile)
    {
    	fprintf(aFile, "{\"X\" : %d, \"Y\" : %d}", aPoint->x, aPoint->y);
	}
}

void writeCircletToJSON(FILE *aFile, Circle *aCircle)
{
    if (NULL != aFile || NULL != aCircle)
    {
    	fprintf(aFile, "{\n\"Center \" : ");
    	writePointToJSON(aFile, aCircle->Center);
    	fprintf(aFile, ", \n\"Radius\" : ");
    	writePointToJSON(aFile, aCircle->Radius);
    	fprintf(aFile, ", \n\"Area \" : %f", SquareCircle(aCircle));
	}
}

int line_search(CircleArray *InstantArray, float key)
{
	int i;
	int pos;

    for(i = 0; i < InstantArray->count; i++)
    {
        if (SquareCircle(InstantArray->Circles[i]) == key)
        {
			printf("\nIt's right,you find it.'\n");
			pos=i;
		
		return pos+1;
		}
    }	
    return -1;
}

void quick_sort(CircleArray *InstantArray, int first, int last)
{
	int left = first;
 	int right = last;

	int mid = InstantArray->area[(left + right) / 2];

  while (left <= right)
  {
    while (InstantArray->area[left] < mid) left++;
    while (InstantArray->area[right] > mid) right--;

    if (left <= right)
	{
        swap(&InstantArray->Circles[left], &InstantArray->Circles[right]);
        left++;
        right--;
	}
  }
  
  if (first < right) quick_sort(InstantArray, first, right);
  if (left < last) quick_sort(InstantArray, left, last);
}
