#include <stdio.h>
#include "dk_tool.h"

int main()
{
    printf("Start!\n\n");

    int number_A, number_B, number_C, Result_Number;

    Enter_numbers(&number_A, &number_B, &number_C);

    Result_Number = function(number_A, number_B, number_C);

    printf("Result: ");

    printf("%d", Result_Number);

    printf("\n");

    printf("\nThe End!\n");

    return 0;
}
