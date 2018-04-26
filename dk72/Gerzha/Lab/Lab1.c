#include <stdio.h>

float power(float value, int power)
{
    float result = power;

    if (power == 0)
        result = 1;
    else if (power > 0)
    {
        for (power; power > 1; power--)
        {
            result = result * value;
        }
    }
    else
    {
        for(power; power < -1; power++)
        {
            result = result / value;
        }
    }
    return(result);
}

float factorial(int value)
{
    float result = value;
    for (value; value > 1; value--)
    {
        result = result * (value - 1);
    }
    return(result);
}

int main(void)
{
    float A;
    int B;
    int C;
    float result = 0;

    printf("Enter value of  A :\n ");
    scanf("%f", &A);
    printf("Enter value of B (should be positive or integer or 0):\n");
    scanf("%d", &B);
    if (B < 0)
    {
       printf("Error, B is < 0");
       return(0);
    }
    printf("Enter value of C (should be integer):\n");
    scanf("%d", &C);
    result = (power(A, 2) + power(B, 2))/(B + power(5, C)) + factorial(B);
    
    printf("The result is %f\n", result);
    return(0);
}