#ifndef HW6_LIST_H
#define HW6_LIST_H
typedef struct __tagIntNode IntNode;
struct __tagIntNode
{
    int value;
    IntNode *prev;
    IntNode *next;
};

typedef struct __tagIntList
{
    IntNode *head;
    IntNode *tail;
    int count;

}IntList;


IntList *CreateIntList();
IntNode *createIntNodeWithValue (int );
void DestroyIntList(IntList *aList);
int AddIntValueToList (IntList *aList, int );
IntNode *createIntNodeWithValue(int );
void PrintList (IntList *aList);
int InsertIntValueAtIndex(IntList *aList, int anIntValue, int anIndex);
void quickSort(IntList *aList, int left, int right);

#endif //HW6_LIST_H
