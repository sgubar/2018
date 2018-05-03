#pragma once

struct Point {
	int x, y;
};
typedef struct Point Point;

struct Trapezoid {
	Point *A, *B, *C, *D;
	float AB, CD, Altitude;
};
typedef struct Trapezoid Trapezoid;

Trapezoid *createTrapezoid(Point A, Point B, Point C, Point D);
float Square(Trapezoid *trap);
float Distantion(Point A, Point B);
//void deleteTrapezoid(Trapezoid *trap);