#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "dz1.h"


 int mnoz( int matr1[2][2], int matr2[2][2], int matr[2][2])
{	
		int i=0, j=0, k=0;
		for ( i = 0; i < 2; i ++ )
 		{
			for ( j = 0; j < 2; j ++ )
	 		{
	 			matr[i][j] = 0;
     			for (k = 0; k < 2; k++)
 					matr[i][j] += matr1[i][k] * matr2[k][j];
  			}
		}
  	
} 


