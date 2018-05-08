#include "dz2.h"
#include "dz3.h"
#include "dz5.h"

#include <stdio.h>

void shellSortArray(TrapezeArray *theArray,FILE *file)
{
     Trapeze *tmp;
	int in = 0;
	int out = 0;
	int h = 1; // start h = 1
	
	//1. Calculate start value of h
	while (h <= theArray->count/2)
	{
		h = h*2 + 1; 
	}

	//2. Sequental decrease h to 1
	while (h > 0)
	{
		for (out = h; out < theArray->count; out ++)
		{
			tmp = theArray->trapezes[out];
			in = out;
		
			// the first sub-array {0, 4, 8}
			while (in > h-1 && areaTrapeze(theArray->trapezes[in - h]) >= areaTrapeze(tmp))
			{
				theArray->trapezes[in] = theArray->trapezes[in - h];
				in -= h;
			}
		
			theArray->trapezes[in] = tmp;
		}
	
		h = (h - 1) / 3; //decrease h
	}
	writeArrayToJSON(file, theArray);
}
int searchTrapezeToArea(TrapezeArray *theArray, float area)
{
	int first = 0,
		last = theArray->count - 1,
		middle = (first + last)/2;
	if(theArray == NULL) return 0;
	while(first < last)
	{
		printf("1\n");
		if(areaTrapeze(theArray->trapezes) == area)
		{
			printf("index = %d\n",middle);
			return 1;
		}
		if(areaTrapeze(theArray->trapezes) < area)
		{
			first = middle + 1;
		}else{
			last = middle;
		}
		middle = (first + last)/2;
	}
	return 0;	
}
