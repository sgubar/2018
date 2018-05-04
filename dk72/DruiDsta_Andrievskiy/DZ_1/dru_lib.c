#include "dru_lib.h"

void mn_m(int n, int m, int matr[n][m], int temp_n, int temp_m, int DR)
{
	matr[temp_n][temp_m] *= DR;
}
