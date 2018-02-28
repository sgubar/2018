#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "area.h"



void check_enter (struct point *arry){
	start:
	
		for(i=0;i<4;i++){
		printf("Point[%d] x=",i+1);
		scanf ("%d",Point[i].x);
		printf(" y=");
		scanf("%d",Point[i].y);
		printf("\n ");}
	
	
	
	
	
	if((Point[2].x-Point[1].x)==(Point[1].y-Point[0].y)){
		if((Point[3].x-Point[2].x)==(Point[2].y-Point[1].y)){
			printf("correct");
		}else {
		printf("incorrect"); goto start;
	}
		}else {
		printf("incorrect"); goto start;
	}
	
	
}


double  length_sqere (struct side *arry){
	double result;
	result = sqrt(pow((sides.Point[1].x-sides.Point[0].x),2)-pow((sides.Point[1].y-sides.Point[0].y),2));
	
	return result*result;
}

 void free_all(Point *points){
 	int i;
 	for(i=0;i<4;i++){
 		free(points[i].x);
 		free(points[i].y);
	 }
 	free(Point);
 	
 	
 }


