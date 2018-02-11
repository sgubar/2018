#include<stdio.h>
#include"functions.h"



int main(int argc,char* argv[])
{
int a,b,c;
float q;
scanf("%d",&a);
scanf("%d",&b);
scanf("%d",&c);
if(c==0)
{
    printf("OOh No it's impossible\n");
    return 0;
}
 q=(module((a*c)-b)/ (float)cub(c));

printf("The variable q is %.2f\n",q);
}

