#include "dk_tool.h" 

int main(int argc, char const *argv[])
{

	int cnt = atoi(argv[1]);
	single_linked_list* list = sll_new();
	for (int i = 0; i < cnt; ++i)
	{
		sll_append(list, new_char_node(getc(stdin)));
	}

	sll_print(list);
	//start__();
	printf("\n__SORTED__\n");
	sll_sort(list, 0, list->len -1);
	sll_print(list);
	sll_free(list);





	return 0;
}
















