#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"



void AddNode(Tree **myTree, double value)
{
	Tree *temp = NULL;
	if (!(*myTree))
	{
		temp = (Tree *)malloc(sizeof(Tree));
		temp->left = temp->right = NULL;
		temp->data = value;
		*myTree = temp;
		return;
	}


	if (value < (*myTree)->data)
	{
		AddNode(&(*myTree)->left, value);
	}
	else if (value >(*myTree)->data)
	{
		AddNode(&(*myTree)->right, value);
	}
}

void PrintElements(Tree *myNode)
{
	
	if (myNode) 
    {
		PrintElements(myNode->left);
		printf("%f ", myNode->data);
		PrintElements(myNode->right);
	}


}

void DeleteElements(Tree *myTree) 
{
	if (myTree) 
    {
		DeleteElements(myTree->left);
		DeleteElements(myTree->right);
		free(myTree);
	}

}

Tree *Search(Tree **myTree, double value) {

	if (!(*myTree)) {
		return NULL;
	}

	if (value == (*myTree)->data) {
		return *myTree;
	}
	else if (value < (*myTree)->data) {
		Search(&((*myTree)->left), value);
	}
	else if (value >(*myTree)->data) {
		Search(&((*myTree)->right), value);
	}
} 
void interface(void) {
	int finish = 0;

	int var = 0;
	int i;
	Tree *myTree = NULL;
	Tree *tmp;
	double value;
	while(finish != 1) 
	{ 	
		printf("\nМеню: ");
		printf("\n1. Заполнить дерево данными; ");
		printf("\n2. Вывести дерево; ");
		printf("\n3. найти элемент; ");
		printf("\n4. Выход;\n");
	   	scanf("%d",&var); 
		switch (var) {
		case 1:
		
		
		

		for (i = 0; i < 8; i++)
		{
			printf("Введите значение: ");
			scanf("%lf", &value);
			AddNode(&myTree, value);
		}
		break; 
  		 
		case 2:
		if (myTree) 
    	{
    		printf("Узлы: ");
			PrintElements(myTree);
			printf("\n");
		}
		
		
		break; 
  		 
		case 3:
		printf("Значение для поиска: ");
		scanf("%lf", &value);
		tmp = Search(&myTree, value);
		if (tmp)
		{
			printf("Узел найден: он = %f\n", tmp->data);
		}
		else
		{
			printf("Елементы не найден.\n");
		}

		
    
  		break; 
  		 
		case 4:
			DeleteElements(myTree);
			finish = 1;
  		 break;
		default:
 
  		break;
		} 	
	}
	

}

