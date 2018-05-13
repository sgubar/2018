#ifndef __SLL_RABU
#define __SLL_RABU
#include <stdlib.h>
#include <stdio.h>
#include <regex.h>

#define CHNULL(x) if(x==NULL){printf("INVALID MALLOC\n");return NULL;}

typedef struct __bt_node{
	double a;
	struct __bt_node* ch[2];
}bt_node, *pbt_node;

typedef struct __bt{
	pbt_node head;
	unsigned int len;
}bintree;

pbt_node new_bt_node(double x);
bintree* new_bintree();
pbt_node bin_search(bintree* bt, double d);
void add_node(bintree* bt, double d);
void bt_print(bintree* in);
double get_double(void);
pbt_node pop_node(bintree* bt, double d);
void bt_free(bintree* in);


#endif


















