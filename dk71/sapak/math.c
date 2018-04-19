#include "math.h"

double power(double x, int p) {
	double ret = 1.0;
	
	while (p--) ret *= x;
	return ret;
}

int factorial(int n) {
	int ret = 1;
	
	while (n) ret *= n--;
	return ret;
}

