#include <stdio.h>
#include <stdlib.h>
#include "HWtool.h"

int main(int argc, char *argv[]) {
	
	int FirstValue , SecondValue, FactorialValue;
	float denominator , Result, denominatorModule;
	
	//Work with User 
	printf("Put first value : ");
	scanf("%d",&FirstValue);
    printf("\nPut second value :");
    scanf("%d",&SecondValue);
    
    //Formula calculation
    denominator = (2 * FirstValue) + SecondValue;
   denominatorModule = ModuleFromValue(denominator);
   FactorialValue = Factorial(FirstValue);
   
    //Stupid check
    	if (denominatorModule == 0 )
    		{
    			printf("Denominator can`t be 0, plz restart programe and values\n");
			}
		else
			{
				Result = FactorialValue / denominatorModule;
				printf("U Result =  %.2f \n",Result);	
			}
}
