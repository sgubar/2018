#include "dk_tool.h"

int factorial (int j)
{
    if(j > 1)
    {
        return j * factorial(j - 1);
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

float sumf(float a)
{
    float result = 0;
    int i;
    for(i = 0; i <= a; i++)
    {
       result += factorial(i);
    }
    return result;
}
