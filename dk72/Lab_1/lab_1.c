#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "functions.h"

int main (int argc, char *argv[])
{
	//Short description of the program
	printf("\n This program calculates the formula: ((A*A + B*B)/(B + 5^C)) + B!, where A, B, C- input values\n");
	
	float A, B, C;
	float nominator, denominator, fraction, result;
	
	
	// Data input
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
	
	printf("\n Result =  %.2f \n", result);	
	
	
	getch();
	return 0;
}
