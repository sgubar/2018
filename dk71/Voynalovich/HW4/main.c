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




    Circle created_Circle = {&Center, &Radius}; 

    addElement(InstantArray, &created_Circle, SquareCircle(&created_Circle)); 

    FILE *file = fopen("D:/work/test.json", "a+"); 

	writeArrayToJSON(file, InstantArray); 

	fflush(file);

    fclose(file); 

    
   insertion_sort(InstantArray);

	FILE *file2 = fopen("D:/work/test2.json", "a+");

	writeArrayToJSON(file2, InstantArray);

	fflush(file2);

	fclose(file2);

	freeArray(InstantArray);

    return 0;

}
