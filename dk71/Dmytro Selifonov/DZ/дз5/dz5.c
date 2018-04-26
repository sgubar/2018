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
	while (h <= theArray->count/3)
	{
		h = h*3 + 1; // 1, 4, 13, 40, 121, ....
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
