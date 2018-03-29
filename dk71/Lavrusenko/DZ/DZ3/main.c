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
int i=0;
int gd = DETECT;
int gm;
char string [64];
FILE *file = fopen("D:\\Lavrusenko\\DZ\\DZ2\\test\\area.txt","r");
     
	 while( !feof(file) ) { 
     fscanf( file, "%c", &string[i] ); 
     i++;
   } 
fflush(file);
 fclose(file);

initgraph(&gd, &gm, "D:\\Lavrusenko\\DZ\\DZ2\\test\\BGI");
  rectangle(200,200,400,400);
 outtextxy(100,100,string);
  getch();
   closegraph();

 
free_all(ABCD);
	
getch();	
	return 0;
	
}

