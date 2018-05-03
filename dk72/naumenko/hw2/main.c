#include "Trapezoid.h"
#include <stdio.h>
#include <stdlib.h>
#define n 2

int main() {
	Trapezoid *t[n];
	Point points[n][4] = {
		{{4, 4}, {10, 4}, {8, 9}, {4, 9}}, {{4, 4}, {10, 4}, {5, 9}, {3, 9}}};

	for (int i = 0; i < n; i++) {
		t[i] = createTrapezoid(
			points[i][0], points[i][1], points[i][2], points[i][3]);
		printf(
			"(%d; %d), (%d; %d), (%d; %d), (%d; %d)\nРешение: %g см^2\n\n",
			points[i][0].x,
			points[i][0].y,
			points[i][1].x,
			points[i][1].y,
			points[i][2].x,
			points[i][2].y,
			points[i][3].x,
			points[i][3].y,
			Square(t[i]));
	}
	for (int i = 0; i < n; i++) {
			//deleteTrapezoid(t[i]);
			free(t[i]);
	}
	
	return 0;
}
