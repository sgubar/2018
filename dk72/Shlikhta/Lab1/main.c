#include <stdio.h>

#include "my_math.h"

float A, B, C; //variables for input data
int sum = 0; //result
int i; //initialisation of counter for summ

int main()
{
	//entering data
	printf("Enter the A: ");
	scanf("%f", &A);

	printf("Enter the B: ");
	scanf("%f", &B);

	printf("Enter the C: ");
	scanf("%f", &C);

	//"protection from fool"
	while (B + sqr(C) == 0)
	{
		int flag;
		float temp_data;
		do
		{
			printf("ERR (B + C^2) = 0. Change B(enter 0) or C(enter 1), and enter data: ");
			scanf("%d %f", &flag, &temp_data);
		} while ((flag != 1) && (flag != 0));
		
		if (flag == 0) B = temp_data;
		if (flag == 1) C = temp_data;

	} 

	
	if (B < 0) i = B * (-1);  //counter for summ must be positive
	else i = B;

	for (i; i >= 0; i--) sum += fact(i); //summ being process
	
	printf("Result is a: %.2f\n", ((A * B) / (B + sqr(C))) + sum); //print result on the screen

    return 0;
}
