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
#include "shellSort.h"
/* #include "shellSort.h"
#include "quickSort.h" */

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
#define SIZE1 10000

static void fileWrite(int anArray[], int aSize, char nf[], FILE *anFile);
static int fileRead(int anArray[], char nf[], FILE *anFile);
static int BinarySearch(int value, int values[], int n);


int main(int argc, const char * argv[])
{
	int theArray[SIZE1];
	
	printf("Test Shell sorting\n");
	
	FILE *fl1;
	int flSize=fileRead(theArray, "in.txt", fl1);
    
	clock_t theStart0 = clock();
    shellSort(theArray, flSize);
	clock_t theEnd0 = clock();
	printf("Sorted\n");
	fileWrite(theArray, flSize, "outShell.txt", fl1);
	printf ("time of shell sorting: %.10lf\n", (double)(theEnd0 - theStart0)/CLOCKS_PER_SEC);
    printf ("\nBinary Search\n Input value:");
    int val1 = getchar();
    printf("\n%d\n", val1);
    int position=BinarySearch(val1, theArray, flSize);
    if (position < 0)
    {
        printf("\nValue not found\n");
    }
    else
    {
        printf("\nFound - theArray[%d]='%c'\n", position, (char)theArray[position]);
    }

    return 0;
}

int BinarySearch(int value, int values[], int n)
{
  int lower = 0;
  int upper = n-1;
  while (lower <= upper)
  {
      int middle=(upper + lower)/2;
      if (values[middle] == value)
      {
          return middle;
      }
      else if (values[middle] > value)
           {
               lower=middle + 1;
           }
           else if (values[middle] < value)
                {
                    upper=middle-1;
                }      
  }
  return -1;

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

