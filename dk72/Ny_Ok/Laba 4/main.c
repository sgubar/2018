#include "Lb4_V10.h"
#define TRUE 1

int main(void)
{
setlocale(LC_ALL, "Russian");

struct List* Begin;
char Key;
while(TRUE)
{
printf( "\nВведите номер - режим операций со списками: "
"\n 1 - ФОРМИРОВАНИЕ СПИСКА"
"\n 2 - ПРОСМОТР СОДЕРЖАНИЯ СПИСКА"
"\n 3 - ПОДВОЇТИ КОЖНЕ ВХОДЖЕННЯ ЗАДАНОГО ЕЛЕМЕНТА"
"\n 4 - ДОБАВИТЬ ЭЛЕМЕНТ В НАЧАЛЕ СПИСКА"
"\n 5 - ДОБАВИТЬ ЭЛЕМЕНТ В КОНЕЦ СПИСКА"
"\n 6 - УДАЛИТЬ ЭЛЕМЕНТ ИЗ СПИСКА"
"\n 7 - Окончание РАБОТЫ\n");

fflush( stdin );
scanf("%c",&Key);
system("cls");
switch (Key)
{
case '1':
system("cls");
Begin = CreateList();
printf("\n\nНажмите любую клавишу, чтобы вернуться в меню...\n");
getch();
system("cls");
break;
case '2':
system("cls");
DisplayList(Begin);
printf("\n\nНажмите любую клавишу, чтобы вернуться в меню...\n");
getch();
system("cls");
break;
case '3':
system("cls");
AddElementSign(Begin);
printf("\n\nНажмите любую клавишу, чтобы вернуться в меню...\n");
getch();
system("cls");
break;
case '6':
system("cls");
RemoveSet_Value(Begin);
printf("\n\nНажмите любую клавишу, чтобы вернуться в меню...\n");
getch();
system("cls");
break;
case '4':
system("cls");
AddElementBegin(&Begin);
printf("\n\nНажмите любую клавишу, чтобы вернуться в меню...\n");
getch();
system("cls");
break;
case '5':
system("cls");
AddElementEnd(Begin);
printf("\n\nНажмите любую клавишу, чтобы вернуться в меню...\n");
getch();
system("cls");
break;
case '7':
FreeList(&Begin);
DisplayList(Begin);
printf("\n\nНажмите любую клавишу для выхода...\n");
getch();
return 0;
default:
system("cls");
printf("\nНеверный ввод !!! Попробуй еще раз!!!\n");
printf("\n\nНажмите любую клавишу, чтобы вернуться в меню...\n");
getch();
system("cls");
break;
}
}
}
