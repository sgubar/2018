#include "dru_lib_lab.h"

void EnterMass(int *mass, int size)
{
	int i=0;
	srand(time(NULL));
    for(; i!=size; i++)
    {
    	mass[i]=rand()%10000;
	}
	printf("\n");
}

void PrintMass(int *mass, int size)
{
	int i=0;
	for(; i!=size; i++)
	{
		printf("%d\t", mass[i]);
	}
	printf("\n\n");
}

int linearSearch(int *mass, int size)
{
	if(size<0)
	{
		printf("Error. The size value is negative.");
		return NULL;
	}
	
	int Key;
	printf("Enter the value you want to find:");
	scanf("%d",&Key);
	
	int i=0;
	for(; i!=size; i++)
	{
		if(mass[i]==Key) 
		{
			printf("Key position:%d\n", i);
			WriteTXT(i, "Search.txt", "Position:");
			return i; //position
		}
	}
	printf("There is no such key!");
	WriteTXT(0, "Search.txt", "There is no such key!");
	return NULL;
}

void TMP(int *A1, int *A2)
{
    int temp=*A1;
    *A1=*A2;
    *A2=temp;
}

void shellSort(int *anArray, int aCount)
{
	int theInner = 0;
	int theOuter = 0;
	int theH = 1; // start h = 1
	
	//1. Calculate start value of h
	while (theH <= aCount/3)
	{
		theH = theH*3 + 1; // 1, 4, 13, 40, 121, ....
	}

	//2. Sequental decrease h to 1
	while (theH > 0)
	{
		for (theOuter = theH; theOuter < aCount; theOuter ++)
		{
			int theTmp = anArray[theOuter];
			theInner = theOuter;
		
			// the first sub-array {0, 4, 8}
			while (theInner > theH-1 && anArray[theInner - theH] >= theTmp)
			{
				anArray[theInner] = anArray[theInner - theH];
				theInner -= theH;
			}
		
			anArray[theInner] = theTmp;
		}
	
		theH = (theH - 1) / 3; //decrease h
	}
}

float ClockShellSort(int *anArray, int aSize)
{
	float Start, Stop, result;
	Start=clock();
	shellSort(anArray, aSize);
	Stop=clock();
	result=Stop-Start;
	return result;
}

int partitionIt(int *anArray, int aLeftIndex, int aRightIndex, int aPivot)
{
	int theLeft = aLeftIndex - 1;
	int theRight = aRightIndex;
	
	while (1)
	{
		// search the bigest element
		while (anArray[++theLeft] < aPivot);
	
		// search the lowest element
		while (theRight > 0 && anArray[--theRight] > aPivot);
	
		if (theLeft >= theRight) // pointer are the same 
		{
			break;
		}
		else
		{
			//lets to swap elements
			int theTmp = anArray[theLeft];
			anArray[theLeft] = anArray[theRight];
			anArray[theRight] = theTmp;
		}
	}

	//lets to swap elements
	int theTmp = anArray[theLeft];
	anArray[theLeft] = anArray[aRightIndex];
	anArray[aRightIndex] = theTmp;
	
	return theLeft; // return break position
}

void quickSort(int *anArray, int aLeftIndex, int aRightIndex)
{
	if (aRightIndex - aLeftIndex <= 0)
	{
		return; // the array size equals to 1 - the array is fully sorted
	}
	
	int thePivot = anArray[aRightIndex];
	int thePartitionIndex = partitionIt(anArray, aLeftIndex, aRightIndex, thePivot);
	
	//left part sorting
	quickSort(anArray, aLeftIndex, thePartitionIndex - 1);
	
	//right part sorting
	quickSort(anArray, thePartitionIndex + 1, aRightIndex);
}

float ClockQuickSort(int *anArray, int aSize)
{
	float Start, Stop, result;
	Start=clock();
	quickSort(anArray, 0, aSize);
	Stop=clock();
	result=Stop-Start;
	return result;
}

void WriteTXT(float DR, char *name, char *text)
{
	FILE *file=fopen(name, "a");
	int i=0;
	for(; text[i]!='\0'; i++)
	{
		fprintf(file, "%c", text[i]);
	}
	fprintf(file, "%.15f\n", DR);
	fclose(file);
}
