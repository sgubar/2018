#include "LB1.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//Calculates the factorial of a number
float factorial (float n)
{
	if (n == 0 || n == 1) 
		return 1;
	else
		return n * factorial(n - 1);
}


