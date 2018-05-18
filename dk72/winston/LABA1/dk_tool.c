#include "dk_tool.h"
#include <stdio.h>
#include <math.h>

void Enter_numbers(int *number_A, int *number_B, int *number_C)
{
    int A, B, C;

    do
    {
        printf("Enter number A(A>=0): ");
        scanf("%d",&A);
        printf("\n");
        if(A<0)
        {
        printf("Error! Enter number A again!");
        printf("\n\n");
        }

    }while(A<0);

    printf("Enter number B: ");
        scanf("%d",&B);
        printf("\n");

    do
    {
        printf("Enter number C(C!=0): ");
        scanf("%d", &C);
        printf("\n");
        if(C==0)
        {
             printf("Error! Enter number C again!");
             printf("\n\n");
        }

    }while(C==0);

    *number_A = A;
    *number_B = B;
    *number_C = C;

}

int function(int number_A, int number_B, int number_C)
{
    int Result_Number, Sum_number=3, Pow_number = 2, Abs_number;
    int i;

    if(number_A==0)
    {
       Sum_number = 1;
    }
    else if(number_A==1)
    {
        Sum_number = 3;
    }
    else
    {
        for(i=2; i<=number_A; i++)
        {
           Pow_number = 2;
           for(int k=2; k<=i; k++)
           {
              Pow_number *= 2;
           }
           Sum_number = Sum_number+Pow_number;
        }
    }

    Abs_number = number_A*number_C-number_B;

    if(Abs_number<0)
    {
        Abs_number *= -1;
    }

    Result_Number = Abs_number*Sum_number/number_C/number_C/number_C;

    return Result_Number;
}
