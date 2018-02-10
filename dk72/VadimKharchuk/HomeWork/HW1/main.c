#include <stdio.h>
#include <stdlib.h>
#include "HWtool.h"

int main(int argc, char *argv[]) {
	printf("\t\t    This programe using input values only within variable INTEGER and output FLOAT\n");
	printf("\t\t    If U ready to start press any button\n\n");
	getch();
	int FirstValue , SecondValue, FactorialValue;
	float denominator , Result, denominatorModule;
	
	//Work with User 
	printf("\tPut first value : ");
	FirstValue = ValueCheck();
    printf("\n\tPut second value :");
    SecondValue = ValueCheck();
    
    //Formula calculation
    denominator = (2 * FirstValue) + SecondValue;
   denominatorModule = ModuleFromValue(denominator);
   FactorialValue = Factorial(FirstValue);
   
    //Check denominator 
    	if (denominatorModule == 0 )
    		{
    			printf("\tDenominator can`t be 0, plz restart programe and update values\n");
			}
		else
			{
				Result = FactorialValue / denominatorModule;
				printf("\tU Result =  %.2f \n",Result);	
			}
}
