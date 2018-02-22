#include "functions.h"
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

float power(float a, float b)
{
	if (b == 0) return 1;
	if (b < 0) return power(1.0 / a, -b);
	return a * power(a, b - 1);
}
