#include "dk_tool.h"
#include <stdio.h>
#include <math.h>

int BinaryToDecimal(void)
{
	char c;
    int result=0;
    printf("Binary arithmetic: ");
    while(scanf("%c",&c) == 1) 
	{
        if( (c<'0') || (c > '1') ) break;
        result<<=1;
        result+=c-'0';
    }
    printf("Decimal numerical system : %d", result);
    return 0;
}


























/*
		int counter = 1, timeless;
		int number, decimal = 0;
    	
		printf("Binary arithmetic: ");
    	scanf_s("%d", &number);
    
		while(number != 0)
		{ 
		timeless = number % 10*counter;
        decimal = decimal + timeless;
        number = number/10;
        counter*=2;
		}
	printf("Decimal numerical system : %d", decimal);
		

	return (0);
	*/
