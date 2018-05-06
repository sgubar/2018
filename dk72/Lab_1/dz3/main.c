#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <conio.h>
#include "circle.h"
#include "circle_array.h"

int main() 
{
	CircleArray *InstantArray = CreateArray(3); //init array of figures
    Point Center = {2,4};    // center of circle
	Point Radius ={1,3};   // radius
    Circle created_Circle = {&Center, &Radius}; // creating circle
    addElement(InstantArray, &created_Circle); // add 
    FILE *file = fopen("circle.txt", "a+"); // creating .json file
	writeArrayToJSON(file, InstantArray); // writing array of figures to json
	fflush(file);
    fclose(file); // closing file
    freeArray(InstantArray); // delete array

	getch();
    return 0;
}
