#include "DR_6_V2.h"
const int listError = -1;

void PrintList(const FloatList *aList)
{
	for (int i = 0; i < CountList(aList); i++)
	{
		FloatNode *theNode = NodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("Узел[%d].value = %8.2f\n", i, theNode->value);
    }
	}
}
/*========================================================*/
int CountList(const FloatList *aList)
{
int theResult = listError;
if (NULL != aList)
{
theResult = aList->count;
}
	return theResult;
}
/*========================================================*/
FloatNode *CreateNodeWithFloatValue(float aValue)/*Создать новый узел под тип значения float*/
{
	FloatNode *theResult = (FloatNode *)malloc(sizeof(FloatNode));

	theResult->value = aValue;
	theResult->nextNode = NULL;/*пока с нулевым указателем*/

	return theResult;
}
/*========================================================*/
void FreeFloatNode(FloatNode *aNode)
{
	if (NULL != aNode)
	{
		free(aNode);
	}
}
/*========================================================*/
FloatList *CreateList()
{
FloatList *theList = (FloatList *)malloc(sizeof(FloatList));/*Allocate memory for the list structure Выделить память для структуры списка*/

/*Clean internal data Чистые внутренние данные*/
theList->head = NULL; /*<!- not head не голова*/
theList->tail = NULL; /*<!- not tail не хвост*/
theList->count = 0; /*<!- initial value of count is zero - no elements in the list начальное значение count равно нулю - в списке нет элементов*/
return theList;
}
/*========================================================*/
FloatNode *AddNode(FloatList *aList, FloatNode *aNewNode)
{
/*Check the input parameter Проверка входного параметра*/
	if (NULL == aList || NULL == aNewNode)
	{
		return NULL;
	}

/*Add the new node to end of the list Добавить новый узел в конец списка*/
	if (NULL == aList->head && NULL == aList->tail)
	{
/*		The list is empty Список пуст*/
		aList->head = aList->tail = aNewNode;
	}
	else
	{
		FloatNode *theTail = aList->tail;
		aList->tail = aNewNode;
		if (NULL != theTail)
		{
			theTail->nextNode = aList->tail;
		}
	}
	aList->count += 1;/*плюс 1 с присвоением*/
	return aNewNode;
}
/*========================================================*/
FloatNode *InsertNodeAtIndex(FloatList *aList, FloatNode *aNewNode, int anIndex)
{
	FloatNode *theResult = NULL;
	if (NULL == aList || NULL == aNewNode)/*проверка - существует ли список и существует ли узел*/
		return NULL;
	if (anIndex < 0 || aList->count < anIndex)
		return NULL;
	if (0 == anIndex)
	{
		if (NULL == aList->head && NULL == aList->tail)
		{
			AddNode(aList, aNewNode);
			theResult = aNewNode;
		}
		else
		{
			FloatNode *theHead = aList->head;
			aList->head = aNewNode;
			aList->head->nextNode = theHead;
			aList->count ++;
			theResult = aNewNode;
		}
	}
	else if (aList->count == anIndex)
	{
		AddNode(aList, aNewNode);
		theResult = aNewNode;
	}
	else
	{
		int theOwnerIndex = anIndex - 1;
		FloatNode *theOwnNode = NodeAtIndex(aList, theOwnerIndex);

		if (NULL != theOwnNode)
		{
			FloatNode *theNextOwnNode = theOwnNode->nextNode;
			theOwnNode->nextNode = aNewNode;
			aNewNode->nextNode = theNextOwnNode;

			aList->count ++;
			theResult = aNewNode;
		}
	}

	return theResult;
}
/*========================================================*/
FloatNode *NodeAtIndex(const FloatList *aList, int anIndex)
{
	FloatNode *theResult = NULL;

	if (NULL != aList && anIndex < aList->count)
	{
		int i = 0;
		FloatNode *theNode = aList->head;

		do
		{
			if (i == anIndex) /*<!- index was found индекс был найден*/
			{
				theResult = theNode; /*<! - our node наш узел*/
				break;
			}
			i++; /* увеличить индекс*/
			theNode = theNode->nextNode; /*<! - go to next node перейти к следующему узлу*/
		} while (NULL != theNode);
	}
/*printf("возвращает индекс узла%d\n",theResult);*/
	return theResult;/*возвращает индекс узла????????*/
}
/*========================================================*/
void FreeList(FloatList *aList)
{
	/* Check the input parameter Проверка входного параметра*/
	if (NULL == aList)
	{
		return;
	}
/*1. Remove all elements Удаление всех элементов*/
	FloatNode *theNode = aList->head;

	while (NULL != theNode)
	{
		FloatNode *theNodeToBeFree = theNode;
		theNode = theNode->nextNode;

		FreeFloatNode(theNodeToBeFree);
	}
/*2. Free memory for the List structure Освобождает место в памяти от структуры списка*/
	free(aList);
}
/*========================================================*/
FloatNode *RemovedNodeAtIndex(FloatList *aList, int anIndex)
{
	FloatNode *theResult = NULL;

	if (NULL == aList)
		return NULL;

	if (anIndex < 0 || aList->count <= anIndex)
		return NULL;

	if (0 == anIndex)
	{
		FloatNode *theHead = aList->head;

		aList->head = aList->head->nextNode;
		if (NULL == aList->head)
			aList->tail = aList->head;

		aList->count --;
		theResult = theHead;
	}
	else
	{
		FloatNode *theOwnNode = NodeAtIndex(aList, anIndex - 1);
		if (NULL != theOwnNode)
		{
			theResult = theOwnNode->nextNode;
			theOwnNode->nextNode = theResult->nextNode;
			aList->count --;
			if (theResult == aList->tail)
			{
				aList->tail = theOwnNode;
			}
		}
	}
	return theResult;
}
