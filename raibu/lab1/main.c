//var 4
#include "dk_tool.h"


int main(int argc, char const *argv[])
{
	arguments* in = malloc(sizeof(arguments));
	if(in==NULL){
		printf("not enough memory\n");
		exit(1);
	}
	enter_args(in);
	equation_var4(in); 
	print_result(in);
	free(in);
	return 0;
}




