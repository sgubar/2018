#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "dk_tool.h"

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "RUS");
    float A,B,C,result;
    printf("¬ведите значение переменной A : ");
    scanf("%f",&A);
    printf("¬ведите значение переменной B : ");
    scanf("%f",&B);
    printf("¬ведите значение переменной C : ");
    scanf("%f",&C);

    if(B + square(C) == 0)
    {
       printf("ќшибка!\n");
        return 1;
    }

    result = ((A * B)/(B + square(C))) + sumf(B);

    printf("–езультат: %.3f", result);

    return 0;
}
