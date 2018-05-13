#include "dk_tool.h" 
#include <time.h>

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int cnt = atoi(argv[1]);
	bintree* bt = new_bintree();
	unsigned char c;
	for (int i = 0; i < cnt; ++i)
	{	
		c = rand()%100;
		add_node(bt, c);
		printf("added node %u\n", c);
		if(i%3==0){
			pbt_node s = pop_node(bt, c);
			printf("deleted %u\n", s->a);
			free(s);
		}
	}

	bt_print(bt);
	bt_free(bt);




	return 0;
}
















