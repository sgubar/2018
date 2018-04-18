#include "dk_tool.h"

int main(int argc, char const *argv[])
{
	
	int x,y;
	printf("enter sizes: [x y]\n");
	scanf("%d %d",&x,&y);
	int *a = matr(x,y), *b = matr(x,y);
	int* sum = plus(a, b, x, y);


	print_matr(a, x, y);
	printf("plus\n");
	print_matr(b, x, y);
	printf("equals\n");
	print_matr(sum, x, y);

	return 0;
}

















