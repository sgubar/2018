#include <stdio.h>
#include "dz2_array.h"
#include "dz4.h"

int main (){

	RactangleArray *theArray = createArray(5);

	Point A = { 0,0 };
	Point B = { 1,0 };
	Point C = { 1,1 };
	Point D = { 0,1 };
	Ractangle ABCD = { &A, &B, &C, &D };

	addElement(theArray, &ABCD);

	B.x = 5;
	C.x = 5;
	C.y = 5;
	D.y = 5;
	
	
	addElement(theArray, &ABCD);
	B.x = 4;
	C.x = 4;
	C.y = 2;
	D.y = 2;
	
	addElement(theArray, &ABCD);
	B.x = 48;
	C.x = 48;
	C.y = 7;
	D.y = 7;


	addElement(theArray, &ABCD);

	FILE *theFile = fopen("test.json", "w+");
	shell_sort(theArray);
	printSquare(theArray);
	writeArrayToJSON(theFile, theArray);

	fflush(theFile);
	fclose(theFile);
	
	while(1){
printf("Vedit' shukane znachennia:");
int i, find;
scanf("%i", &find);
i= binary_find(theArray,find);

if (i!=-1){
	
	break;
}


	freeArray(theArray);

	return 0;
}}
