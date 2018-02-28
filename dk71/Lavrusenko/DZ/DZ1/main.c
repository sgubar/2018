#include "convert.h"



int main(int argc, char *argv[]) {
	char *heksakod [64];
	printf("Enter heksa code :\n");
	scanf("%s",&heksakod);
	printf("%s(16)=%d(10)",heksakod,convertation(heksakod) );
	
	
	
	
	return 0;
}
