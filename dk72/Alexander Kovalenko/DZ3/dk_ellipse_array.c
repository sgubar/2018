//
//  dk_ellipse_array.c
//  dz3
//
//  Created by Alexander Kovalenko on 4/03/18.
//  Copyright © 2018 Alexander Kovalenko. All rights reserved.
//

#include "dk_ellipse_array.h"
#include <stdlib.h>

// init/dealloc
EllipseArray *createArray(int aNumber)
{
	EllipseArray *theResult = NULL;
	
	if (aNumber > 0)
	{
		theResult = (EllipseArray *)malloc(sizeof(EllipseArray));
	
		if (NULL != theResult)
		{
			theResult->ellipses = (Ellipse **)malloc(sizeof(Ellipse *)*aNumber);
		
			if (NULL != theResult->ellipses)
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

void freeArray(EllipseArray *anArray)
{
	if (NULL != anArray)
	{
		for (int i = 0; i < anArray->count; i ++)
		{
			destroyEllipse(anArray->ellipses[i]);
		}
	
		free(anArray->ellipses);
		free(anArray);
	}
}

//interface
//returns index of added element OR -1 if fail
int addElement(EllipseArray *anArray, Ellipse *aEllipse)
{
	int theResult = -1;
	
	if (NULL != anArray && NULL != aEllipse &&
				anArray->count < anArray->number)
	{
		anArray->ellipses[anArray->count] = aEllipse;
					
	
		theResult = anArray->count;
		anArray->count ++;
	}
	
	return theResult;
}

void writeArrayToJSON(FILE *aFile, EllipseArray *anArray)
{
	if (NULL == anArray || NULL == aFile)
	{
		return ;
	}
	
	fprintf(aFile, "{\n\"number\" : %d,\n\"count\" : %d,\n",
			anArray->number, anArray->count);
	fprintf(aFile, "\"ellipses\" : \n[\n");
	
	for (int i = 0; i < anArray->count; i ++)
	{
		writeEllipseToJSON(aFile, anArray->ellipses[i]);
	
		if (i < anArray->count - 1)
		{
			fprintf(aFile, ",");
		}
		fprintf(aFile, "\n");
	}
	
	fprintf(aFile, "],\n}");
}

