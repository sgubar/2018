#include "DR7_V2.h"

int main()
{
setlocale(LC_ALL, "Russian");
//SetConsoleOutputCP(1251);

int flag;
float value = 0;
float *arrayValues = NULL;
printf("ДЕМОНСТРАЦИЯ БИНАРНОГО ДЕРЕВА\n");
treeNode *Root_Node = createTreeNode();
int kolichestvo_znacheniy = 15;
printf("\n Количество элементов в двоичном дереве задаём = 15 ");
arrayValues = (float *)malloc(sizeof(float) * kolichestvo_znacheniy);
Root_Node->value =4.13;

float y=-2;
float x;
for(int i = 0; i < kolichestvo_znacheniy-10; i++)
{
x= (y<0)? (pow (y,2)+1): (pow (y,2)+0.25);
value = arrayValues[i] = x;
add_BTree_Node_with_value(Root_Node, value);
y=y+0.5;
}
add_BTree_Node_with_value(Root_Node, 8);
add_BTree_Node_with_value(Root_Node, 4);
add_BTree_Node_with_value(Root_Node, 9);
printTree(Root_Node);
treeNode *max_value_Node = findMaxMin(Root_Node, 1);
treeNode *min_value_Node = findMaxMin(Root_Node, 0);
printf("\nНаименьшее значение в данном двоичном дереве (%4.2f) ...", min_value_Node->value);
printf("\nНаибольшее значение в данном двоичном дереве (%4.2f) ...", max_value_Node->value);
do
{
printf("\n\nДля поиска в этом двоичном дереве ...\n Введи значение: ");
scanf("%f", &value);
fflush(stdin);
treeNode *Node = findValue(Root_Node, value);
if(Node != NULL)
{
printf("\n\nЗначение, которое нужно найти: %4.2f",Node->value);
if(Node->parent)
printf("\nПредыдущее значение (т.е. сверху): %4.2f", Node->parent->value);
else
printf("\n\nЗначение является корнем этого двоичного дерева ...");
if(Node->left)
printf("\nМеньшее значение  слева вниз = %4.2f", Node->left->value);
if(Node->right)
printf("\nБольшее значение справа вниз = %4.2f", Node->right->value);
}
else
{
printf("\n\nЗначение, которое вы ищете, не существует в данном двоичном дереве ...");
}
printf("\n\nБудем искать ещё?\nДля продолжения поиска -введите «0»,\nдля прерывания поиска любую ЦИФРУ: ");
scanf("%i", &flag);
fflush(stdin);
}while(flag == 0);
flag=0;
do
{
printf("\n\nУкажите значение узла, который необходимо удалить ...\nУдаляемое значение: ");
scanf("%f", &value);
fflush(stdin);
if( Root_Node->value== value)
{
printf("\n\nКорневой узел удалять нельзя...\nВведи другое значение ...");
continue;
}
treeNode *Node_for_delete = findValue(Root_Node, value);
deleteNode(Node_for_delete);
printf("\n\nДля продолжения удаления введите «0»,\nдля прерывания удаления любую ЦИФРУ:");
scanf("%i", &flag);
fflush(stdin);
}while(flag == 0);
printTree(Root_Node);
max_value_Node = findMaxMin(Root_Node, 1);
min_value_Node = findMaxMin(Root_Node, 0);
printf("\nНаименьшее значение в данном двоичном дереве (%4.2f) ...", min_value_Node->value);
printf("\nНаибольшее значение в данном двоичном дереве (%4.2f) ...", max_value_Node->value);
deleteTree(Root_Node, arrayValues, kolichestvo_znacheniy);
return 0;
}
