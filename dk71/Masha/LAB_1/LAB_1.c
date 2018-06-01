#include <stdio.h>
#include <stdlib.h>
#include "LAB_1.h"

int checkFunction(int *variable)
{
	int result = scanf("%i", variable);
	while(result != 1)
	{
		fflush(stdin);
		printf("\n\t- Incorrect value ...\n\t- Value: ");
		result = scanf("%i", variable);
	}
}

int moduleFunction(int value)
{
	if(value < 0)
		return (value * (-1));
	else if(value >= 0)
		return value;
}

float powerFunction(int value, int power)
{
	if(power > 1)
	{
		for(int i = 2; i <= power; ++i)
		value *= value;
	}else if(power == 0)
	{
		value = 1;
	}else if(power < 0)
	{
		power = moduleFunction(power);
		for(int i = 2; i <= power; ++i)
		value *= value;
		(float)value;
        value = 1 / value;
	}
	return value;
}

float sumFunction(int numOfOperations)
{
	float result = 0;
	if(numOfOperations >= 0)
		for(int D = 0; D <= numOfOperations; ++D)
			result += powerFunction(2, D);
	else if(numOfOperations < 0)
		for(int D = 0; D >= numOfOperations; --D)
			result += powerFunction(2, D);
	return result;
}