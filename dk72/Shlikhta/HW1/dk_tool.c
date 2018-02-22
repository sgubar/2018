#include "dk_tool.h"

#include <string.h>

int num_hex_dec[6], num_dec = 0;

int power(int data_pow, int st)
{
	if(st == 0) return 1;
	return data_pow * power(data_pow, st-1);
}

int hextodec(char num_hex[10])
{
	//comparison A B C D E F with dec "analogue"
	for(int i = 0; num_hex[i] != '\0' ; i++)
	{
		if(num_hex[i] > 47 && num_hex[i] < 58) num_hex_dec[i] = num_hex[i] - 48; 
		if(num_hex[i] > 64 && num_hex[i] < 71) num_hex_dec[i] = num_hex[i] - 55;
		if(num_hex[i] > 96 && num_hex[i] < 103) num_hex_dec[i] = num_hex[i] - 87; 
	}
	
	//for(int i = 0; i < strlen(num_hex); i++) printf("%d ", num_hex_dec[i]); //only for test
	
	int j = 0;
	
	// converting from hex to dec
	for(int i = strlen(num_hex)-1; i >= 0; i--) 
	{  
		num_dec += power(16, i) * num_hex_dec[j]; 
		j++;
	} 
	
	j = 0;
	
	return num_dec;
}