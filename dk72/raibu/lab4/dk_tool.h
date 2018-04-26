#ifndef __SLL_RABU
#define __SLL_RABU
#include <stdlib.h>
#include <stdio.h>

typedef struct __sll_node{
	char a;
	struct __sll_node *next;
}char_node, *pchar_node;

typedef struct _sll
{
	pchar_node head;
	unsigned int len;
}single_linked_list;


pchar_node new_char_node(char in);
single_linked_list* sll_new();
pchar_node sll_get_index(single_linked_list* list, int n);
int sll_append(single_linked_list* list, pchar_node in);
pchar_node sll_remove(single_linked_list* list, int index);
int sll_insert(single_linked_list* list, pchar_node in, int index);
int sll_free(single_linked_list* list);
int sll_len(single_linked_list* in);
void sll_print(single_linked_list* in);
void sll_sort(single_linked_list* list, int first, int last);
void sll_swap(single_linked_list* list, int a, int b);
void start__();
#endif


















