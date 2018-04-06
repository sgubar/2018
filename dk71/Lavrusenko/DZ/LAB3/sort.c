#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "sort.h"




//  считать буфер отправить на сортировку 

void sort_bubble(ArraySqere *array ){
	int i,j; int Ax,Ay,Bx,By,Cx,Cy,Dx,Dy; 
	clock_t time;
	time = clock();
	 for(i = 1; i < array->counter; i++){
        for(j = 0; j < array->counter - i; j++){
            if(area(array->sqere[j]) > area(array->sqere[j+1])){
                Ax=array->sqere[j]->A->x; Ay=array->sqere[j]->A->y; Bx=array->sqere[j]->B->x; By=array->sqere[j]->B->y; Cx=array->sqere[j]->C->x; Cy=array->sqere[j]->C->y; Dx=array->sqere[j]->D->x; Dy=array->sqere[j]->D->y;
                array->sqere[j]->A->x = array->sqere[j+1]->A->x; array->sqere[j]->A->y = array->sqere[j+1]->A->y;      array->sqere[j]->B->x = array->sqere[j+1]->B->x; array->sqere[j]->B->y = array->sqere[j+1]->B->y;     array->sqere[j]->C->x = array->sqere[j+1]->C->x; array->sqere[j]->C->y = array->sqere[j+1]->C->y;     array->sqere[j]->D->x = array->sqere[j+1]->D->x; array->sqere[j]->D->y = array->sqere[j+1]->D->y;
                array->sqere[j+1]->A->x = Ax;  array->sqere[j+1]->A->y = Ay; array->sqere[j+1]->B->x = Bx;  array->sqere[j+1]->B->y = By;    array->sqere[j+1]->C->x = Cx;  array->sqere[j+1]->C->y = Cy;     array->sqere[j+1]->D->x = Dx;  array->sqere[j+1]->D->y = Dy;
            }}} 
			
			time = clock() - time;
            printf(" Time bubble %f sec\n", (double)time/CLOCKS_PER_SEC);       
                   
       		
}



void sort_choice (ArraySqere *array){
	
int i;
int j;	
int min_i;	
int Ax,Ay,Bx,By,Cx,Cy,Dx,Dy; 
	clock_t time;
	time = clock();	
	for (i = 1; i < array->counter - 1; i++) {
         min_i = i;
	for (j = i + 1; j < array->counter; j++) {
		if ( area(array->sqere[j]) > area(array->sqere[min_i])) {
			min_i = j;
		}
	}
				Ax=array->sqere[j]->A->x; Ay=array->sqere[j]->A->y; Bx=array->sqere[j]->B->x; By=array->sqere[j]->B->y; Cx=array->sqere[j]->C->x; Cy=array->sqere[j]->C->y; Dx=array->sqere[j]->D->x; Dy=array->sqere[j]->D->y;
                array->sqere[j]->A->x = array->sqere[min_i]->A->x; array->sqere[j]->A->y = array->sqere[min_i]->A->y;      array->sqere[j]->B->x = array->sqere[min_i]->B->x; array->sqere[j]->B->y = array->sqere[min_i]->B->y;     array->sqere[j]->C->x = array->sqere[min_i]->C->x; array->sqere[j]->C->y = array->sqere[min_i]->C->y;     array->sqere[j]->D->x = array->sqere[min_i]->D->x; array->sqere[j]->D->y = array->sqere[min_i]->D->y;
                array->sqere[min_i]->A->x = Ax;  array->sqere[min_i]->A->y = Ay; array->sqere[min_i]->B->x = Bx;  array->sqere[min_i]->B->y = By;    array->sqere[min_i]->C->x = Cx;  array->sqere[min_i]->C->y = Cy;     array->sqere[min_i]->D->x = Dx;  array->sqere[min_i]->D->y = Dy;
            
}
	time = clock() - time;
            printf(" Time choice %f sec \n", (double)time/CLOCKS_PER_SEC); 	
	

}

void sort_pass(ArraySqere *array ){
	
	int pass, j,i ;
    int Ax,Ay,Bx,By,Cx,Cy,Dx,Dy;
    clock_t time;
	time = clock();	
	for (pass = 0; pass < array->counter-1; pass++){
		for (j = pass+1; j < array->counter; j++){
			if ( area(array->sqere[pass])>area(array->sqere[j])){
				Ax=array->sqere[j]->A->x; Ay=array->sqere[j]->A->y; Bx=array->sqere[j]->B->x; By=array->sqere[j]->B->y; Cx=array->sqere[j]->C->x; Cy=array->sqere[j]->C->y; Dx=array->sqere[j]->D->x; Dy=array->sqere[j]->D->y;
      array->sqere[j]->A->x = array->sqere[pass]->A->x; array->sqere[j]->A->y = array->sqere[pass]->A->y;      array->sqere[j]->B->x = array->sqere[pass]->B->x; array->sqere[j]->B->y = array->sqere[pass]->B->y;     array->sqere[j]->C->x = array->sqere[pass]->C->x; array->sqere[j]->C->y = array->sqere[pass]->C->y;     array->sqere[j]->D->x = array->sqere[pass]->D->x; array->sqere[j]->D->y = array->sqere[pass]->D->y;
   			array->sqere[pass]->A->x = Ax;  array->sqere[pass]->A->y = Ay; array->sqere[pass]->B->x = Bx;  array->sqere[pass]->B->y = By;    array->sqere[pass]->C->x = Cx;  array->sqere[pass]->C->y = Cy;     array->sqere[pass]->D->x = Dx;  array->sqere[pass]->D->y = Dy;
            
			
			
			}
		}
	}
	time = clock() - time;
            printf(" Time pass %f  sec\n", (double)time/CLOCKS_PER_SEC); 

}
