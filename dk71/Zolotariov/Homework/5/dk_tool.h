#ifndef DK_TOOL_H
#define DK_TOOL_H
#include <stdio.h>

typedef struct {
	int x;
	int y;
} Point;

typedef struct {
	Point* points[4];
} Trapeze;

typedef struct {
	int capacity;
	Trapeze** array;
} TrapezeArray;

Trapeze* new_TrapezePointArray(Point* points[4]);
Trapeze* new_TrapezePointEnum(Point* first, Point* second, Point* third, Point* fourth);
Trapeze* new_TrapezePointCoord(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
void del_Trapeze(Trapeze* trapeze);
void print_Trapeze(Trapeze* trapeze);
Point* new_Point(int x, int y);
TrapezeArray* new_Array(int capacity);
int InsertElem(TrapezeArray* trapezeArray, Trapeze* trapeze, int index);
int AddElem(TrapezeArray* trapezeArray, Trapeze* trapeze);
void del_Array(TrapezeArray* trapezeArray);
void WriteArrayToFile(FILE** file, TrapezeArray* trapezeArray);
float GetArea(Trapeze* trapeze);
int BinarySearñh(TrapezeArray* arr, Trapeze* trapeze, int area, int start, int end);
void ShellSort(TrapezeArray* arr, int n);
void PrintArr(TrapezeArray* arr);



#endif 
