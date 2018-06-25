#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <conio.h>
#include "circle.h"

int main() 
{
	CircleArray *InstantArray = CreateArray(2); //init array of figures
    Point Center = {2,4};    // center of circle
	Point Radius ={1,3};   // radius
    Circle createCircle = {&Center, &Radius}; // creating circle
    addElement(InstantArray, &createCircle); // add 
    FILE *file = fopen("circles.json", "a+"); // creating .json file
	writeArrayToJSON(file, InstantArray); // writing array of figures to json
	fflush(file);
    fclose(file); // closing file
    freeArray(InstantArray); // delete array

	getch();
    return 0;
}
