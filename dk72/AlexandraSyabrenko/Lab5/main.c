#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
    Tree *test = createTree();
    
    insertDoubleValueToTree(test, 9.8);
    insertDoubleValueToTree(test, 6.34);
    insertDoubleValueToTree(test, 42.01);
    insertDoubleValueToTree(test, 61.3);
    insertDoubleValueToTree(test, 7.8);
    insertDoubleValueToTree(test, 2.07);
    insertDoubleValueToTree(test, 33.45);
    insertDoubleValueToTree(test, 50.6);
    
    printTree(test->root);
    printf("\n");
    
    printf("Searched node : %.3f\n", searchNodeWithValue(test, 33.45)->value);
    
    deleteValueFromTree(test, 33.45);
    deleteValueFromTree(test, 2.07);
    deleteValueFromTree(test, 61.3);
    
    printTree(test->root);
    printf("\n");
    
    deleteTree(test);
    return 0;
}
