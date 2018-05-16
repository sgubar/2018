#ifndef lab4_h
#define lab4_h

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	float Value;
	struct node* next;
	struct node* prev;
}node;

typedef struct list
{
	int size;
	node* head;
	node* tail;
	
}list;


list* CreateList();

void AddTheElement(list* thelist, float value);

void PrintTheList(list* thelist);

void DeleteList(list* thelist);

#endif
