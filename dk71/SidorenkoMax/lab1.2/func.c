#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int Result=0;


	int factorial(int a)
		{
				int h;
				Result=1;
				for(h=1;h<a+1;h++)
					{
						Result=Result*h;
					}
				return Result;
		}
		
		
	int multiplication(int a, int b)
		{
				Result=2*a+b;
				return Result;
		}
	
	int module(int multiplicationResult)
		{
			if (multiplicationResult < 0)
				Result=multiplicationResult*(-1);
			return Result;
		}
	
	float division (float factorialResult, float moduleResult)
		{
			float Result2=0;
			Result2 = factorialResult/moduleResult;
			return Result2;
		}

