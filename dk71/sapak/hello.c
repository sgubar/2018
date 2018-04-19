
#include "math.h"

int main() {
	
	setbuf(stdout, NULL);
	
	double A;
	printf("A=\n");
	
	if (scanf("%f", &A) != 1) {
		printf("invalid!\n");
		return 1;
	}
	
	int B;
	printf("B=\n");
	
	if (scanf("%d", &B) != 1 || B < 0) {
		printf("invalid!\n");
		return 1;
	}
	
	int C;
	printf("C=\n");
	
	if (scanf("%d", &C) != 1 || C < 0) {
		printf("invalid!\n");
		return 1;
	}
	
	
	double Q = (power(A, 2) + power(B, 2)) / (B + power(5, C)) + factorial(B);
	
	
	printf("Q=%.3f\n", Q);
	
	return 0;
}

