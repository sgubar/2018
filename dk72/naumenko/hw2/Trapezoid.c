#include <stdlib.h>
#include <math.h>
#include "Trapezoid.h"

Trapezoid *createTrapezoid(Point A, Point B, Point C, Point D) {
	if(!((A.y == B.y && C.y == D.y) || (A.x == D.x && C.x == B.x))) {
		return 0;
	}

	Trapezoid *trap = malloc(sizeof(Trapezoid));
	trap->A = &A;
	trap->B = &B;
	trap->C = &C;
	trap->D = &D;
	
	Point F = {C.x, A.y};
	trap->Altitude = Distantion(C, F);

	trap->AB = Distantion(A, B);
	trap->CD = Distantion(C, D);

	return trap;
}

float Distantion(Point A, Point B) {
	float dx = (A.x) - (B.x);
	float dy = (A.y) - (B.y);
	float dist = sqrt((dx * dx + dy * dy));
	return dist;
}

float Square(Trapezoid *trap) {
	return trap->Altitude * (trap->AB + trap->CD)/2;
}

/*void deleteTrapezoid(Trapezoid *trap) {
	if(trap) {
		trap->A = NULL;
		trap->B = NULL;
		trap->C = NULL;
		trap->D = NULL;
		trap->Altitude = 0;
		trap->AB = 0;
		trap->CD = 0;
	}
}*/