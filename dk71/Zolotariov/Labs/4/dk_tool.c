#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

Node* newNode(float data);

Node* newNode(float data) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = data;
	tmp->Next = NULL;
	tmp->Prev = NULL;
	return tmp;
}

List* newList() {
	List* tmp = (List*)malloc(sizeof(List));
	tmp->Head = NULL;
	tmp->Tail = NULL;
	return tmp;
}

Node* GetElemOn(List* List, int index) {
	if (GetSize(List) <= index) {
		printf("List isnt long enough");
		return;
	}
	Node* Current = List->Head;
	while (index != 0) {
		Current = Current->Next;
		index--;
	}
	return Current;
}

void Add(float d, List* List) {
	Node *node = newNode(d);
	if (List->Tail) {
		List->Tail->Next = node;
		node->Prev = List->Tail;
		List->Tail = node;
	}
	if (!List->Head) {
		List->Head = node;
		List->Tail = node;
	}
}

void AddAtIndex(float d, int index, List* List) {
	if (GetSize(List) <= index) {
		printf("List isnt long enough");
		return;
	}
	Node *NodeToInsert = newNode(d);
	Node *Current = List->Head;
	while (index != 0) {
		Current = Current->Next;
		index--;
	}
	Current->Prev->Next = NodeToInsert;
	NodeToInsert->Prev = Current->Prev;
	Current->Prev = NodeToInsert;
	NodeToInsert->Next = Current;
}

void Write(List* List) {
	if (!List->Head) {
		printf("List is empty\n");
		return;
	}
	Node* tmp = NULL;
	for (tmp = List->Head; tmp; tmp = tmp->Next) {
		printf("%f\n", tmp->data);
	}
	printf("\n");
}

void Clear(List* List) {
	if (!List->Head) return;
	for (List->Tail = List->Head->Next; List->Tail; List->Tail = List->Tail->Next) {
		free(List->Tail->Prev);
		List->Head = List->Tail;
	}
	free(List->Head);
}

float ExtractAt(List* List, int index) {
	if (!List->Head)
		return 0;
	Node* Current = List->Head;
	int i;
	for (i = 1; i < index; i++) {
		Current = Current->Next;
	}
	Current->Prev->Next = Current->Next;
	Current->Next->Prev = Current->Prev;
	float data = Current->data;
	free(Current);
	return data;
}

int GetSize(List* List) {
	if (!List->Head) {
		return 0;
	}
	int amount = 0;
	Node* tmp = NULL;
	for (tmp = List->Head; tmp; tmp = tmp->Next) {
		amount++;
	}
	return amount;
}

void Sort(List* List) {
	int length = GetSize(List);
	int gap;
	for (gap = length / 2; gap > 0; gap /= 2)
	{
		int i;
		for (i = gap; i < length; i += 1)
		{
			float temp = GetElemOn(List, i)->data;
			int j;
			for (j = i; j >= gap && GetElemOn(List, j - gap)->data > temp; j -= gap) {
				GetElemOn(List, j)->data = GetElemOn(List, j - gap)->data;
			}
			GetElemOn(List, j)->data = temp;
		}
	}
}

void DeleteFirstSmallerThanAvarage(List* list) {
	float sum = 0;
	int count = 0;
	Node* current = list->Head;
	while (current) {
		count++;
		sum += current->data;
		current = current->Next;
	}
	sum /= count;
	current = list->Head;
	Node* firstSmaller = NULL;
	while (current && current->data < sum) {
		firstSmaller = current;
		current = current->Next;
	}
	if (current) {
		firstSmaller->Prev->Next = current;
		current->Prev = firstSmaller->Prev;
		free(firstSmaller);
	}
}

