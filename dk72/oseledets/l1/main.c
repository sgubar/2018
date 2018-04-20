#include <stdio.h>
#include "dk.h"


int main()
{
    int A;

    float Q, B;


    printf("Enter A: ");
    scanf("%d", &A);
    printf("Enter B: ");
    scanf("%f", &B);



    Q = factorial(A) / module((2*A)+B);

    printf("Result = %.2f\n", Q);





    return 0;
}
