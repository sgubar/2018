#include "Lb4_V10.h"

struct List* CreateList()/*ÔÎĞÌÈĞÎÂÀÍÈÅ ÑÏÈÑÊÀ*/
{
struct List *Begin = NULL, *Previous = NULL, *Current= NULL;/*Previous-Ïğåäûäóùèé; Current-Òåêóùèé; Begin-Íà÷àëíûé*/
char Ok = 'y';
while (Ok == 'y')
{
printf("\nÂâåäèòå ÷èñëà ñïèñêà: ");
Current = ( struct List*)malloc(sizeof(struct List));
if (Begin==NULL)
Begin = Current;
else
Previous -> Next = Current;
Previous = Current;
scanf("%d",&Current -> x);
fflush(stdin);
printf("\nÏğîäîëæèòü? (Y/N):");
scanf("%c",&Ok);
}
Previous -> Next = NULL;
return Begin;
}
/*=====================================*/
void DisplayList(struct List* Begin)/*ÏĞÎÑÌÎÒĞ ÑÎÄÅĞÆÀÍÈß ÑÏÈÑÊÀ*/
{
struct List* Current = Begin;
if (Begin == NULL)
{
printf("Ñïèñîê ïóñò\n");
return;
}
printf("\nÑïèñîê ÷èñåë:\n");
while (Current)
{
printf("%d ",Current -> x);
Current = Current -> Next;
}
printf("\n");
}
/*=====================================*/
void RemoveSet_Value(struct List* Begin)/*ÓÄÀËÈÒÜ İËÅÌÅÍÒ ÈÇ ÑÏÈÑÊÀ*/
{
printf("\nÅñòü è Áûëî: ");
DisplayList(Begin);
struct List* Current = Begin, *Previos = Current;
int set_Value;
printf("\nÂâåäèòå óäàëÿåìîå çíà÷åíèå: ");
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
printf("\nÑòàëî: ");
DisplayList(Begin);
}
/*=====================================*/
void AddElementBegin(struct List** Begin)/*ÄÎÁÀÂÈÒÜ İËÅÌÅÍÒ Â ÍÀ×ÀËÅ ÑÏÈÑÊÀ*/
{
struct List* Current = (struct List*)malloc(sizeof(struct List));
printf("\nÂâåäèòå ÷èñëî: ");
scanf("%d",&Current -> x);
Current -> Next = *Begin;
*Begin = Current;
}
/*=====================================*/
void AddElementEnd(struct List* Begin)/*ÄÎÁÀÂÈÒÜ İËÅÌÅÍÒ Â ÊÎÍÅÖ ÑÏÈÑÊÀ*/
{
struct List* Current = Begin, *Previos;
while (Current)
{
Previos = Current;
Current = Current -> Next;
}
Current = (struct List*)malloc(sizeof(struct List));
Previos -> Next = Current;
printf("\nÂâåäèòå ÷èñëî:\n");
scanf("%d",&Current -> x);
Current -> Next = NULL;
}
void AddElementSign(struct List* Begin)/*ÏÎÄÂÎ¯ÒÈ ÊÎÆÍÅ ÂÕÎÄÆÅÍÍß ÇÀÄÀÍÎÃÎ ÅËÅÌÅÍÒÀ*/
{
printf("\nÁûëî: ");
DisplayList(Begin);
struct List* Current = Begin, *Previos = Current;
int set_Value;
printf("\nÂâåäèòå çàäàííîå çíà÷åíèå: ");
scanf("%d",&set_Value);
while (Current)
{
if ( Current -> x == set_Value)
{
Previos = Current;
Current = (struct List*)malloc(sizeof(struct List));
Current -> Next = Previos -> Next;
Previos -> Next = Current;
/*printf("\nÂâåäèòå ÷èñëî:\n");*/
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
printf("\nÑòàëî: ");
DisplayList(Begin);
}
/*=====================================*/
void FreeList(struct List** Begin)/*Îêîí÷àíèå ĞÀÁÎÒÛ*/
{
struct List* Current = *Begin;
while (Current)
{
*Begin = (*Begin) -> Next;
free(Current);
Current = *Begin;
}
}
