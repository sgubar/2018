#include "dk_tool.h" 
#include <time.h>
int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int cnt = atoi(argv[1]);
	bintree* bt = new_bintree();
	double k;
	for (int i = 0; i < cnt; ++i)
	{	
		k = (double)rand();
		add_node(bt, k);
		printf("added node %f\n", k);
		if(i%3==0){
			pbt_node c = pop_node(bt, k);
			printf("deleted %f\n", c->a);
			free(c);
		}
	}

	bt_print(bt);
	bt_free(bt);




	return 0;
}
















