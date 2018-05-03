#include "myfunc.h"
#include <stdio.h>

int main() {
	int x = 0, y = 0, a = 0, b = 0, n = 0;
	printf("x =");
	scanf("%d", &x);
	printf("y =");
	scanf("%d", &y);

	printf("n =");
	scanf("%d", &n);

	int arr[y][x];
	for (a; a < y; a++) {
		for (b; b < x; b++) {
			printf("[%d][%d] =", a, b);
			scanf("%d", &arr[a][b]);
		}
		b = 0;
	}
	printf("\n\n");
	for (a = 0; a < y; a++) {
		for (b = 0; b < x; b++) {
			matrixmult(y, x, arr, a, b, n);
			printf("[%d][%d] = %d\n", a, b, arr[a][b]);
		}
	}

	return 0;
}