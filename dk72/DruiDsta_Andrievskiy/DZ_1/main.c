#include "dru_lib.h"
#include <stdio.h>

int main() {
	int n, m, i, j, DR;
	printf("Enter matrix parameters\n Length n=");
	scanf("%d", &n);
	if(n<0) n*=-1;
	printf("Ðeight m=");
	scanf("%d", &m);
	if(m<0) m*=-1;

	printf("Enter the multiplier :");
	scanf("%d", &DR);

	int matr[n][m];
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			printf("[%d][%d] =", i, j);
			scanf("%d", &matr[i][j]);
		}
	}
	i=0; j=0;
	
	printf("\nResult\n");
	do
	{
		do
		{
			mn_m(n, m, matr, i, j, DR);
			printf("[%d][%d] = %d\n", i, j, matr[i][j]);
			j++;
		}while(j!=m);
		i++; j=0;
	}while(i!=n);
	
	
	
	
	
	
	/*
	for (a = 0; a < y; a++) {
		for (b = 0; b < x; b++) {
			mn_m(y, x, arr, a, b, n);
			printf("[%d][%d] = %d\n", a, b, arr[a][b]);
		}
	}

*/
	return 0;
}
