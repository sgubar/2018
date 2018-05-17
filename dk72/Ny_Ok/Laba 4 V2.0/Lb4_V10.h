#ifndef LB4_V10_H_INCLUDED
#define LB4_V10_H_INCLUDED
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

typedef struct List
{
int x;
struct List * Next;
}List;

int flag;/*флаг выполнения первого пункта меню*/
List * CreateList(void);
/*void DisplayList(List* );*/
void DisplayList(List*,int);
void RemoveSet_Value(List* );
void AddElementBegin(List** );
void AddElementEnd(List* );
void AddElementSign(List* );
/*void FreeList(List** );*/
int FreeList(struct List**,int);

#endif // LB4_V10_H_INCLUDED
