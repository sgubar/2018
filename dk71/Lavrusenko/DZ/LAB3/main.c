#include <stdio.h>
#include <stdlib.h>
#include "sqere_Array.h"
#include "sort.h"
#include "area.h"

int main(int argc, char *argv[]) {
	int i;
	int random;
	ArraySqere *array = createArray(5000);	
Point A = {2,3};
Point B = {2,6};	
Point C = {5,6};
Point D = {5,3};
	Sqere ABCD = {&A,&B,&C,&D};
	addElement(array,&ABCD);

	for(i=20;i<5000;i++){
		random = rand() % i + 1;
		A.x=random;  B.x=random; 	C.x=random+i;  D.x=random+i;
		A.y=random;  B.y=random+i;    C.y=random+i;  D.y=random;
		addElement(array,&ABCD);
	}
	FILE *file = fopen("D:\\Lavrusenko\\LAB3\\before.json", "a");
	
	wrireToJSON(file, array);
	fflush(file);
	fclose(file);
	
	sort_bubble(array);
	
	FILE *choice = fopen("D:\\Lavrusenko\\LAB3\\bubble.json", "a");
	
	wrireToJSON(choice, array);
		fflush(choice);
	fclose(choice);
	
	freeArray(array);
	getch();

	return 0;
}


