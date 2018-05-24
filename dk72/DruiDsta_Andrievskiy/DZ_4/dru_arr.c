#include "dru_arr.h"


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
			theResult->aFig=(Fig **)malloc(sizeof(Fig *)*aNumber);
			theResult->S=(float *)malloc(sizeof(float)*aNumber);
			
			if (NULL != theResult->aFig)
			{
				theResult->num=aNumber;
				theResult->count=0;
			}
			else
			{
				free(theResult);
				theResult=NULL;
			}
		}
	}

	return theResult;
}

void addElement(FigArr *anArr, Fig *aFig, Param *fig_par)
{

	if (NULL!=anArr && NULL!=aFig && anArr->count<anArr->num)
	{
		anArr->count++;
		anArr->aFig[anArr->count]=aFig;
		anArr->S[anArr->count]=fig_par->S;
		
	}

}

void freeArr(FigArr *anArr)
{
	int i=1;
	if (NULL != anArr)
	{
		for (; i<=anArr->count; i++)
		{
			destroyFig(anArr->aFig[i]);
		}
		free(anArr->aFig);
		free(anArr);
	}
}

void writeArrayToJSON(FILE *aFile, FigArr *anArr)
{
	if (NULL == anArr || NULL == aFile)
	{
		return ;
	}
	
	fprintf(aFile, "{\n\"number\" : %d,\n", anArr->num);
	
	int i=1;
	for (; i<=anArr->count; i++)
	{
		fprintf(aFile, "\n\"count\" : %d,\n", i);
		writeFigToJSON(aFile, anArr->aFig[i]);
		fprintf(aFile, "S=%f", anArr->S[i]);
		
		if (i<anArr->count)
		{
			fprintf(aFile, "\n\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
		}
		
	}
	
	fprintf(aFile, "\n}\n");
}

void bubbleSort(FigArr *anArray)
{
	int theIn, theOut=anArray->num--;
	
	for (; theOut>1; theOut--)
	{
		for (theIn=0; theIn<theOut; theIn++)
		{
			if (anArray->S[theIn]>anArray->S[theIn++])	TMP(&anArray->aFig[theIn], &anArray->aFig[theIn++]);
		}
	}
}

void TMP(FigArr *A1, FigArr *A2)
{
    FigArr *temp=A1;
    A1=A2;
    A2=temp;
}

void printArr(FigArr *anArray)
{
	if (NULL==anArray)
	{
		return ;
	}
	
	printf("{\n\"number\" : %d,\n", anArray->num);
	
	int i=0;
	for (; i<anArray->count; i++)
	{
		printf("\"count\" : %d\n", i);
		printFig(anArray->aFig[i]);
	
		if (i>anArray->count-1)
		{
			printf("\n\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
		}
		printf("S=%f\n\n", anArray->S[i]);
	}
	
	printf("\n}\n");
}




