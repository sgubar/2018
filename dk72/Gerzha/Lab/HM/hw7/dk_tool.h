#ifndef __SLL_RABU
#define __SLL_RABU
#include <stdlib.h>
#include <stdio.h>
#include <regex.h>

#define CHNULL(x) if(x==NULL){printf("INVALID MALLOC\n");return NULL;}

typedef struct tag_node{
	int a;
	struct tag_node* ch[2];
}node, *pnode;

typedef struct tag_bintree{
	pnode head;
	int length;
}bintree;

pnode new_bt_node(int x);
bintree* new_bintree();
pnode bin_search(bintree* bt, int d);
void add_node(bintree* bt, int d);
void bt_print(bintree* in);
int get_int(void);
pnode pop_node(bintree* bt, int d);
void bt_free(bintree* in);


#endif


















