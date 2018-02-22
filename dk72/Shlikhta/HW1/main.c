#include <stdio.h>
#include <string.h>

#include "dk_tool.h"

int flag = 1;
char data[4], result[32];

int main(void)
{
	while(1)
	{
	//enter data and check on correct entering
		do
		{
			//entering data
			printf("Enter a hexademical numeric(x or X for exit): "); //if you enter "x" or "X" program will end
			scanf("%4s", &data); //5th symbol and more don't read
		
			if(data[0] == 'x' || data[0] == 'X'){ flag = 2; break; } //special for exit
			
			//checking for correct entering
			for(int i = 0; data[i] != '\0'; i++)
			{
				if(data[i] < 48 || 
				(data[i] > 57 && data[i] < 65) || 
				(data[i] > 70 && data[i] < 97) || 
				data[i] > 102)
				{ 
					printf("%c ERR\n", data[i]); 
					flag = 0;
				}
				else flag = 1;
			
			}
		}while(flag == 0); 
	
		if(flag == 2) break;
	
		sprintf(result, "%s(hex) = %d(dec)", data,  hextodec(data));
	
	
		for(int i = 0; result[i] != '\0'; i++) printf("-");
		printf("\n");
		printf("%s\n", result); //print the result
		for(int i = 0; result[i] != '\0'; i++) printf("-");
		printf("\n");
	}
	
	return 0;
}
