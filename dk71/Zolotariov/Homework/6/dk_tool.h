#ifndef DK_TOOL_H
#define DK_TOOL_H

typedef struct Node Node;

struct Node {
	float data;
	Node *Next; 
	Node *Prev;
};

typedef struct {
	Node *Head;
	Node *Tail;
} List;

List* newList();
void AddAtIndex(float d, int index, List* List);
void Add(float d, List* List);
void Write(List* List);
void Clear(List* List);
float ExtractAt(List* List, int n);
int GetSize(List* List);
void Sort(List* List);

#endif
