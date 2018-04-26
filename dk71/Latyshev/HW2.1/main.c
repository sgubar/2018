#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include "circle.h"


int main() 
{
	
	//Coordinates declaration
	Point Center = {2,4};    
	Point Rad ={1,3};                                
	
	Circle *sample = createCircle(&Center,&Rad); //Creating circle
	printCircle(sample);  //Print circle
	printf("The Square of Circle = %f\n", SquareCircle(sample)); //Square of circle

	
	FreeCircle(sample); //Destroying circle
	
	return 0;
}
