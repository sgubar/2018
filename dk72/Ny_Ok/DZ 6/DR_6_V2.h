#ifndef DR_6_V2_H_INCLUDED
#define DR_6_V2_H_INCLUDED
/*#include "SortDR6V2.h"*/
#include <locale.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
extern const int listError;
// Predeclaration
// The node declaration Объявление узла
typedef struct _FloatNode FloatNode;
struct _FloatNode
{
	float value;
	FloatNode *nextNode;//<! - the reference to next node ссылка на следующий узел
};

typedef struct _FloatList
{
	FloatNode *head;
	FloatNode *tail;
	int count;
}FloatList;


FloatList *CreateList();/*Создать список*/
FloatNode *CreateNodeWithFloatValue(float aValue);/*Создать новый узел под тип значения float*/
FloatNode *AddNode(FloatList *aList, FloatNode *aNewNode);/*Добавить новй узел в список*/

FloatNode *InsertNodeAtIndex(FloatList *aList, FloatNode *aNewNode, int anIndex);/*Вставить новый узел по индексу*/

void PrintList(const FloatList *aList);
int CountList(const FloatList *aList);/*возвращает индекс записи или код ошибки*/
FloatNode *NodeAtIndex(const FloatList *aList, int anIndex);/*возвращает узел по индексу??????*/

FloatNode *RemovedNodeAtIndex(FloatList *aList, int anIndex);/*удалить узел */


void FreeFloatNode(FloatNode *aNode);/*удалить узел, в смысле очистить память*/
void FreeList(FloatList *aList);/*удалить список, в смысле очистить память*/





#endif // DR_6_V2_H_INCLUDED
