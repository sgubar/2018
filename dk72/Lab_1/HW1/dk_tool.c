#include "dk_tool.h"
#include <stdio.h>
#include <math.h>

int ConvertToDecimal(int number, int base)
{
	int count = 0, result = 0;
	
	do
	{
		int mod = number % 10;
		result += pow(base, count)*mod; 
		count++;
		number /= 10;
	} while(number);
	
	return result;
}

