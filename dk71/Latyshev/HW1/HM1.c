#include <stdio.h>
 #include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "dk_tool.h"

int biennial_transformer(void)
{
    char ch;
    long long n;
    
    do
    {
        n=0;
        printf("Input a number in binary arithmetic");
        while((ch=getchar())=='0' || ch=='1')
        {
            n<<=1;
            if(ch=='1') n++;
        }
        printf("Now it was converted into decimal numerical system :%lld\n",n);
    }while(ch==10);
     
 }
