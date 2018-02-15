#include <stdio.h>
#include <stdlib.h>
#include "laba.h"
int main()
{
	printf("This program solves this example\n");

	printf("\t    A*B   __B\n\tQ = --- + \\  * D!\n\t    B+C^2 /_  \n\t            D=0\n");
	printf("Please! Enter the values:\n");
		int A=0, B=0, C=0;
		float Q=0;
		int numerator;
		int denominator;
		double result_division = 0;
		int sum_factorial=0;
		int power(int n);
		int sum(int B);
	
		
		
		
		scanf("%d", &A);
	printf("A=%d\n", A);
		scanf("%d", &B);
	printf("B=%d\n", B);
		scanf("%d", &C);
	printf("C=%d\n", C);
			
			 numerator = A * B;
			 denominator = B + power(C);
			 result_division = (double)numerator/denominator;
			 printf("%.3f\n", result_division);
		
			sum_factorial = sum(B);
			Q = (result_division + sum_factorial);
				printf("RESULT: Q=%.3f\n", Q);

	return 0;
}
