#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include"dk_tree.h"
char menu(void)
{
    int ch;
    puts("Binary  Tree");
    puts("Enter the letter corresponding to your choice:");
    puts("a) add a number          l) print tree");
    puts("n) number of values     f) find number");
    puts("d) delete a value       q) quit");
    while ((ch = getchar()) != EOF)
    {
        while (getchar() != '\n')
            continue;
        ch = tolower(ch);
        if (strchr("alrfndq",ch) == NULL)
            puts("Please enter an a, l, f, n, d, or q:");
        else
            break;
    }
    if (ch == EOF)       /* make EOF cause program to quit */
        ch = 'q';

    return ch;
}

void addnumber(IntTree *aTree)
{
    int value;
        puts("Please enter the number that you want to add:");
    scanf("%d", &value);
    insertIntValueToTree(aTree,value);
    puts("The number was added");


}


void show_tree(IntTree *aTree)
{
    printf("\nTree:\n");
    printTree(aTree);
    printf("\n\nList was printed!\n");
}

void findnumber(IntTree * aTree)
{
    int value;
    puts("Enter the value of Node to find: ");
    scanf("%d", &value);
    findNodeWithValue(aTree,value);
    printf("\n");
}

void delete_a_value(IntTree * aTree)
{
  int value;
    do
    {
        puts("Enter the value of Node for deleting: ");
        scanf("%d", &value);
        if(value == aTree -> root->value)
        {
            puts("Error ! Enter again! (root=value)!");
        }
    }while(value == aTree -> root->value);
    deleteNodeWithIntValue(aTree, aTree -> root, value);
    puts("Node was deleted!");
}
void the_number_of_values(IntTree *aTree)
{
    printf("\n\nNumber of elements is (size of Tree): %d\n", countNodesWithTree(aTree));
}
