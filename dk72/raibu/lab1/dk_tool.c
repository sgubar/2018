//dk_tool.c
#include "dk_tool.h"


void enter_args(arguments* in){
	printf("Please enter three arguments. All of them must be integers.\nenter A:");
	//scanf("%d",&(in->a));
	get_int(&(in->a));
	printf("enter B:");
	get_int(&(in->b));
	printf("enter C:");
	get_int(&(in->c));
}


void get_int(int* a){
	regex_t pattern;
	char* str = malloc(64);
	scanf("%s",str);
	regcomp(&pattern, "-?[0-9]+", REG_EXTENDED | REG_NOSUB);
	while(regexec(&pattern, str, 0, NULL, 0)){
		printf("Retry: ");
		scanf("%s",str);
	}
	*a = atoi(str);
	regfree(&pattern);
}


int fact(int num){

	int result = 1;
	for (int i = 0; i < num; ++i)
	{
		result*=i;
	}
	return result;
}

double powi(int num, int power){

	int result = 1;
	int apow = (power>=0)?power:-power; 

	if(power==0){return 1;}

	for (int i = 0; i < apow; ++i)
	{
		result*=num;
	}

	if(power<0){
		return divf(1.0,(double)result);
	}

	return result;
}

int addi(unsigned int a, ...){
	int result = 0;
	va_list args;
	va_start(args, a);
	while(a--){
		result+=va_arg(args, int);
	}
	va_end(args);
	return result;
}

int subi(unsigned int a, ...){
	va_list args;
	va_start(args, a);
	int result = va_arg(args, int);
	a--;
	while(a--){
		result-= va_arg(args, int);
	}
	va_end(args);
	return result; 
}

double addf(unsigned int a, ...){
	double result = 0;
	va_list args; 
	va_start(args, a);
	while(a--){
		result+=va_arg(args, double);
	}
	va_end(args);
	return result;
}

double subf(unsigned int a, ...){
	va_list args;
	va_start(args, a);
	double result = va_arg(args, double);
	a--;
	while(a--){
		result-= va_arg(args, double);
	}
	va_end(args);
	return result;
}

double divf(double num, double divisor){
	if(divisor == .0){
		printf("There's where you are wrong: %.2f not divisible by 0!\n", num);
		exit(1);
	}
	return num/divisor;
}
 

double cyclic_sum_pow2(int from, int to){
	double result=0;
	if(from==to)return powi(2,from*2);
	else if(from<to){
		for (int i = from; i <= to; ++i)
		{
			result+=powi(2,i+to);
		}
	}else{
		for (int i = from; i >= to; --i)
		{
			result+=powi(2,i+to);
		}
	}
	return result;
}

 
void equation_var4(arguments* in){
	in->q = addf(2, divf(addi(3, in->a, in->b, in->c), subi(3, 100, in->b, in->c)), cyclic_sum_pow2(0, in->a));
}


void print_result(arguments* in){
	printf("the result is %.3f\n", in->q);
}
