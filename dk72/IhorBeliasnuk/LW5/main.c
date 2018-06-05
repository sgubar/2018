#include <stdio.h>
#include "tools.h"

int main() {
    intTree *test = createIntTree();

    insertIntValueToTree(test, 9);
    insertIntValueToTree(test, 6);
    insertIntValueToTree(test, 42);
    insertIntValueToTree(test, 61);
    insertIntValueToTree(test, 7);
    insertIntValueToTree(test, 2);
    insertIntValueToTree(test, 33);
    insertIntValueToTree(test, 50);

    printTree(test->root);
    printf("\n");

    printf("Searched node : %d\n", searchNodeWithValue(test, 33)->value);

    deleteValueFromTree(test, 33);
    deleteValueFromTree(test, 2);
    deleteValueFromTree(test, 61);

    printTree(test->root);
    printf("\n");

    deleteIntTree(test);

}