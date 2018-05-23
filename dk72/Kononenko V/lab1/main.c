#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "LB1.h"

int main (int argc, char *argv[])
{
	printf("\nStart of programm,enter value\n");
	
	float A, B, C, D;
	float nomin, denomin, frac, result;
	
	
	// Ask the user to enter values
	printf("\nA = ");
	scanf_s("%f", &A);
	printf("\nB = ");
	scanf_s("%f", &B);
	printf("\nC = ");
	scanf_s("%f", &C);
	int i=0;
	for(;i<B+1;i++){
		D=factorial(i)+D;	
		
	}
	
	//Formula 
	nomin = (A*B);
	denomin = (B + C*C);
	frac =  nomin/denomin;
	result = frac + D;
	if(denomin==0){
		printf("\n func of domination cant be 0");
		return;}
		else{
	
		
	
	printf("\n Result =  %.2f \n", result);	
	
        }
	
	getch();
	return 0;
}
