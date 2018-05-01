#ifndef hw_6_h
#define hw_6_h

#include "libs.h"

typedef struct node
{
	float data;
	struct node* next;
	struct node* prev;
}node, *pnode;

typedef struct list
{
	int size;
	pnode head;
	pnode tail;
	
}list, *plist;

plist create_list();

void add_el(plist ae_list, float ae_data);

void print_list(plist pl_list);

void delete_list(plist dl_list);

pnode get_node(plist gn_list, int gn_ind);

void insert_el(plist ie_list, int ie_ind, float ie_data);

void add_el_to_beg(plist pb_list, float pb_data) ;

#endif