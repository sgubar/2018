#include <stdio.h>
#include <stdlib.h>

//Function for calculation Module
float ModuleFromValue (float denominator)
{	
	float module;
	if(denominator < 0)
	denominator *= -1;
	else module = denominator;
	return module;
}

//Function for calculation Factorial
int Factorial (int FirstValue)
{		printf("In function");
    int factorial;
    printf("%d",FirstValue);
	int i = 0;
	while(i <= FirstValue)
		{
		factorial *= i;	
		i++;
	}   
		printf("Out");	
	return factorial;
}


int main(int argc, char *argv[]) {
	
	int FirstValue , SecondValue, FactorialValue = 0;
	float denominator , Result, denominatorModule;
	
	//Work with User 
	printf("Put first value : ");
	scanf("%d",&FirstValue);
    printf("\nPut second value :");
    scanf("%d",&SecondValue);
    
    //Formula calculation
    denominator = (2 * FirstValue) + SecondValue;
  //  printf("denominator = %f\n",denominator);
   denominatorModule = ModuleFromValue(denominator);
   printf("DenModule :%f",denominatorModule);
   FactorialValue = Factorial(FirstValue);
   printf("DenModule :%f",FactorialValue);
    //Stupid check
    	if (denominatorModule == 0 )
    		{
    			printf("Denominator can`t be 0, plz restart programe and values\n");
			}
		else
			{
				Result = FactorialValue / denominatorModule;
				printf("U Result =  %f \n");	
			}
}
