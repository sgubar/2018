#include "Lb4_V10.h"

List* CreateList()
{
List *Begin = NULL,*Pre=NULL,*Current=NULL;
char Ok = 'y';
while (Ok == 'y')
{
printf("\nВведите числа списка: ");
Current = (List*)malloc(sizeof(List));
if (Begin==NULL)
Begin = Current;
}
else
{
Pre -> Next = Current;
}
Pre = Current;



scanf("%d",&Current -> x);
fflush(stdin);

printf("\nПродолжить? (Y/N):");
scanf("%c",&Ok);
}
Pre-> Next = NULL;


flag=1;

return Begin;
}
/*=====================================*/
void DisplayList(List* Begin, int flag)
{
if (flag!=1)
{
printf("Начинать надо с пункта меню под номером 1\n");
return;
}
List* Current = Begin;
if (Begin == NULL)
{
printf("Список пуст\n");
return;
}
printf("\nСписок чисел:\n");
while (Current)
printf("%d ",Current -> x);\
Current = Current -> Next;
}
printf("\n");
}
/*=====================================*/
void RemoveSet_Value(List* Begin)
{
if (flag!=1)
{
printf("Начни с пункта меню под номером 1\n");
return;
}
printf("\nЕсть и Было: ");
DisplayList(Begin,flag);
List* Current = Begin, *Pre = Current;
int set_Value;
printf("\nВведите удаляемое значение: ");
scanf("%d",&set_Value);
while ( Current )
if ( Current -> x == set_Value)
{
Pre -> Next = Current -> Next;
free(Current);
Current = Pre-> Next;
}
else
{
Pre = Current;
Current = Current -> Next;
}
}
printf("\nСтало: ");
DisplayList(Begin,flag);
}
/*=====================================*/
void AddElementBegin(List** Begin)
{
if (flag!=1)
{
printf("Начни с пункта меню под номером 1\n");
return;
}
struct List* Current = (List*)malloc(sizeof(List));
printf("\nВведите число: ");
scanf("%d",&Current -> x);
Current -> Next = *Begin;

*Begin = Current;
}
/*=====================================*/
void AddElementEnd(List* Begin)
{
if (flag!=1)
{
printf("Начни с пункта меню под номером 1\n");
return;
}
List* Current = Begin, *Pre;

while (Current)/*крутимся пока Current*/
{
Pre = Current;
Current = Current -> Next;
}
Current = (List*)malloc(sizeof(List));
Pre -> Next = Current; 
printf("\nВведите число:\n");
scanf("%d",&Current -> x);
Current -> Next = NULL;
}
/*=====================================*/
void AddElementSign(List* Begin)
{
if (flag!=1)
{
printf("Начни с пункта меню под номером 1\n");
return;
}
printf("\nЕсть и Было: ");
DisplayList(Begin,flag);
List* Current = Begin, *Pre = Current;


int set_Value;
printf("\nВведите заданное значение: ");
scanf("%d",&set_Value);
while (Current)
{
if ( Current -> x == set_Value) 
{
Pre = Current;
Current = (List*)malloc(sizeof(List));
Current -> Next = Pre -> Next;
Pre -> Next = Current;
Current -> x=set_Value;

}

Pre = Current;
Current = Current -> Next;
/*}*/
}
printf("\nСтало: ");
DisplayList(Begin,flag);
}
/*=====================================*/
int FreeList(List** Begin,int flag)
{
if (flag!=1)
{
printf("Чистить нечего, потому что не создано.\n");
return flag;
}
List* Current = *Begin;
while (Current)
{
*Begin = (*Begin) -> Next;
free(Current);
Current = *Begin;
}
return flag;
}
