#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int val;
    struct node * next;
 } node_t;

void print_list(node_t * head);
void bubbleSort(node_t * head);
void removed(node_t *head);
