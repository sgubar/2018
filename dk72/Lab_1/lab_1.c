#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "functions.h"

int main (int argc, char *argv[])
{
	printf("\n This program calculates the formula: ((A*A + B*B)/(B + 5^C)) + B!, where A, B, C- input values\n");
	
	float A, B, C;
	float nominator, denominator, fraction, result;
	
	
	// Ask the user to enter values
	printf("\n Enter the first value :\nA = ");
	scanf_s("%f", &A);
	printf("\n Enter the second value : \nB = ");
	scanf_s("%f", &B);
	printf("\n Enter the third value (C > 0): \nC = ");
	scanf_s("%f", &C);
	
	//Formula 
	nominator = (A*A + B*B);
	denominator = (B + power(5, C));
	fraction =  nominator/denominator;
	result = fraction + factorial(B);
	
	//Check denominator
	if (denominator == 0)
	{
		printf("\n Your denominator was equal to zero, which does not satisfy the range of admissible values.So, your result is %d. Try again to get a full result"/*, factorial(B)*/);
	}
	else
	{
		printf("\n Result =  %.2f \n", result);	
	}
	
	
	getch();
	return 0;
}
