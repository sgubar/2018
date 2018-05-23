#include "list.h"
#include <stdlib.h>
#include <stdio.h>

//Nodes
Node *createNode(char value)
{
    Node *result = (Node *) malloc(sizeof(Node));
    
    result->value = value;
    result->next = NULL;
    
    return result;
}

void deleteNode(Node *node)
{
    if (NULL != node)
    {
        free(node);
    }
}

void printNode(Node *node)
{
    if(node != NULL)
    {
        printf("%c ", node->value);
    }
}

//Lists
List *createList()
{
    
    List *list = (List *) malloc(sizeof(List));
    
    
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
    
    return list;
}

void deleteList(List *list)
{
    if (NULL == list)
    {
        return;
    }
    Node *node = list->head;
    
    while (NULL != node)
    {
        Node *nodeToBeRemoved = node;
        node = node->next;
        
        deleteNode(nodeToBeRemoved);
    }
    free(list);
}

Node *addNode(List *list, Node *newNode)
{
    if (NULL == list || NULL == newNode)
    {
        return NULL;
    }
    
    if (NULL == list->head && NULL == list->tail)
    {
        list->head = list->tail = newNode;
    }
    else
    {
        Node *tail = list->tail;
        list->tail = newNode;
        
        if (NULL != tail)
        {
            tail->next = list->tail;
        }
    }
    
    list->count += 1;
    
    return newNode;
}

Node *getNodeAtIndex(const List *list, int index)
{
    Node *theResult = NULL;
    
    if (NULL != list && index < list->count)
    {
        int i = 0;
        Node *node = list->head;
        
        do
        {
            if (i == index)
            {
                theResult = node;
                break;
            }
            
            i++;
            node = node->next; 
            
        } while (NULL != node);
    }
    
    return theResult;
}

Node *removeNodeAtIndex(List *list, int index)
{
    Node *result = NULL;
    
    if (NULL == list)
        return NULL;
    
    if (index < 0 || list->count <= index)
        return NULL;
    
    if (0 == index)
    {
        Node *head = list->head;
        
        list->head = list->head->next;
        if (NULL == list->head)
            list->tail = list->head;
        
        list->count--;
        result = head;
    }
    else
    {
        Node *ownNode = getNodeAtIndex(list, index - 1);
        if (NULL != ownNode)
        {
            result = ownNode->next;
            ownNode->next = result->next;
            
            list->count--;
            
            if (result == list->tail)
            {
                list->tail = ownNode;
            }
        }
    }

    return result;
}

Node *insertNodeAtIndex(List *list, Node *newNode, int index)
{
    Node *theResult = NULL;
    
    if (NULL == list || NULL == newNode)
        return NULL;
    
    if (index < 0 || list->count < index)
        return NULL;
    
    if (0 == index)
    {
        if (NULL == list->head && NULL == list->tail)
        {
            addNode(list, newNode);
            theResult = newNode;
        }
        else
        {
            Node *head = list->head;
            list->head = newNode;
            list->head->next = head;
            list->count ++;
            theResult = newNode;
        }
    }
    else if (list->count == index)
    {
        addNode(list, newNode);
        theResult = newNode;
    }
    else
    {
        int theOwnerIndex = index - 1;
        Node *theOwnNode = getNodeAtIndex(list, theOwnerIndex);
        
        if (NULL != theOwnNode)
        {
            Node *theNextOwnNode = theOwnNode->next;
            theOwnNode->next = newNode;
            newNode->next = theNextOwnNode;
            
            list->count ++;
            theResult = newNode;
        }
    }
    
    return theResult;
}

int getLength(List *list)
{
    if (NULL == list)
        return -1;
    return list->count;
}

void printList(const List *list)
{
    if (NULL == list)
        return;
    for(int i=0; i<list->count; i++)
    {
        printNode(getNodeAtIndex(list, i));
    }
}

int listCount(List *list)
{
    int result = -1;
    if (NULL != list)
    {
        result = list->count;
    }
    return result;
}

// quickSort

void swapNodesByIndex(List *list, int left, int right)
{
    if (left == right)
        return ;
    
    Node *leftNode = getNodeAtIndex(list, left);
    Node *rightNode = getNodeAtIndex(list, right);
    
    char theTmp = leftNode->value;
    leftNode->value = rightNode->value;
    rightNode->value = theTmp;
}

int partitionIt(List *list, int leftIndex, int rightIndex, char pivot) //розділення
{
    int left = leftIndex;
    int right = rightIndex;

    while (left < right)
    {
        while (getNodeAtIndex(list, left)->value < pivot)
            left++;

        while (right > 0 && getNodeAtIndex(list, right)->value > pivot)
            right--;

        if (left < right)
        {
            swapNodesByIndex(list, left, right);

            left++;
            right--;
        }
    }
    return left;
}

void quickSort(List *list, int leftIndex, int rightIndex)
{
    if (leftIndex < rightIndex)
    {
        char pivot = getNodeAtIndex(list, rightIndex)->value;
        int partition = partitionIt(list, leftIndex, rightIndex, pivot);
        
        quickSort(list, leftIndex, partition - 1);
        quickSort(list, partition, rightIndex);
    }
}

void testList()
{
    printf("Starting...\n");
    
    Node *node2 = createNode('x');
    Node *node4 = createNode('y');
    
    List *list = createList();
    printf("Created the empty list\n");
    printf("\nNumber of elements in this list: %d\n\n", listCount(list));
    
    printf("Added one node to this list\n");
    addNode(list, node2);
    printList(list);
    printf("\nNumber of elements in this list: %d\n\n", listCount(list));
    
    printf("Added one more node to this list\n");
    addNode(list, node4);
    
    printf("\nNumber of elements in this list: %d\n\n", listCount(list));
    
    printf("Added two nodes to this list\n");
    addNode(list, createNode('7'));
    addNode(list, createNode('8'));
    printList(list);
    
    printf("\n\nAdded node with value = 5 at 4th position of the list\n");
    Node *node = createNode('5');
    insertNodeAtIndex(list, node, 4);
    printList(list);
    
    printf("\n\nAdded node with value = a at 4th position of the list\n");
    insertNodeAtIndex(list, createNode('a'), 4);
    printList(list);
    
    printf("\n\nRemoved node at 4th position and added node into the second position\n");
    printf("After removing: \n");
    node = removeNodeAtIndex(list, 4);
    printList(list);
    
    printf("\n\nSorting: \n");
    quickSort(list, 0, list->count - 1);
    printList(list);
    
    deleteList(list);
    
    printf("\nDone\n");
}
