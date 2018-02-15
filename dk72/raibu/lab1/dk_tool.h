//dk_tool.h


#ifndef __DK_TOOL_H
#define __DK_TOOL_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <regex.h>

typedef struct arguments{									//struct for equation variables
int a,b,c;
double q;
}arguments;

void enter_args(arguments* in); 
void get_int(int* a);							//prompt for input A,B,C
int fact(int num);											//factorial
double powi(int num, int power);							//integer power
int addi(unsigned int a, ...);								//integer addition
int subi(unsigned int a, ...);								//integer substraction
double addf(unsigned int a, ...);							//floating point addition
double subf(unsigned int a, ...);							//floating point substraction
double divf(double num, double divisor);					//floating point division
//int cyclic_sum(int from, int to, int (*p)(...), int _argc, ...);
//CUSTOM FUNCTION AND ARGUMENTS QUANTITY NOT WORKING WITHOUT ASSEMBLY
double cyclic_sum_pow2(int from, int to);					//sum of function 2^x values from & to some value
void equation_var4(arguments* in);							//4 variant formula
void print_result(arguments* in);							//print calculated value

#endif












