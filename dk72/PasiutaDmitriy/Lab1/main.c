#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main(int argc, char *argv[]) {

    printf("\t\t  HELLO! \n\n");
    float A,B,C,Result;
    printf("\t Put A value : ");
    scanf("%f",&A);
    printf("\n\t Put B value :");
    scanf("%f",&B);
    printf("\n\t Put C value :");
    scanf("%f",&C);

    if(B + square(C) == 0)
    {
       printf("ERROR!f\n");
        return 1;
    }

    Result = ((A * B)/(B + square(C))) + Factorialsum(B);

    printf("Result: %.3f", Result);

    return 0;
}
