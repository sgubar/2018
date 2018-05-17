#ifndef lb_4_h
#define lb_4_h

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	float value;
	struct node* next;
	struct node* prev;
}node;

typedef struct ring
{
	int size;
	node* head;
}ring;

ring* CreateRing();

void AddTheElement(ring* temp_ring, float temp_value);

void EnterTheData(ring* temp_ring);

int IndexOfMin(ring* temp_ring);

void PrintTheRing(ring* temp_ring, int start_ind);

void DeleteTheRing(ring* temp_ring);

#endif
