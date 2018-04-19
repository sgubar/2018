#include <stdio.h>
#include <stdlib.h>
#include "sqere_Array.h"
#include "sort.h"
#include "area.h"

int main(int argc, char *argv[]) {
	int i;
	int random;
	int find;
	ArraySqere *array = createArray(5000);	
Point A = {0,0};
Point B = {0,0};	
Point C = {0,0};
Point D = {0,0};

	Sqere ABCD = {&A,&B,&C,&D};
	addElement(array,&ABCD);

	for(i=21;i<5000;i++){
		random = rand() % 10000 + 1;
		A.x=0;  B.x=0; 	C.x=random;  D.x=random;
		A.y=0;  B.y=random;    C.y=random;  D.y=0;

			
		addElement(array,&ABCD);
	}

	FILE *file = fopen("D:\\Lavrusenko\\LAB3\\before.json", "a");
	
	wrireToJSON(file, array);
		fflush(file);
	fclose(file);
	
	shell_sort(array);
	
	FILE *choice = fopen("D:\\Lavrusenko\\LAB3\\shell.json", "a");
	
	wrireToJSON(choice, array);
		fflush(choice);
	fclose(choice);
	
	while(1){
printf("Vedit' iskome zna4 :");
scanf("%i",&find);
i= binary_find(array,find);

if (i!=-1){
	
	break;
}
}
printf("element #%d\n", i);
printf("\"A\": {\"x\":%d,\"y\":%d},\n",array->sqere[i]->A->x,array->sqere[i]->A->y);
			printf("\"B\": {\"x\":%d,\"y\":%d},\n",array->sqere[i]->B->x,array->sqere[i]->B->y);
				printf("\"C\": {\"x\":%d,\"y\":%d},\n",array->sqere[i]->C->x,array->sqere[i]->C->y);
					printf("\"D\": {\"x\":%d,\"y\":%d}\n",array->sqere[i]->D->x,array->sqere[i]->D->y);

	freeArray(array);
getch();
system("pouse");
	return 0;
}


