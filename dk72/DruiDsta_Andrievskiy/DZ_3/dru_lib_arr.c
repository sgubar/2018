#include <stdlib.h>
#include <stdio.h>
#include "dru_lib.h"
#include "dru_lib_arr.h"


FigArr *createArr()
{
	FigArr *theResult = NULL;
	
	int aNumber;
	printf("Enter the number of figures:");
	scanf("%d",&aNumber);
	
	if (aNumber > 0)
	{
		theResult = (FigArr *)malloc(sizeof(FigArr));
	
		if (NULL != theResult)
		{
			theResult->aFig = (Fig **)malloc(sizeof(Fig *)*aNumber);
		
			if (NULL != theResult->aFig)
			{
				theResult->num = aNumber;
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

int addElement(FigArr *anArr, Fig *aFig, Param *fig_par)
{
	int theResult=-1;
	
	if (NULL!=anArr && NULL!=aFig && anArr->count<anArr->num)
	{
		anArr->aFig[anArr->count]=createFig(aFig->A, aFig->B, aFig->C);
	
		theResult=anArr->count;
		anArr->count++;
	}
	return theResult;
}                           

void freeArr(FigArr *anArr)
{
	int i=0;
	if (NULL != anArr)
	{
		for (; i<anArr->count; i++)
		{
			destroyFig(anArr->aFig[i]);
		}
		free(anArr->aFig);
		free(anArr);
	}
}
                                    
void writeArrayToJSON(FILE *aFile, FigArr *anArr)
{
	if (NULL == anArr || NULL == aFile)
	{
		return ;
	}
	
	fprintf(aFile, "{\n\"number\" : %d,\n", anArr->num);
	
	int i=0;
	for (; i<anArr->count; i++)
	{
		writeFigToJSON(aFile, anArr->aFig[i]);
	
		if (i<anArr->count-1)
		{
			fprintf(aFile, "\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
		}
	}
	
	fprintf(aFile, "\n}\n");
}

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
