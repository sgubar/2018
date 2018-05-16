#ifndef lab4_h
#define lab4_h

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	float data;
	struct node* next;
	struct node* prev;
}node;

typedef struct list
{
	int size;
	node* head;
	node* tail;
	
}List;

void DataInput(List* temp_list);
List* CreateList();
void AddElement(List* temp_list, float temp_data);
void PrintList(List* temp_list) ;
void DeleteList(List* temp_list);

#endif
