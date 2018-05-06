#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lab4.h"


int main()
{

node_t * head = NULL;
head = malloc(sizeof(node_t));
if (head == NULL) {
    return 1;
}
node_t * current = head;

int d = 0;
printf("skolko chisel?\n");
scanf("%d", &d);

for( int i = 0; i <d; i++)
{
   printf("chislo %d = ", i+1);
   scanf("%d", &current->val);
   current->next = malloc(sizeof(node_t));
   if(i < d-1)
     current = current->next;
    else
    current->next = NULL;
}

print_list(head);
bubbleSort( head);
printf("\n");
print_list(head);
removed(head);
printf("\n");
print_list(head);


}

