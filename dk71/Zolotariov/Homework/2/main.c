#include "dk_tool.h"
#include <stdio.h>

int main() {
	Point* point1 = new_Point(1, 1);
	Point* point2 = new_Point(2, 2);
	Point* point3 = new_Point(1, 0);
	Point* point4 = new_Point(3, 2);
	Point points[4] = { point1, point2, point3, point4};
	Trapeze* trapeze1 = new_TrapezePointEnum(point1, point2, point3, point4);
	Trapeze* trapeze2 = new_TrapezePointArray(points);
	Trapeze* trapeze3 = new_TrapezePointCoord(1, 2, 4, 2, 3, 5, 2, 5);
	print_Trapeze(trapeze3);
}
