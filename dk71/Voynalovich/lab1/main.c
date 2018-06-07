#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


#include "Lab_Work_1_2_Functions.h"





int main()



{

	float variable_A;
	float variable_B;
	float variable_C;
	
    printf("\n");
    printf("\n");
	printf("This program will calculate the following expression : \n");

	printf("((A^2 + B^2)/(B + 5^C)) + B! \n");

	printf("In this expression you can inscribe 3 values.\n It's A,B and C \n");
    printf("\n");
    printf("\n");
	float nominator;
	float denominator;
	float result, fraction;

	

	//ask to enter the value

	printf("Enter an integer value for the first variable :\n A=");

	scanf("%f", &variable_A);

	printf("Enter an integer value for the second variable :\n B=");

	scanf("%f", &variable_B);
	
	while (variable_B < 0)
        
	{

		printf("\n variable_B was < 0  Please enter a positive integer value for variable_B \n\n\nvariable_B = ");

		scanf_s("%f", &variable_B);	

	}

	printf("Enter an integer value for the third variable :\n C=");

	scanf("%f", &variable_C);

	

	

	//Formula calculation

	nominator = ((variable_A * variable_A) + (variable_B * variable_B));
	
	denominator = (variable_B + power(5, variable_C));


    	//Check denominator
	if (denominator == 0 )

    		{

    			printf("Denominator egueted to 0 ,so your result will be only factorial(B), that was calculated as %f \n", factorial(variable_B) );

			}

		else

			{

				fraction = nominator/denominator;

	            result = fraction + factorial(variable_B);


				printf("\n Your result = %.2f \n", result);	

			}
  return 0;
}


