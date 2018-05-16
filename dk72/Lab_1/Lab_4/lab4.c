#include "lab4.h"

List* CreateList()
{
	List* temp_list = malloc(sizeof(List));
	
	temp_list->size = 0;
	temp_list->head = temp_list->tail = NULL;
	
	return temp_list;
}

void AddElement(List* temp_list, float temp_data) 
{
    node* temp = malloc(sizeof(node));

    temp->data = temp_data;
    temp->next = NULL;
    temp->prev = temp_list->tail;
    if (temp_list->tail) temp_list->tail->next = temp;
 
    temp_list->tail = temp;
 
    if (temp_list->head == NULL) temp_list->head = temp;

    temp_list->size++;
}

void DataInput(List* temp_list)
{
	int quantity;
	
	do
	{
		printf("Enter quantity of elements: ");
		scanf("%d", &quantity);
	}while(quantity < 1);
	int i;
	for(i = 0; i < quantity; i++)
	{
		float a;
		scanf("%f", &a);
		AddElement(temp_list, a);
	}
}

void PrintList(List* temp_list) 
{
    node* temp = temp_list->head;
	
	while(temp)
	{
        printf("%.1f ", temp->data);
        temp = temp->next;
    }
    printf("\n");
	printf("%.1f ", temp_list->head->data);
    temp = temp_list->tail->prev;
	
	while(temp->prev)
	{
        printf("%.1f ", temp->data);
        temp = temp->prev;
    }
	printf("%.1f ", temp_list->tail->data);
    printf("\n");
}

void DeleteList(List* temp_list) 
{
    node* temp = temp_list->head;
    node* temp_next = malloc(sizeof(node));
    while (temp) {
        temp_next = temp->next;
        free(temp);
        temp = temp_next;
    }
    free(temp_list);
    temp_list = NULL;
}


