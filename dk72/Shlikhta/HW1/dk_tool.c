#include "dk_tool.h"

#include <string.h>

int power(int data_pow, int st)
{
	if(st == 0) return 1;
	return data_pow * power(data_pow, st-1);
}

int hextodec(char num_hex[10])
{
	int temp_num, num_dec = 0, str_len = strlen(num_hex);
	
	// converting from hex to dec
	for(int i = 0; num_hex[i] != '\0' ; i++)
	{
		if(num_hex[i] >= '0' && num_hex[i] <= '9') temp_num = num_hex[i] - 48; 
		if(num_hex[i] >= 'A' && num_hex[i] <= 'F') temp_num = num_hex[i] - 55;
		if(num_hex[i] >= 'a' && num_hex[i] <= 'f') temp_num = num_hex[i] - 87; 
		
		num_dec += power(16, str_len-i-1) * temp_num;
	}

	return num_dec;
}
