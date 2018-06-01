#include <stdio.h>
#include <stdlib.h>
#include "LAB_1.h"

int main(void)
{
	int A = 0;
	int B = 0;
	int C = 0;
	float result = 0;
	printf(" In this program you have to enter three integer values to calculate the mathematical expression #2 ...\n\n Please enter an integer value for variable 'A' ...\n\n Your value: ");
	checkFunction(&A);
	printf("\n\n Please enter an integer value for variable 'B' ...\n\n Your value: ");
	checkFunction(&B);
	printf("\n\n Please enter an integer value for variable 'C' ...\n\n Your value: ");
	checkFunction(&C);
	while(C == 0)
	{
        printf("\n\n Incorrect value for variable 'C' ...\n\n 'C' could not be equal to '0' ...\n\n Please try again ...\n\n Your value: ");
	    checkFunction(&C);
	}
	result = moduleFunction(((A * C) - B)) /  powerFunction(C, 3) * sumFunction(A);
	printf("\n\n Result of calculating: %f", result);
	return 0;

}