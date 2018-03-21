#include <stdio.h>
#include <stdlib.h>
#include "dk_matrix_minus.h"


int* matr(int x, int y)    /* function of enter matrix */
{

	int* m = malloc(x*y*sizeof(int));  /* Allocating memory for matrix */
	for (int i = 0; i < y; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			printf("enter cell [%d][%d]\n", i,j);
			scanf("%d",(m+i*y+j));
		}
		printf("\n");
	}

	return m;

}

void prm(int* a, int x, int y)      /* Сonclusion of matrix*/

{
	for (int i = 0; i < y; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			printf("%2d", *(a+i*y+j));
		}
		printf("\n");
	}

}

int* minuss(int* f, int* a, int x, int y) /* Function of minus matrix */
{


	int* m = malloc(x*y*sizeof(int)); /* Allocating memory for matrix */
	for (int i = 0; i < y; ++i)
	{
		for (int j = 0; j < x; ++j)
		{

			*(m+i*y+j) = *(f+i*y+j) - *(a+i*y+j); /* Formula of minus matrix 1 - matrix 2 */
		}
		printf("\n");
	}

	return m;
}


void prmin(int* f, int* a, int x, int y)        /* Conclusion of minus matrix */
{

	int* m = malloc(x*y*sizeof(int));
	for (int i = 0; i < y; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			*(m+i*y+j) = *(f+i*y+j) - *(a+i*y+j);
		}
		printf("\n");
	}
	for (int i = 0; i < y; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			printf("%2d", *(f+i*y+j));
		}
		if(i==y/2){
			printf(" - ");
		}else{
			printf("   ");
		}
		for (int j = 0; j < x; ++j)
		{
			printf("%2d", *(a+i*y+j));
		}
		if(i==y/2){
			printf(" = ");
		}else{
			printf("   ");
		}
		for (int j = 0; j < x; ++j)
		{
			printf("%2d", *(m+i*y+j));
		}
		printf("\n");

	}


}

