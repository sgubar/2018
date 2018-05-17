#ifndef DK_TOOL_H
#define DK_TOOL_H

typedef struct {
	int x;
	int y;
} Point;

typedef struct {
	Point* first;
	Point* second;
	Point* third;
	Point* fourth;
} Trapeze;

Trapeze* new_TrapezePointArray(Point* points[4]);
Trapeze* new_TrapezePointEnum(Point* first, Point* second, Point* third, Point* fourth);
Trapeze* new_TrapezePointCoord(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
void del_Trapeze(Trapeze* trapeze);
void print_Trapeze(Trapeze* trapeze);
Point* new_Point(int x, int y);


#endif 
