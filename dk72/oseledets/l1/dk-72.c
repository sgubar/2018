#include "dk.h"
#include <stdio.h>


int factorial(int A)
{
    int result = 1;
    for(int i = 1; i <= A; i++)
    {
        result *= i;
    }
    return result;
}
 float module( float number)
{
    if(number >= 0)
    {
        return number;
    }
    else
    {
        return number*(-1);
    }
}
