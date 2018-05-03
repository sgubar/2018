#include "myfunc.h"

void matrixmult(int y, int x, int A[y][x], int Ny, int Nx, int B) {
	A[Ny][Nx] *= B;
}