#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lab_2.h"

int main(int argc, char *argv[]) {
	int n;
	enter(&n);
	buble_sort(n);
	insertion_sort(n);
	sort_chose(n);


	system ("pause");
	return 0;
}