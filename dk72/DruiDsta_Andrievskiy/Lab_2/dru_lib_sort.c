#include "dru_lib_sort.h"

void EnterMass(int *mass, int size)
{
	int i=0;
	srand(time(NULL));
    for(; i!=size; i++)
    {
    	mass[i]=rand()%1000;
	}
	printf("\n");
}

void PrintMass(int *mass, int size)
{
	int i=0;
	for(; i!=size; i++)
	{
		printf("%d ", mass[i]);
	}
	printf("\n\n");
}

void TMP(int *A1, int *A2)
{
    int temp=*A1;
    *A1=*A2;
    *A2=temp;
}


void bubbleSort(int *anArray, int aSize)
{
	int theIn, theOut=aSize-1;
	
	for (; theOut>1; theOut--)
	{
		for (theIn=0; theIn<theOut; theIn++)
		{
			if (anArray[theIn]>anArray[theIn+1])	TMP(&anArray[theIn], &anArray[theIn+1]);
		}
	}
}

void selectionSort(int *anArray, int aSize)
{
	int theOut=0;
	for (; theOut<aSize-1; theOut++)
	{
		int theMinIndex=theOut, theIn=theOut+1;
	
		for (; theIn<aSize; theIn++)
		{
			if (anArray[theIn]<anArray[theMinIndex])
			{
				theMinIndex=theIn;
			}
		}
		TMP(&anArray[theOut], &anArray[theMinIndex]);
	}
}

void insertionSort(int *anArray, int aSize)
{
	int theOut=1;
	for (; theOut<aSize; theOut++)
	{
		int theTmp=anArray[theOut];
		int theIn=theOut;
	
		while (theIn>0 && anArray[theIn-1]>=theTmp)
		{
			anArray[theIn]=anArray[theIn-1];
			--theIn;
		}
	
		anArray[theIn]=theTmp;
	}
}

float ClockBubbleSort(int *anArray, int aSize)
{
	int Start, Stop, result;
	Start=clock();
	bubbleSort(anArray, aSize);
	Stop=clock();
	result=Stop-Start;
	return result;
}

float ClockSelectionSort(int *anArray, int aSize)
{
	int Start, Stop, result;
	Start=clock();
	selectionSort(anArray, aSize);
	Stop=clock();
	result=Stop-Start;
	return result;
}

float ClockInsertionSort(int *anArray, int aSize)
{
	int Start, Stop, result;
	Start=clock();
	insertionSort(anArray, aSize);
	Stop=clock();
	result=Stop-Start;
	return result;
}

void WriteMass(int *mass, int size, float time, char *name, char *sort)
{
	FILE *file=fopen(name, "a");
	int i=0;
	for(; sort[i]!='\0'; i++)
	{
		fprintf(file, "%c", sort[i]);
	}
	fprintf(file, ":\n");
	
	for(i=0; i!=size; i++)
	{
		if(i%20==0) fprintf(file, "\n");
	    fprintf(file, "%d\t", mass[i]);
	}
	fprintf(file, "\nTime: %.15f\n", time);
	fclose(file);
}













