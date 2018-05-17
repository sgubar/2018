#include "lb_4.h"

ring* CreateRing()
{
	ring* temp_ring = malloc(sizeof(ring));
	
	temp_ring->size = 0;
	
	temp_ring->head = NULL;
	
	return temp_ring;
}

void AddTheElement(ring* temp_ring, float temp_value) 
{
    node* temp = malloc(sizeof(node));

    temp->value = temp_value;
	
	if(temp_ring->head == NULL)
	{
		temp_ring->head = temp;
		temp->next = temp->prev = temp;
	}
	else
	{
		node* temp_prev = temp_ring->head->prev;
		temp->next = temp_ring->head;
		temp_ring->head->prev = temp;
		temp->prev = temp_prev;
		temp_prev->next = temp;
	}

    temp_ring->size++;
}

void EnterTheData(ring* temp_ring)
{
	int kolvo;
	do
	{
		printf("Vvedite kolichestvo elementov kolca: ");
		scanf("%d", &kolvo);
	}while(kolvo < 1);
	
	for(int i = 0; i < kolvo; i++)
	{
		float a;
		scanf("%f", &a);
		AddTheElement(temp_ring, a);
	}
}

int IndexOfMin(ring* temp_ring)
{
	int temp_index;
	
	float min = temp_ring->head->value;
	
	node* temp = temp_ring->head;
	
	for(int i = 0; i < temp_ring->size; i++)
	{
        if(temp->value < min) 
		{
			min = temp->value;
			temp_index = i;
		}
        temp = temp->next;
    }
	
	printf("Minimalniy element: %.1f\nIndex minimalnogo elementa: %d\n", min, temp_index);
	
	return temp_index;
}

void PrintTheRing(ring* temp_ring, int start_ind) 
{
    node* temp = temp_ring->head;
	
	for(int i = 0; i < start_ind; i++)
        temp = temp->next;
	
	for(int i = 0; i < temp_ring->size + 5; i++)
	{
		printf("%.1f ", temp->value);
		temp = temp->next;
	}
	
    printf("\n");
}

void DeleteTheRing(ring* temp_ring) 
{
    node* temp = temp_ring->head;
    node* temp_next = malloc(sizeof(node));
    for(int i = 0; i < temp_ring->size; i++)
	{
        temp_next = temp->next;
        free(temp);
        temp = temp_next;
    }
    free(temp_ring);
    temp_ring = NULL;
}

