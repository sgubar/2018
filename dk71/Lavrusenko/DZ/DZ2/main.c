#include "area.h"
#include <stdlib.h>
#include <stdio.h>


int main()
{

	
Point A = {2,3};
Point B = {2,6};	
Point C = {5,6};
Point D = {5,3};	
Sqere *ABCD = create_sqere(&A,&B,&C,&D);

printf("\n");


FILE *file = fopen("area.txt","a");
fprintf(file,"Sqere is : %f",area(ABCD));
fflush(file);
fclose(file);

 
free_all(ABCD);
	
getch();	
	return 0;
	
}

