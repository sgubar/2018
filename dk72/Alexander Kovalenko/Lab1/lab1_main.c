//
//  main.c
//  lab1
//
//  Created by Alexander Kovalenko on 2/14/18.
//  Copyright © 2018 Alexander Kovalenko. All rights reserved.
//


#include <stdio.h>
#include "lab1_tool.h"


int main()
{
    int A,B,Q;
    printf("Input numbers A and B: \n");
    scanf("%d %d", &A, &B);
    Q=fctrl(A)/absl(2*A+B);        /*formula of calculation*/
        if(A<0)                    /*verification*/
        {
         printf("Not correct numbers \n");                
         return 0;
        }    
    printf("Q= %d\n",Q);        /*result*/
}
