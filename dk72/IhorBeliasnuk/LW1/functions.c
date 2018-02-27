#include "functions.h"

float absolutValue(float val)
{
    return val < 0 ? -val : val;
};

float exponentation(float val, int exp)
{
    float res = val;

    if(exp == 0)
    {
        return 1;
    }

    for(int i = 1; i < exp; i++)
    {
        res *= val;
    }

    return res;
};

float sum(float val)
{
    float res = 0;

    if(val == 0)
    {
        return 0;
    }

    for(int i = 0; i <= val; i++)
    {
        res += exponentation(2, i);
    }

    return res;
};
