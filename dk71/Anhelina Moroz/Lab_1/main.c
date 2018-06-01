#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(){
	
	int A, B, C, numerator_module, sum1;
	float result;

	printf("Enter value\n");
	printf("A = ");
	scanf("%d", &A);
				
				
	printf("Enter value\n");
	printf("B = ");
	scanf("%d", &B);

			
	printf("Enter value, different from 0\n");
	printf("C = ");
	scanf("%d", &C);
	if (C == 0) 
	{
		printf("Value C is incorrect\n");
		return 0;
	}
	
	sum1 = sum_func(A);
	numerator_module = module(numerator(A,B,C)); 
	float numerator_module_float = (float) numerator_module;
	float cube_float = (float) cube(C);
	float sum_float = (float) sum1;
	result = (numerator_module_float)/(cube_float)*(sum_float);
	printf("Q = %f", result);
	
}
