#include <stdio.h>

#include "functions.h"

int main()
{
    float Q, A, B, C;

    printf("Hello! I'm calculate one weird formula!\n Enter A: ");//requesting values from user
    scanf("%f", &A);
    printf(" Enter B: ");
    scanf("%f", &B);
    printf(" Enter C: ");
    scanf("%f", &C);

    while(C == 0)//checking for invalid values
    {
        printf(" You can't divide by zero! Enter another value: ");
        scanf("%f", &C);
    }

    Q = (absolutValue(A * C - B)/exponentation(C, 3)) * sum(A);//calculating formula

    printf("Result = %.3f\n", Q );//result output

    return 0;
}
