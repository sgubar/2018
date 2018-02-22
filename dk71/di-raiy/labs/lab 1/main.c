#include <stdio.h>
#include <stdlib.h>


int Factorial(int num)
{
    int factorial = 1;
    if (num > 0)
    {
      for(int i=1; i <= num; i++ )
        {
            factorial = factorial*i;
        }
    }
    return factorial;
}

int main()
{
    printf("This is firs lab;\n");
    printf("Variant 8 (1);\n");
    printf("\n");
    printf("     A * B      B\n");
    printf("Q = _______ + E     * D!;\n");
    printf("    B + C^2     D=0\n");
    printf("\n");
    printf("input data A, B, C;\n");
    printf("Please, enter A : ");
    float A;
    scanf("%f", &A);
    printf("Please, enter B : ");
    float B;
    scanf("%f", &B);
    if ( B < 0)
    {
        printf("mi takogo ne uchili\n");
        return 0;
    }
    printf("Please, enter C : ");
    float C;
    scanf("%f", &C);
    float drob;
    if (B + (C*C)==0)
    {
        printf("error. Dilenie na 0\n");
        return 0;
    }
    drob = (A*B)/(B+(C*C));
    printf("\n");
    printf("%f\n", drob);
    printf("\n");
    printf("\n");
    float sum = 0;
        for(int D = 0; D <= B; D++)
        {
            sum = sum + Factorial(D);
        }
    printf("sum factorial :%f", sum);
    float result = sum + drob ;
    printf("\n");
    printf("\n");
    printf(" result :%.1f", result);

            return 0;
}
