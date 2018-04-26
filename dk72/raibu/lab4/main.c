#include "dk_tool.h" 

int main(int argc, char const *argv[])
{
	if(argc !=2){
		printf("USAGE: ./main <infile>\n");
		exit(1);
	}

	
	FILE* fp = fopen(argv[1], "r");
	single_linked_list* list = sll_new();
	char c;
	while((c = getc(fp))!=EOF && c!= '\n'){
		sll_append(list, new_char_node(c));
	}
	sll_print(list);
	printf("%d\n", sll_len(list));

	int l = 0, r = sll_len(list)-1;
	while(r>=l){
		if(sll_get_index(list, r)->a == sll_get_index(list, l)->a){
			l++;r--;
			continue;
		}else{
			printf("NOTEQ\n");break;
		}
	}
	if(r<=l){
		printf("EQ\n");
	}

	sll_free(list);
	fclose(fp);




	return 0;
}
















