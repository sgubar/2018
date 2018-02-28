#include "dk_tool.h"
#include <stdio.h>
#include <math.h>

int factorial(int n)
{
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

int functsiaSumy(int chislo_A, int chislo_C, int (*Yfactorial)(int))
{
    int suma_A_D=0, chislo_D=0, suma_Q=0;
    for( int i=0;i<chislo_C;i++)
    {
        suma_A_D =chislo_A+chislo_D;
        suma_Q=suma_Q + Yfactorial(suma_A_D);
        chislo_D=chislo_D+1;
    }
    return suma_Q;
}
