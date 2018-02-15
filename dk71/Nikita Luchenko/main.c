#include <stdio.h>
#include <stdlib.h>
#include "laba.h"
int main()
{
	printf("This program solves this example\n");

	printf("\t    A*B   __B\n\tQ = --- + \\  D!\n\t    B+C^2 /_  \n\t            D=0\n");
	printf("Please! Enter the values:\n");
		int A=0, B=0, C=0;
		float Q=0;
		int numerator;
		int denominator;
		double result_division = 0;
		int sum_factorial=0;
		int power(int n);
		int sum(int B);
		int factorial(int sum);
	
		
		
		
		scanf("%d", &A);
	printf("   A=%d\n", A);
		scanf("%d", &B);
	printf("   B=%d\n", B);
		scanf("%d", &C);
	printf("   C=%d\n\n", C);
			
			 numerator = A * B;
			 denominator = B + power(C);
			 
			 	if (denominator==0)
				 {
				 	printf("The denominator can not be zero");
				 	return 0;
				 }
			 
			 result_division = (double)numerator/denominator;
			 printf("\t%d*%d\n\t--- = %.3f\n\t%d+%d^2\n\n", A, B, result_division, B, C);
		
			sum_factorial = sum(B);
			printf("\t__%d\n\t\\  D = %d\n\t/_\n\t  D=0\n\n", B, sum_factorial);
			Q = (result_division + sum_factorial);
				printf("RESULT: Q = %.3f\n", Q);

	return 0;
}
