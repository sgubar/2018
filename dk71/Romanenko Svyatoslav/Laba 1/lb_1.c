#include "lb_1.h"

int factorial(int znach)
{
	int theResult = 1;
	int i;
	for(i=1;i<=znach;i++){
		theResult=theResult*i;
	}
	
	return theResult;
}
int multiply(int znach1, int znach2)
{
	int theResult = znach1*znach2;
	
	return theResult;
}
int division(int znach1, int znach2)
{
	int theResult;
	if(0!=znach2){
	     theResult =znach1/znach2;
	} else {
		printf("you can not divide by 0!");
	}
	
	
	return theResult;
}
int math_sum(int C, int A)
{
	int D,theResult;
	for(D=0;D<=C;D++){
		theResult=theResult+factorial(A+D);
	}
	
	return theResult;
}
