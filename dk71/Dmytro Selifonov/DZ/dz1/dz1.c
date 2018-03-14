#include <stdio.h>
#include <stdlib.h>
#include "dktool.h"
int kilkist_sliv();

int main(int argc, char *argv[]) {
	int words = 0;
	words = kilkist_sliv();
	printf("words = %d\n",words);
	return 0;
}
