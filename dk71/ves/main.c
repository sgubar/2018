#include <stdio.h>
#include <stdlib.h>


#include "funk.h"

int main() {
	
	float a, b, c;
	
	printf("Vvedit` znachennya a, b, c\na=");
	scanf("%f", &a);
	printf("b=");
	scanf("%f", &b);
	printf("c=");
	scanf("%f", &c);
	
	float mnozResult, moduleResult, kubResult, divisionResult, eksResult, mnoz1Result;
	
	mnozResult=(mnoz(a,b,c));
	moduleResult = (module(mnozResult));
	kubResult=(kub(c));
	divisionResult = (division(moduleResult,kubResult));
	eksResult=(eks(a));
	mnoz1Result=mnoz1(divisionResult,eksResult);
	
	printf("result=%f\n", mnoz1Result);
	return 0;
	
}
