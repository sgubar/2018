#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int fac(int A_f)
{
 int fac=1;
int i;
for(i=1; i<=A_f; i++)
{
    fac=fac*i;
}
 return fac;
}

int mod(int A_m, int B_m)
{
    int mod_AB= 2*A_m+B_m;
if (mod_AB < 0)
{
        mod_AB = -mod_AB;
        return -mod_AB;
}
return mod_AB;
}
double REPLY(double A_f, int mod_AB)
{
    double REP;
    REP = A_f/mod_AB;
return REP;
}
