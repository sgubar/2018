#include <stdio.h>

#include <conio.h>

#include "my_tree.h"



int main() 

{	

    Tree *theTree = createTree();

    insertValueToTree(theTree,45);

    insertValueToTree(theTree,46);

    insertValueToTree(theTree,47);

    insertValueToTree(theTree,48);

    insertValueToTree(theTree,49);

    insertValueToTree(theTree,50);



    printf("Binary tree\n");

    printTree(theTree); 

    printf("\n");

    Node *SeachNode = findNodeWithValue(theTree,(char)46); 

    printf("\n");

    printf("Searched value =  %c \n", SeachNode ->value );

    printf("\n");

    deleteNodeWithElement(theTree, theTree -> root,(char)46);

    printf("Binary tree after deleted element");

    printf("\n");

    printTree(theTree);

    deleteTree(theTree);

    

    getch();

    return 0;

}
