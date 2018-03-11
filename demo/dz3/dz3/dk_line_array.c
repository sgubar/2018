//
//  dk_line_array.c
//  dz3
//
//  Created by Slava Gubar on 3/1/18.
//  Copyright © 2018 Slava Gubar. All rights reserved.
//

#include "dk_line_array.h"
#include <stdlib.h>

// init/dealloc
LineArray *createArray(int aNumber)
{
	LineArray *theResult = NULL;
	
	if (aNumber > 0)
	{
		theResult = (LineArray *)malloc(sizeof(LineArray));
	
		if (NULL != theResult)
		{
			theResult->lines = (Line **)malloc(sizeof(Line *)*aNumber);
		
			if (NULL != theResult->lines)
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

void freeArray(LineArray *anArray)
{
	if (NULL != anArray)
	{
		for (int i = 0; i < anArray->count; i ++)
		{
			destroyLine(anArray->lines[i]);
		}
	
		free(anArray->lines);
		free(anArray);
	}
}

//interface
//returns index of added element OR -1 if fail
int addElement(LineArray *anArray, Line *aLine)
{
	int theResult = -1;
	
	if (NULL != anArray && NULL != aLine &&
				anArray->count < anArray->number)
	{
		anArray->lines[anArray->count] =
					createLine(aLine->A, aLine->B);
	
		theResult = anArray->count;
		anArray->count ++;
	}
	
	return theResult;
}

void writeArrayToJSON(FILE *aFile, LineArray *anArray)
{
	if (NULL == anArray || NULL == aFile)
	{
		return ;
	}
	
	fprintf(aFile, "{\n\"number\" : %d,\n\"count\" : %d,\n",
			anArray->number, anArray->count);
	fprintf(aFile, "\"lines\" : \n[\n");
	
	for (int i = 0; i < anArray->count; i ++)
	{
		writeLineToJSON(aFile, anArray->lines[i]);
	
		if (i < anArray->count - 1)
		{
			fprintf(aFile, ",");
		}
		fprintf(aFile, "\n");
	}
	
	fprintf(aFile, "],\n}");
}

