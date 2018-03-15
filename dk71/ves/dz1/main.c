#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "dz1.h"

int main(){
 	
 int i, j, k;
 int matr1[2][2];
 int matr2[2][2];
 int matr[2][2];
 
 printf("\nVvedit' dvi matruzi\n\n");
 
 for ( i = 0; i < 2; i ++ )
 {
	for ( j = 0; j < 2; j ++ )
	 {
		printf ("matr1[%d][%d]=", i, j);
		scanf ("%d", &matr1[i][j]);
	 }
 }

		for ( i = 0; i < 2; i ++ )
		{
   			for ( j = 0; j < 2; j ++ )
			{
				printf ("%d ", matr1[i][j]);
   			}
   		  printf("\n");
		}



for ( i = 0; i < 2; i ++ )
 {
	for ( j = 0; j < 2; j ++ )
	 {
		printf ("matr2[%d][%d]=", i, j);
		scanf ("%d", &matr2[i][j]);
	 }
}

	for ( i = 0; i < 2; i ++ )
	{
   		for ( j = 0; j < 2; j ++ )
		{
			printf ("%d ", matr2[i][j]);
   		}
      printf("\n");
	}

printf("\n");


mnoz( matr1, matr2, matr);
  
  for (i = 0; i < 2; i++)
 {
 for (j = 0; j < 2; j++){
 
 printf("%d ", matr[i][j]);
 }
  printf("\n");
}
 return 0;
}
