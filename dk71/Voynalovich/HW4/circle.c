#include "circle.h"
#include <stdio.h>
#include <stdlib.h>

// CIRCLE INTERFACE
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
	if (NULL != aCircle)	printf ("Circle.\n Center(%i,%i),\n Radius = (%i,%i)\n", aCircle->Center->x, aCircle->Center->y, aCircle->Radius->x,aCircle->Radius->y);
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
    	fprintf(aFile, "{\"x\" : %d, \"y\" : %d}", aPoint->x, aPoint->y);
	}
}

void writeCircletToJSON(FILE *aFile, Circle *aCircle)
{
    if (NULL != aFile || NULL != aCircle)
    {
    	fprintf(aFile, "{\n\"Center \" : ");
    	writePointToJSON(aFile, aCircle->Center);
    	fprintf(aFile, "\n\"Radius\" : ");
    	writePointToJSON(aFile, aCircle->Radius);
    	fprintf(aFile, "\n\"Square \" : %2f", SquareCircle(aCircle));
	}
}

// ARRAY INTERFACE

CircleArray *CreateArray(int aNumber)
{
    CircleArray *theResult = NULL;
    if(aNumber > 0)
    {
        theResult = (CircleArray *)malloc(sizeof(CircleArray));
        if(NULL != theResult)
        {
            theResult->Circles = malloc(sizeof(Circle *)*aNumber);
            if(NULL != theResult->Circles)
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

void freeArray(CircleArray *InstantArray)
{
	int i;
	if (NULL != InstantArray)
	{
		for (i = 0; i < InstantArray->count; i ++)
		{
			FreeCircle(InstantArray->Circles[i]);
		}
		free(InstantArray->Circles);
		free(InstantArray);
	}
}

void addElement(CircleArray *InstantArray, Circle *aCircle)
{
    if(NULL != InstantArray && NULL != aCircle && InstantArray->count < InstantArray->number)
    {
        InstantArray->Circles[InstantArray->count] = createCircle(aCircle->Center, aCircle->Radius);
        InstantArray->count++;
    }
}

void writeArrayToJSON(FILE *aFile, CircleArray *InstantArray)
{
    if (NULL == aFile || NULL == InstantArray) return;
    fprintf(aFile, "{\n\"number\" : %d,\n\"count\" : %d,\n", InstantArray->number, InstantArray->count);
    fprintf(aFile, "\"Circles\" : \n[\n");

	int i;
    for (i = 0; i < InstantArray->number; i++)
    {
        writeCircletToJSON(aFile, InstantArray->Circles[i]);
        if (i < InstantArray->number - 1)
        {
            fprintf(aFile, ",");
        }
        fprintf(aFile, "\n");
    }
    fprintf(aFile, "],\n}");
}

void insertion_sort(CircleArray *InstantArray)
{
    Circle *Tmp = NULL;
    int In;
	int Out;
	
    for (Out = 1; Out < InstantArray->count; Out++)
    {
        Tmp = InstantArray->Circles[Out];
        In = Out - 1;
        while(In >= 0 && InstantArray->Circles[In] > InstantArray->Circles[Out])
        {
            InstantArray->Circles[In+1] = InstantArray->Circles[In];
            In = In - 1;
        }
        InstantArray->Circles[In+1] = Tmp;
    }
}
