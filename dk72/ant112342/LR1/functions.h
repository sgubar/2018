#include<stdio.h>
float power(int n)
{
  int i;
  float s=2.0;
    if(n==0)
     {
     return s=1;
    }
       if(n>0)
        {
        for(i=0;i<n-1;i++)
          {
            s=s*2.0;
           }
          return s;
         }
           if(n<0)
             {
             for(i=0;i>n+1;i--)
               {
             s=s*2.0;
               }
             return 1.0/s;
              }
}
int module(float c)
    {
        if(c>=0)
        {
        return c;
        }
            else
            {
            return c*(-1);
            }
    }
float summa(int n)
{
  int j;
   if(n>0)
    {
    int m=1;
    float k=0;
       for ( j=0;j<n;j++)
            {
               k=k+m*power(i);
                m++;
             }
    return k;
     }
    if(n<0)
     {
       int m=-1;
        float k=0;
           for ( j=0;j>n;j--)
            {
              k=k+m*power(i);
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
int cub(int n)
{
    return n*n*n;
}



