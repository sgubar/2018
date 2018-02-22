#include<stdio.h>

float power(int n) /* initiate the funktion of pow (pow of number 2)*/
{
    int i;/*initiate the integer value for cycle for */
  float s=2.0;/* initiate float value 2*/
    if(n==0)/* program check the pow if the pow is equal zero then the result will be 1*/
     {
     return s=1;
    }
       if(n>0)/*if the n greater than zero then we use cycle for to calculate the result*/
        {
        for(i=0;i<n-1;i++)
          {
            s=s*2.0;
           }
          return s; /*the result */
         }
           if(n<0)/* if the n less than zero then we use the same cycle for, but the pow that less than zero is equal to 1 divided by the postive pow*/
             {
             for(i=0;i>n+1;i--)
               {
             s=s*2.0;
               }
             return 1.0/s;/*The result*/
              }
}
int module(float c)/*The module function if the value is less to zero then we multiply this value by (-1) */
    {
        if(c>=0)
        {
        return c;
        }
            else
            {
            return c*(-1);/*The result*/
            }
    }
float summa(int n)/*The summa function  */
{
    int j;/* initiate the j value we use it for cylce for*/
   if(n>0)/*We check the value n if n is greater than zero */
    {
    int m=1;
    float k=0;
       for ( j=0;j<n;j++)
            {
               k=k+m*power(j);
                m++;
             }
    return k;/* The result */
     }
    if(n<0)/*We check the n value if n is less than zero  */
     {
       int m=-1;
        float k=0;
           for ( j=0;j>n;j--)
            {
              k=k+m*power(j);
               m--;
             }
        return k;
        }
        if(n==0)
         {
           float k=1;
          return k;
          }
}
int cub(int n)/* cube function  */
{
    return n*n*n;/*the result*/
}




