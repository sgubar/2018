#include <stdio.h>

#include "my_math.h"

int fact(int count_f)
{
	int fact = 1;
	while (count_f > 0) { fact *= count_f; count_f--; }
	return fact;
}

float sqr(float data_sqr) { return data_sqr * data_sqr; }