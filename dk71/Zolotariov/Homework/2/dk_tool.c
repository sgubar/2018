#include "dk_tool.h"
#include <stdio.h>

Point* new_Point(int x, int y) {
	Point* point = malloc(sizeof(*point));
	point->x = x;
	point->y = y;
	return point;
}

Trapeze* new_TrapezePointArray(Point* points[4]) {
	int i;
	for (i = 0; i < 4; i++) {
		if (points[i] == NULL) {
			printf("Point %d wasn't initialized\n Returning NULL", i);
			return NULL;
		}
	}
	Trapeze* trapeze = malloc(sizeof(*trapeze));
	trapeze->first = points[0];
	trapeze->second = points[1];
	trapeze->third = points[2];
	trapeze->fourth = points[3];
	return trapeze;
}

Trapeze* new_TrapezePointEnum(Point* first, Point* second, Point* third, Point* fourth) {
	Trapeze* trapeze = malloc(sizeof(*trapeze));
	trapeze->first = first;
	trapeze->second = second;
	trapeze->third = third;
	trapeze->fourth = fourth;
	return trapeze;
}

Trapeze* new_TrapezePointCoord(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	Trapeze* trapeze = malloc(sizeof(*trapeze));
	trapeze->first = new_Point(x1, y1);
	trapeze->second = new_Point(x2, y2);
	trapeze->third = new_Point(x3, y3);
	trapeze->fourth = new_Point(x4, y4);
	return trapeze;
}

void del_Trapeze(Trapeze* trapeze) {
	free(trapeze);
}

void print_Trapeze(Trapeze* trapeze) {
	printf("First point: %d %d\n", trapeze->first->x, trapeze->first->y);
	printf("Second point: %d %d\n", trapeze->second->x, trapeze->second->y);
	printf("Third point: %d %d\n", trapeze->third->x, trapeze->third->y);
	printf("Fourth point: %d %d\n", trapeze->fourth->x, trapeze->fourth->y);
}
