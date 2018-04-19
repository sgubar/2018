#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "sort.h"










//  считать буфер отправить на сортировку 

void sort_bubble(ArraySqere *array ){
	int i,j; int Ax,Ay,Bx,By,Cx,Cy,Dx,Dy; 
	int *p;
	clock_t time;
	time = clock();
	 for(i = 1; i < array->counter; i++){
        for(j = 0; j < array->counter - i; j++){
            if(area(array->sqere[j]) > area(array->sqere[j+1])){
                			 p = array->sqere[j];
				             array->sqere[j] = array->sqere[j+1]; 
						     array->sqere[j+1] = p;
            }}} 
			
			time = clock() - time;
            printf(" Time bubble %f sec\n", (double)time/CLOCKS_PER_SEC);       
                   
       		
}

void shell_sort(ArraySqere *array){
   int i, j, step;
    int *buffer;
    clock_t time;
	time = clock();
    for (step = array->counter / 2; step > 0; step /= 2){
        for (i = step; i < array->counter; i++)
        {
            buffer = array->sqere[i];
            for (j = i; j >= step; j -= step)
            {
                if (area(buffer) < area(array->sqere[j - step])){
			        array->sqere[j] = array->sqere[j - step];}
                else{
                    break;}
            
            array->sqere[j - step] = buffer;
        }
}
}
	time = clock() - time;
    printf(" Time Shell(sort) %f sec\n", (double)time/CLOCKS_PER_SEC);  
}


int binary_find(ArraySqere *array, int serch)
{
int m, left, right;
left = 0; right = array->counter-1;
while (1)
 {
    if (left > right) return (-1); // значение не найдено
    m = left + (right - left) / 2;
    if (area(array->sqere[m]) < serch) left = m + 1;
    if (area(array->sqere[m]) > serch) right = m - 1;
    if (area(array->sqere[m]) == serch) return m;
 }
}


