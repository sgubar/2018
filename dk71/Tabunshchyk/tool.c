#include <stdio.h>
#include <stdlib.h>
#include "tool.h"




float leftside (int a,int b,int c)
{
	float r,r1;
	r=(a*b);
	r1=(c*c+b);                    
	r=r/r1;
	return r;
}


float rightside (int b)
{
	int d,summ,ad,ed,f;
	summ=0;
	for (ad=0; ad<=b; ad++)        //summation of a series of numbers
	{
		f=1;
		for (ed=1;ed<ad;ed++)      //factorial
		{
			f=f*(ed+1);		
		}                                                      //right side of example
		
	
		
		summ=(summ+f);		
	}
	return summ;
}
