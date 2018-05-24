//
//  main.c
//  Testing SimpleSort
//
//  Created by Alexander Kovalenko on 5/14/18.
//  Copyright © 2018 Alexander Kovalenko. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "SimpleSort.h"

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
#define SIZE1 10000

static void fileWrite(int anArray[], int aSize, char nf[], FILE *anFile);
static int fileRead(int anArray[], char nf[], FILE *anFile);


int main(int argc, const char * argv[])
{
	int theArray[SIZE1];
	
	printf("Test bubble sorting\n");
	
	FILE *fl1;
	int flSize=fileRead(theArray, "in.txt", fl1);
	clock_t theStart0 = clock();
    bubbleSort(theArray, flSize);
	clock_t theEnd0 = clock();
	printf("Sorted\n");
	fileWrite(theArray, flSize, "outBubble.txt", fl1);
	printf ("time of bubble sorting: %.10lf\n", (double)(theEnd0 - theStart0)/CLOCKS_PER_SEC);

	printf("\nTest selection sorting\n");
	flSize=fileRead(theArray, "in.txt", fl1);
	theStart0 = clock();
	selectionSort(theArray, flSize);
	theEnd0 = clock();
	printf("Sorted\n");
	fileWrite(theArray, flSize, "outSelection.txt", fl1);
	printf ("time of selection sorting: %.10lf\n", (double)(theEnd0 - theStart0)/CLOCKS_PER_SEC);

	printf("\nTest insertion sorting\n");
	flSize=fileRead(theArray, "in.txt", fl1);
	theStart0 = clock();
	insertionSort(theArray, flSize);
	theEnd0 = clock();
	printf("Sorted\n");
	fileWrite(theArray, flSize, "outInsertion.txt", fl1);
	printf ("time of insertion sorting: %.10lf\n", (double)(theEnd0 - theStart0)/CLOCKS_PER_SEC);


    return 0;
}

void fileWrite(int anArray[], int aSize, char nf[], FILE *anFile)
{
    anFile=fopen(nf,"a+");
    for (int i=0; i<aSize; i++)
    {
        fputc(anArray[i], anFile);
    }
    fclose(anFile);
}

int fileRead(int anArray[], char nf[], FILE *anFile)
{
    anFile=fopen(nf,"r");
    int theResult=0;
    while ((anArray[theResult]=fgetc(anFile)) != EOF)
    {
        theResult++;
    }
    fclose(anFile);
    return theResult;
}

