#include "dk_tool.h" 
#include <time.h>
int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int cnt = atoi(argv[1]);
	bintree* bt = new_bintree();
	int k;
	for (int i = 0; i < cnt; ++i)
	{	
		k = rand();
		add_node(bt, k);
		printf("added node %d\n", k);
		if(i%3==0){
			pnode c = pop_node(bt, k);
			printf("deleted node %d\n", c->a);
			free(c);
		}
	}
    printf("printing by value+\n");
	bt_print(bt);
	bt_free(bt);




	return 0;
}
















