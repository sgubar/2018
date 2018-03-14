#include <stdio.h>
#include <math.h>
#include "math1.h"
int suma(int a,int b,int c);
int read_hex();

 int suma(int a,int b,int c)
{
	int result = 0, dodatkova_zmina = b - c;
	int i = 0;
	for(i = 1;i <= a;i++){
		result += i * dodatkova_zmina;
	}
	return result;
}
int read_hex()
{
	char hex[4];
	hex[4]=(0,0,0,0);
	int dec = 0;
	int zmina = 0;
	printf("vvedit chuslo hex(4 sumvola):\n");
	int i = 0;
	for(i = 0;i < 4;i++){
		scanf("%c",&hex[i]);
		if(!((hex[i] >= '0'&&hex[i] <= '9')||(hex[i] >= 'a'&&hex[i] <= 'f')||(hex[i] >= 'A'&&hex[i] <= 'F'))){
			printf("vu velu ne pravulnuy sumvol sprobuyte znovy\n");
			hex[4] = (0,0,0,0);
			i--;
		}
	}
	
	printf("vu vvelu = %c%c%c%c\n",hex[0],hex[1],hex[2],hex[3]);
	for(i = 3;i >= 0;i--)
	{
		if(hex[i] >='0'&&hex[i] <= '9'){
			zmina = (hex[i] - 48)*pow(16,3 - i);
		}
		if(hex[i] >='A'&&hex[i] <= 'F'){
			zmina = (hex[i] - 55)*pow(16,3 - i);
		}
		if(hex[i] >= 'a'&&hex[i] <= 'f'){
			zmina=(hex[i] - 87)*pow(16,3 - i);
		}
			
		dec += zmina;
	}
	printf("dec = %d\n",dec);
	return dec;	
}

