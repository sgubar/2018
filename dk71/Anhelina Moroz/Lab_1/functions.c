#include <math.h>
#include <stdio.h>
#include <stdlib.h> 
#include "functions.h"


int module(int value) 
{
	return value >= 0 ? value : value*(-1);
}


int cube(int C) 
{
	return C*C*C;
}


int numerator(int A, int B, int C) 
{
	return (A * C) - B;
}


int power(int D) 
{
	return pow(2, D);	
}


int sum_func(int A) 
{
	int D;
	int sum;

	for(D = 0; D <= A; D++) 
	{
		sum = sum + power(D);
	}	
	return sum;		
}
