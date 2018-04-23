#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define MAX_LENGTH 4

int len_end_or_delim = 0;

bool is_valid_oct(char c)
{
	return c >= '0' && c <= '7';
}

bool is_valid_value(const char *value_oct, const int len)
{
	if(len > MAX_LENGTH)
	{
		printf("\n Error: invalid length");
		return false;
	}
	len_end_or_delim = len;
	bool delim_met = false;
	int i;
	for(i = 0; i < len; i++)
	{
		if(value_oct[i] == '.' || value_oct[i] == ',')
		{
			if(delim_met)
			{
				printf("\n Error: already met the deilmeter");
				return false;	
			}
			delim_met = true;
			len_end_or_delim = i;
		}
		else
		{
			if(!is_valid_oct(value_oct[i]))
			{
				printf("\nError: invalid oct value");
				return false;
			}
		}
	}

	return true;
}


int main() 
{
	char value_oct[MAX_LENGTH];
	float value_dec = 0;

	printf("\n Please enter an oct value: ");
	gets(value_oct);

	const int len = strlen(value_oct);

	if (!is_valid_value(value_oct, len))
	{
		printf("\n Invalid value");
		getch();
		return -1;
	}

	bool is_floating_point = false;
	int power_to = len_end_or_delim - 1;
	int i = 0;
	int digit = 0;
	for (i = 0; i < len; i++)
	{
		if (!is_floating_point)
		{
			if (value_oct[i] == '.' || value_oct[i] == ',')
			{
				is_floating_point = true;
				power_to = -1;
				continue;
			}
		}
		
		digit = value_oct[i] - '0';
		
		value_dec += digit * pow(8, power_to);
		power_to--;
	}

	printf("\n Result %f", value_dec);
	getch(); 
	return 0;
}
