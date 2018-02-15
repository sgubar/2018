#include <stdio.h>
#include <stdlib.h>
#include "func.h"
	
			
			
		int factorial(float a)
			{
				int h, c;
				c=1;
				for(h=1;h<a+1;h++)
					{
						c=c*h;
					}
				return c;
			}

		int multiplication(float a, float b)
			{
				int c=0;
				c=2*a+b;
				return c;
			}
	
		int module(float ku1)
			{
				if ( ku1 < 0)
					{
						ku1 = ku1*(-1);
					}
		return ku1;
			}
	
	float division(float ku3 , float ku2)
		{	
			float result;
			result=ku3/ku2;
			return result;
		}

