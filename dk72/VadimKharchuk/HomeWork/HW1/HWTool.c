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
	}   

	return factorial;
}

//stupid check
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int ValueCheck() {

    int value;
        while (  scanf("%d",&value) == 0 )
        {
            printf("\tAre you sure used correct values? Check it, and try aggain: ");
                while(getchar()!='\n');
        }
    printf("\tDonne\n");
    return value;
}
