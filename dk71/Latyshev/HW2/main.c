#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include "circle.h"


int main() 
{
	
	//Coordinates declaration
	Point A = {2,4};                                    
	
	Circle *sample = createCircle(&A); //Creating circle
	printCircle(sample);  //Print circle
	printf("The Square of Circle = %f\n", SquareCircle(sample)); //Square of circle

	
	FreeCircle(sample); //Destroying circle
	
	return 0;
}
