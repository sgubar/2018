#include <stdio.h>
#include <stdlib.h>
#include "func.h"


int main() {
	int a,b;																	// Initializing variables
	do																			// Variable input
		{	printf("Enter value A\n");
			printf("Value must be greater than zero\n");
			scanf("%d", &a);
		}while(a < 0);
	printf("Enter value B\n");
	scanf("%d", &b);															// Variable input
	float ku1,ku2,ku3;
	float ku4;
	ku3 = (factorial( a));
	ku1 = (multiplication(a,b));
	ku2 = module(ku1);
	ku4 = division(ku3, ku2);
/*	printf("%.1f ",ku3);																							
	printf("%.1f ",ku1);
	printf("%.1f ",ku2); */
	printf("Result: ");
	printf("%.2f ",ku4); 
	return 0;
}
