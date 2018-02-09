//
//H_W_tool.h
//
//hw1
//
//Created by Vadim Kharhuk on 2/09/18.
//
//Copyright © 2018 Vadim Kharchuk. All rights reserved.

#include "HWtool.h"


//Function for calculation Module from some values
float ModuleFromValue (float denominator)
{	
	float module;
	if(denominator < 0)
	denominator *= -1;
	else module = denominator;
	return module;
}

//Function for calculation Factorial for any values
int Factorial (int FirstValue)
{   int factorial = 1;
	int i = 1;
while(i < FirstValue + 1)
		{
		factorial  *= i;	
		i++;
		printf(" i = %d, factorial = %d\n", i, factorial);
	}   

	return factorial;
}
