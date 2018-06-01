#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "area.h"





Point *copyPoint(Point *Point);



Sqere *create_sqere(Point *A, Point *B, Point *C,Point *D){
	
	Sqere *result = NULL;
	if ((NULL !=A)&&(NULL !=B)&&(NULL !=C)&&(NULL !=D)){
		
		result = (Sqere*)malloc(4*sizeof(Sqere));
		if (result != NULL){
			result->A = copyPoint(A);
			result->B = copyPoint(B);
			result->C = copyPoint(C);
			result->D = copyPoint(D);
			
		}
		
	}
		return result; 
}


 void free_all(Sqere *Sqere){
 	
 if (Sqere != NULL){
 		free(Sqere->A);
 		free(Sqere->B);
 		free(Sqere->C);
 		free(Sqere->D);
	}
 	free(Sqere);
 	
 	
 }

double area (Sqere *Sqere){
	
	double side ;
			if (Sqere != NULL){
				side = sqrt(pow((Sqere->B->y-Sqere->A->y),2)+pow((Sqere->B->x-Sqere->A->x),2));
				
			}
	
	
	return side*side;
	
}
Point *copyPoint(Point *aPoint)
{
	Point *result = (Point*)malloc(sizeof(Point));
	if (NULL != result)
	{
		result->x = aPoint->x;
		result->y = aPoint->y;
	}
	
	return result;
}

