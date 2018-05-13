#include "dk_tool.h" 

int main(int argc, char const *argv[])
{

	int cnt = atoi(argv[1]);
	bintree* bt = new_bintree();
	for (int i = 0; i < cnt; ++i)
	{	
		add_node(bt, (double)i);
		printf("added node %d\n", (char)i);
		if(i%3==0){
			pbt_node c = pop_node(bt, (char)i);
			printf("deleted %d\n", c->a);
			free(c);
		}
	}

	bt_print(bt);
	bt_free(bt);




	return 0;
}
















