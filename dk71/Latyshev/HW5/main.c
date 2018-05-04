#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <conio.h>



#include "circle.h"

#include "circle_array.h"









int main(void) 

{

	CircleArray *InstantArray = CreateArray(5); 

    Point Center = {2,4};    
	Point Radius ={1,3};   

    float search;
    int choice;

    Circle created_Circle = {&Center, &Radius}; 


    addElement(InstantArray, &created_Circle, SquareCircle(&created_Circle)); 


    FILE *file = fopen("D:/work/test.json", "a+"); 


	writeArrayToJSON(file, InstantArray); 


	fflush(file);
    fclose(file); 


    quick_sort(InstantArray, 0, InstantArray->count-1);
    
	FILE *file2 = fopen("D:/work/test2.json", "a+");

	writeArrayToJSON(file2, InstantArray);


	fflush(file2);
	fclose(file2);

while(1)

		{

		printf("\tEnter the area of circle:"); 

		scanf("\n%f", &search);

		choice = line_search(InstantArray, search);

		printf("\nPosition of a triangle = %d\n\n", choice);

		}
		
	freeArray(InstantArray);

    return 0;



}
