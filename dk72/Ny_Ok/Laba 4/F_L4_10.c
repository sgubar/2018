#include "Lb4_V10.h"

struct List* CreateList()/*������������ ������*/
{
struct List *Begin = NULL, *Previous = NULL, *Current= NULL;/*Previous-����������; Current-�������; Begin-��������*/
char Ok = 'y';
while (Ok == 'y')
{
printf("\n������� ����� ������: ");
Current = ( struct List*)malloc(sizeof(struct List));
if (Begin==NULL)
Begin = Current;
else
Previous -> Next = Current;
Previous = Current;
scanf("%d",&Current -> x);
fflush(stdin);
printf("\n����������? (Y/N):");
scanf("%c",&Ok);
}
Previous -> Next = NULL;
return Begin;
}
/*=====================================*/
void DisplayList(struct List* Begin)/*�������� ���������� ������*/
{
struct List* Current = Begin;
if (Begin == NULL)
{
printf("������ ����\n");
return;
}
printf("\n������ �����:\n");
while (Current)
{
printf("%d ",Current -> x);
Current = Current -> Next;
}
printf("\n");
}
/*=====================================*/
void RemoveSet_Value(struct List* Begin)/*������� ������� �� ������*/
{
printf("\n���� � ����: ");
DisplayList(Begin);
struct List* Current = Begin, *Previos = Current;
int set_Value;
printf("\n������� ��������� ��������: ");
scanf("%d",&set_Value);
while ( Current )
{
if ( Current -> x == set_Value)
{
Previos -> Next = Current -> Next;
free(Current);
Current = Previos -> Next;
}
else
{
Previos = Current;
Current = Current -> Next;
}
}
printf("\n�����: ");
DisplayList(Begin);
}
/*=====================================*/
void AddElementBegin(struct List** Begin)/*�������� ������� � ������ ������*/
{
struct List* Current = (struct List*)malloc(sizeof(struct List));
printf("\n������� �����: ");
scanf("%d",&Current -> x);
Current -> Next = *Begin;
*Begin = Current;
}
/*=====================================*/
void AddElementEnd(struct List* Begin)/*�������� ������� � ����� ������*/
{
struct List* Current = Begin, *Previos;
while (Current)
{
Previos = Current;
Current = Current -> Next;
}
Current = (struct List*)malloc(sizeof(struct List));
Previos -> Next = Current;
printf("\n������� �����:\n");
scanf("%d",&Current -> x);
Current -> Next = NULL;
}
void AddElementSign(struct List* Begin)/*����ί�� ����� ��������� �������� ��������*/
{
printf("\n����: ");
DisplayList(Begin);
struct List* Current = Begin, *Previos = Current;
int set_Value;
printf("\n������� �������� ��������: ");
scanf("%d",&set_Value);
while (Current)
{
if ( Current -> x == set_Value)
{
Previos = Current;
Current = (struct List*)malloc(sizeof(struct List));
Current -> Next = Previos -> Next;
Previos -> Next = Current;
/*printf("\n������� �����:\n");*/
/*scanf("%d",&Current -> x);*/
Current -> x=set_Value;
/*break;*/
}
/*else*/
/*{*/
Previos = Current;
Current = Current -> Next;
/*}*/
}
printf("\n�����: ");
DisplayList(Begin);
}
/*=====================================*/
void FreeList(struct List** Begin)/*��������� ������*/
{
struct List* Current = *Begin;
while (Current)
{
*Begin = (*Begin) -> Next;
free(Current);
Current = *Begin;
}
}
