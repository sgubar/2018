#include <stdio.h>
#include <stdlib.h>
#include "dru_lib.h"

int main(int argc, char *argv[])
{
	setlocale(0, "ukr");
	
	double a, b, c, d=0, result;
	printf("Ââåä³òü çì³íí³: \nA=");
	scanf("%lf",&a);
	printf("B=");
	scanf("%lf",&b);
	printf("C=");
	scanf("%lf",&c);
	
	result=formula(a, b, c, d);

	printf("result = %f\n", result);
	return 0;
}
