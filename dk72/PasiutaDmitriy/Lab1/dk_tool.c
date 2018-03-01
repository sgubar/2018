//
// Created by dima on 21.02.18.
//

#include "dk_tool.h"

int Factorial (int j)
{
    if(j > 1)
    {
        return j * Factorial(j - 1);
    }
    else
    {
        return 1;
    }
};


float square(float a)
{
    return a * a;
};

float Factorialsum(float a)
{
    float result = 0;
    for(int i = 0; i <= a; i++)
    {
       result += Factorial(i);// result +factorial 0,1,2,....,i
    }
    return result;
}
