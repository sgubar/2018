#include "Lab5_V10.h"
#define MAXWOR 1000



int main()
{
setlocale(LC_ALL, "Russian");
//SetConsoleOutputCP(1251);

tnode *root;
char word[MAXWOR];
root = NULL;
printf("Нужно ввести некоторое количество слов (условие выхода - ввод символа 0:  \n");
do
{
scanf("%s",word);
if(isalpha(word[0]))
root = addtree(root, word);
}while(word[0]!='0'); 
printf("Вывод дерева. Обход  в симметричном порядке:\n");
treeprint(root);
printf("Вывод дерева. Обход  в пямом порядке:\n");
treeprint2(root);
freemem(root);
printf("******************************************************************************\n");
printf("\nPress any key to exit...\n");

getchar();
printf ("Экран не закрывается, пока не нажата любая клавиша...");
getchar();

return 0;
}
