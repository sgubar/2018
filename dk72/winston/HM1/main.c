#include <stdio.h>
#include <stdlib.h>
#include "dk_matrix_minus.h"

int main(int argc, char const *argv[])
{

	int x,y; /* Length of arrays and columns */
	printf("\nEnter arrays and columns for matrix:\n");
	scanf("%d %d",&x,&y);
	int *f = matr(x,y), *a = matr(x,y);
	printf("\nThe result of minus matrix is:\n");

    prmin(f,a,x,y); /* Conclusion of minus matrix */

	return 0;
}
