	

void sumamatrixAB(int verSide, int horSide, int* matrixAPoiner, int* matrixBPoiner, int* matrixCPoiner)
{
    int i, j;
    
    for(i = 0; i < verSide; i++)    
     {
    	    for(j = 0; j < horSide; j++)           	
     	     {
         	        matrixCPoiner[i*horSide+j] = matrixAPoiner[i*horSide+j] + matrixBPoiner[i*horSide+j];
       	 	 }
     }	
}

void scanmatrix(int verSide, int horSide, int* matrixAPoiner)
{
	 int i, j;
	 
  	 for(i = 0; i < verSide; i++)
 	   { 
 	       for(j = 0; j < horSide; j++)
	        {
	            printf("Enter [%d][%d] = ", i, j);
	            scanf("%d", &matrixAPoiner[i*horSide+j]);
 	        }
 	   }
}

void printmatrix(int verSide, int horSide, int* matrixAPoiner)
{
	 int i, j;
			 
 	 for(i = 0; i < verSide; i++) 
         {
        	 for(j = 0; j < horSide; j++)
              {
              		printf("\t%d ", matrixAPoiner[i*horSide+j]);
              }
   		     printf("\n\n\n");
         }
}
