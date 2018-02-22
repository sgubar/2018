//
//  lab1_tool.c
//  lab1
//
//  Created by Alexander Kovalenko on 2/15/18.
//  Copyright © 2018 Alexander Kovalenko. All rights reserved.
//


#include "lab1_tool.h"

int fctrl(int n)    /*factorial calculation*/
{
    int f,i;
    if(n<0) 
    {    
        return (-1);        /*factorial n<0 is not exist*/
    }
        else    
        {
            f=1;
            for(i=1; i<=n; i++)
            f=f*i;              
            
            return (f);
        }
}


int absl(int x)     /*absolute value of x */
{
    if (x>=0)
    {
        return(x);   
    }
        else
        {
            return(-x);
        }
}       
