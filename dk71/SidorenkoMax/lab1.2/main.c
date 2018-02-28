#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main() {
	int a,b;
	do																		
		{	printf("Enter value A\n");
			printf("Value must be greater than zero\n");
			scanf("%d", &a);
		}while(a < 0);
	printf("Enter value B\n");
	scanf("%d", &b);
	float moduleResult, multiplicationResult, factorialResult;
	float  divisionResult;
	factorialResult = (factorial(a));
	multiplicationResult = (multiplication(a,b));
	moduleResult = (module(multiplicationResult));
	divisionResult = (division(factorialResult,moduleResult));
	printf("Result: %.2f", divisionResult);	
	
	return 0;
}
