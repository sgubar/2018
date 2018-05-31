#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "menu.h"
#include <windows.h>
#include <ctype.h>
#include <stdio.h>
#include <conio.h>

void GetXY (COORD *coord)
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	if (GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &info))
    {
		coord->X = info.dwCursorPosition.X;
		coord->Y = info.dwCursorPosition.Y;
	}
	else
    {
		coord->X = -1;
		coord->Y = -1;
	}
}

void SetCharXY (int x , int y , char c)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), coord);
	if(c != NULL)
		printf("%c", c);
}

int menu1 ()
{
    printf("\n\n");

	int i=0 , ch = 0, menulenght = 6, tmp = 0;
	COORD pos;

	GetXY (&pos);

    tmp = pos.Y;

	int positions[7][2] = {{0,2},{0,3},{0,4},{0,6},{0,7},{0,8},{0,9}};

	printf("Choose variant:\n");
	printf("-----------------\n");
	printf("  Insert new Node!\n");
	printf("  Find Node by value!\n");
	printf("  Delete Node by value!\n");
	printf("-----------------\n");
	printf("  Print tree (backwards type)!\n");
	printf("  Print tree (Graphic type)!\n");
	printf("  Get the number of elements in the tree!\n");
	printf("  Destroy the tree and Exit!\n");
	printf("-----------------\n");

	SetCharXY (positions[0][0], pos.Y + positions[0][1], '>');

	while (ch != 13)
    {
		ch = _getch();
		switch (ch)
		{
		case 80:				//up
			if (i < menulenght)
            {
                SetCharXY (positions[i][0] , pos.Y +positions[i][1] , ' ');
                i++;
				SetCharXY (positions[i][0], pos.Y + positions[i][1], '>');
			}
			break;
		case 72:				//down
			if (i > 0)
            {
                SetCharXY (positions[i][0] , pos.Y +positions[i][1] , ' ');
                i--;
				SetCharXY (positions[i][0], pos.Y + positions[i][1], '>');
			}

			break;
		}
	}

	SetCharXY (positions[i][0], pos.Y + positions[i][1], ' ');
	SetCharXY (positions[0][0], positions[6][1]+tmp, ' ');
	printf("\n");

	return i+1;
}

void insert_Node(IntTree *aTree)
{
    double value;
    printf("\n\nEnter VALUE for insert: ");
    scanf("%lf", &value);
    insert_IntNodeToTree(aTree, value);
    printf("\nNode was inserted!\n");
}

void find_Node(IntTree *aTree)
{
    double value;
    printf("\n\nEnter the value of Node to find: ");
    scanf("%lf", &value);
    find_NodeWithIntValue(aTree, value);
    printf("\n");
}

void delete_Node(IntTree *aTree)
{
    double value;
    do
    {
        printf("\n\nEnter the value of Node for deleting: ");
        scanf("%lf", &value);
        if(value == aTree -> root->value)
        {
            printf("Error ! Enter again! (root=value)!\n");
        }
    }while(value == aTree -> root->value);
    delete_NodeWithIntValue(aTree, aTree -> root, value);
    printf("\nNode was deleted!\n");
}

void print_Tree_(IntTree *aTree)
{
    printf("\nTree:\n");
    print_Tree(aTree);
    printf("\n\nList was printed!\n");
}

void print_TreeGraphic(IntTree *aTree)
{
    printf("\nIn development! Use other function!\n");
}


void size_Tree(IntTree *aTree)
{
    printf("\n\nNumber of elements(size of Tree): %d\n", count_NodesInTree(aTree));
}

void delete_Tree(IntTree *aTree)
{
    destroy_IntTree(aTree);
    printf("\n\nTree was deleted!\n");
}

void The_End()
{
    printf("\nThank You!\n");

    printf("\n!!!!!!!! \\(^_^)/ !!!!!!!!\n");
}
