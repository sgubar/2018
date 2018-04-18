#include <stdio.h>
#include <stdlib.h>

#include "dk_tool.h"

int* matr(int x, int y){			//create new matr x*y
	int* m = malloc(x*y*sizeof(int)); //выделить память
	for (int i = 0; i < y; ++i) //итерация по столбцам
	{
		for (int j = 0; j < x; ++j) //итерация по строкам
		{
			printf("enter cell [%d][%d]\n", i,j); //запрошення вводу
			scanf("%d",(m+i*y+j)); //ввод
		}
	}
	
	return m; //возвращаем выделенную память

}

int* plus(int* first, int* second, int x, int y){ //возвращает сумму матриц
	int* out_matr = malloc(x*y*sizeof(int));
	for (int i = 0; i < y; ++i)
	{
		for (int j = 0; j < x; ++j)
		{

			*(out_matr+i*y+j) = *(first+i*y+j) + *(second+i*y+j); //matr[i][j] = *(matr + i*width + j)
		}
	}
	return out_matr; //возвращаем 
}


void print_matr(int* a, int x, int y){ //печатает матрицу
	for (int i = 0; i < y; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			printf("%4d", *(a+i*y+j));
		}
		printf("\n");
	}
}
