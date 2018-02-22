#include<stdio.h>
#include"functions.h"



int main(int argc,char* argv[])
{
int a,b,c;/*interger values that will be used*/
float q;/* the result*/
printf("Enter the a number:\n");
scanf("%d",&a);/*This comand is used for enter the value a*/
printf("Enter the b number:\n");
scanf("%d",&b);/*This comand is used for enter the value b */
printf("Enter the c number:\n");
scanf("%d",&c);/* This comand is used foe enter the value c */
if(c==0)/*This cycle is used for checking the c value (if the c equal to 0 then program ceases to work ) */
{
    printf("OOh No it's impossible\n");
    return 0;
}
 q=(module((a*c)-b)/(float)cub(c))*summa(a);/*The operations (we use the functions )*/

printf("The variable q is %.2f\n",q); /*program print the result */
}

