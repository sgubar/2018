#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Lab_Work_1.1_Functions.h"


int factorial (int value)

           
{
    int l;
    int Result = 1;

    if (value > 0)

    {

      for( l=1; l <= value; l++ )

        {

            Result = Result*l;

        }

    }

    return Result;

}





int power(int base, int C)

{

  base = 5;

  int p;

  for (p = 1; C > 0; --C)

    p *= base;

  return p;

}
