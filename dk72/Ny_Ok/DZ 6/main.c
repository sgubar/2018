#include "DR_6_V2.h"
#include "SortDR6V2.h"

int main()
{
  setlocale(LC_ALL, "Russian");

  printf("Начинаем демонстрацию односвязного списка ...\n");

	FloatNode *theNode2 = CreateNodeWithFloatValue(45);
	FloatNode *theNode4 = CreateNodeWithFloatValue(40);

	FloatList *theList = CreateList();
	printf("number of elements: %d\n", CountList(theList));

	AddNode(theList, theNode2);
	printf("number of elements: %d\n", CountList(theList));

	AddNode(theList, theNode4);
	printf("number of elements: %d\n", CountList(theList));

	AddNode(theList, CreateNodeWithFloatValue(7));
	AddNode(theList, CreateNodeWithFloatValue(8));

	FloatNode *theNode = CreateNodeWithFloatValue(5);

	InsertNodeAtIndex(theList, theNode, 4);
	InsertNodeAtIndex(theList, CreateNodeWithFloatValue(10), 4);



	PrintList(theList);
	theNode = RemovedNodeAtIndex(theList, 4);
	InsertNodeAtIndex(theList, theNode, 2);


	printf("\nAfter removing После удаления: \n");
	PrintList(theList);


  printf("\nНужно нажать любую клавишу для продолжения\n");
  getch();
  system("cls");
  printf("До сортировки: \n");
  float y=-7;/*Довавляем в список ещё N элементов(узлов)*/
	float x;
	for (int N=0; N<1; N++){
	x=pow (y,2)+1;
	AddNode(theList, CreateNodeWithFloatValue(x));
  y=y+0.5;
	}
	sPrintList(theList);

	printf("После Сортировки: \n");
/*	quickSort(theList, 0, theList->count - 1);*/
/*	PrintList(theList);*/
ShellsSort(theList);

	FreeList(theList);

	printf("Готово.\n");
  return 0;
}
