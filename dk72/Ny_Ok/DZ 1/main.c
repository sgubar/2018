#include <stdio.h>
#include <conio.h>
#include "dk_tool.h"
#include <locale.h>
#include <windows.h>
int main()
{
char str[80];
int result10;
setlocale(LC_ALL, "Russian");
SetConsoleOutputCP(1251);
printf ("Enter the number in hexadecimal format...\n");
printf ("Введи число в шестнадцатеричном формате...\n");
scanf("%[ABCDEFabcdef0123456789]",str);/*здесь ограничиваемся вводом символов указаннх в []*/
printf("******************************************************************************\n");
result10=translating16_10 (&str);
if ((result10)!=0)
{
printf("Hexadecimal number (Шестнадцатеричному числу) - %.4s\n",str);
printf ("Matches a decimal number (Соответсвует десятичное число) - %d\n",result10);
}
printf("******************************************************************************\n");
printf("\nPress any key to exit...\n");
printf ("Экран не закрывается, пока не нажата любая клавиша...");
getch();	/*Экран не закрывается, пока не нажата любая клавиша*/
return 0;

}
