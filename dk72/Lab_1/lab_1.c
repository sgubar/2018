#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "functions.h"

int main (int argc, char *argv[])
{
	printf("\n This program calculates the formula: ((A*A + B*B)/(B + 5^C)) + B!, where A, B, C- input values\n\n Do not use characters of type A, B C etc.\n\n");
	
	float A, B, C;
	float nominator, denominator, fraction, result;
	
	while (1)
	{
		
	// Ask the user to enter values
	printf("\n Enter the first value :\nA = ");
	scanf_s("%f", &A);
	
	printf("\n Enter the second value : \nB = ");
	scanf_s("%f", &B);
	while (B < 0)
	{
		printf("\n B was < 0  Please enter again.\nB = ");
		scanf_s("%f", &B);	
	}
	
	printf("\n Enter the third value (C > 0): \nC = ");
	scanf_s("%f", &C);
	
	//Formula 
	nominator = (A*A + B*B);
	denominator = (B + power(5, C));
	fraction =  nominator/denominator;
	result = fraction + factorial(B);
	
		printf("\n Result =  %.2f \n", result);	
		
	}
	
	getch();
	return 0;
}
