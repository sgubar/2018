#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include "circle.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	
	//Coordinates declaration
	Point Coords = {2,4};                                    
	
	Circle *Crl = createCircle(&Coords); //Creating circle
	printCircle(Crl);  //Print circle
	printf("The Square of Circle = %f\n", SquareCircle(Crl)); //Square of circle
	Coords.x = 3;
	
	printCircle(Crl);
	destroyCircle(Crl); //Destroying circle
	
	getch();
	return 0;
}
