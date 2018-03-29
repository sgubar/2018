#include <stdio.h>
#include "functions.h"


int main() {
    int B;
    float A, C, Q;
    
    printf("Hello, I am a calculator that knows only one formula ((Aˆ2+Bˆ2)/(B+5ˆC))+B!\n");
    printf("Input A: ");
    scanf("%f", &A);
    printf("Input B: ");
    scanf("%d", &B);
    
    while (B < 0)
    {
        printf("The argument for the factorial can not be less than zero. Please, input another value: ");
        scanf("%d", &B);
    }
    
    printf("Input C: ");
    scanf("%f", &C);
    
    
    
   
    Q = (power(A,2)+power(B,2))/(B + power(5, C))+factorial(B);
    printf("Result = %.4f\n", Q);
    
    
    return 0;
}


