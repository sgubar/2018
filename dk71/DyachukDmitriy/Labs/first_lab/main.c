#include <stdio.h>
#include <stdlib.h>
#include "first_lab.h"

int main(void)
{
    int variable_B = 0;
    int variable_A = 0;
    int variable_C = 0;
    float result_Q = 0;
    int value_result = 0;
    printf("This programm will calculate the output value of mathematical expression: \n");
    printf("\n\t(A^2) + (B^2)\n\t------------- + B!\n\t  B + (5^C)\n\n");
    printf("Please enter the integer value for variable 'A':\nA = ");
    do
    {
        value_result = scanf("%i", &variable_A);
        fflush(stdin);
        if (value_result == 1)
        {
           printf("You have entered the value of: %i\n", variable_A);
        }else
        {
           printf("Your value does not meet the condition of this programm.\nPlease try again:\nA = ");
        }
    }while(value_result != 1);
    printf("Please enter a positive integer value for variable 'B':\nB = ");
    do
    {
        value_result = scanf("%i", &variable_B);
        fflush(stdin);
        if (value_result == 1 && variable_B >= 0)
        {
           printf("You have entered the value of: %i\n", variable_B);
        }else
        {
           printf("Your value does not meet the condition of this programm or factorial of this value non-exist.\nPlease try again:\nB = ");
        }
    }while(value_result != 1 || variable_C < 0);
    printf("Please enter a positive integer value for variable 'C':\nC = ");
    do
    {
        value_result = scanf("%i", &variable_C);
        fflush(stdin);
        if (value_result == 1 && variable_C >= 0)
        {
           printf("You have entered the value of: %i\n", variable_C);
        }else
        {
           printf("Your value does not meet the condition of this programm or there is no such degree.\nPlease try again:\nC = ");
        }
    }while(value_result != 1 || variable_С < 0);
    printf("\n\t(%i^2) + (%i^2)\n\t------------- + %i!\n\t  %i + (5^%i)\n\n", variable_A, variable_B, variable_B, variable_B, variable_C);
    int output_factorial = factorial(variable_B);
    int output_numerator = numerator(variable_A, variable_B);
    int output_denominator = denominator(variable_B, variable_C);
    result_Q = all_expression(output_factorial, output_numerator, output_denominator);
    printf("\nResult os this mathematical expression with your values (A = %i; B = %i; C = %i) is equal to the: %f\n", variable_A, variable_B, variable_C, result_Q); // Диалог с пользователем
    return 0;
}
