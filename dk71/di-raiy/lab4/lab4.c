#include "lab4.h"

void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d; ", current->val);
        current = current->next;
    }
}

void bubbleSort(node_t * head)
{   bool sort = false;
    while(!sort)
    {
        sort = true;
    node_t * current = head;
    while(current != NULL)
        {
			if (current->next != NULL && current->val > current->next->val)
			{
			    int tmp = current->val;
				current->val = current->next->val;
				current->next->val = tmp;
				sort = false;

			}
            current = current->next;
		}

    }
}
void removed(node_t *head)
{
    node_t * current = head;

    while (current != NULL) {
        if(current->next != NULL && current->val == current->next->val)
        {
            current->next = current->next->next;
        }
        current = current->next;
    }
}
