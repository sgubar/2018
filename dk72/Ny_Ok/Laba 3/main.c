#include "SortShel.h"
int main()
{
setlocale(LC_ALL, "Russian");
//SetConsoleOutputCP(1251);
float TimeStart,TimeStop;
TimeStart = clock()/(float)CLOCKS_PER_SEC;
sort_vctavka();
TimeStop = clock()/(float)CLOCKS_PER_SEC;
printf("Время для сортировки методом Выборка в секундах = %f\n",TimeStop-TimeStart);
/*===============================================================================*/
TimeStart = clock()/(float)CLOCKS_PER_SEC;
sort_Shell();
TimeStop = clock()/(float)CLOCKS_PER_SEC;
printf("Время для сортировки методом Шелла в секундах = %f\n",TimeStop-TimeStart);
/*===============================================================================*/

/*===============================================================================*/
printf("Количество отсортированных слов = %d\n", n_word());
printf("******************************************************************************\n");
find2();
printf("\n******************************************************************************\n");
printf("******************************************************************************\n");
printf("\nPress any key to exit...\n");
printf ("Экран не закрывается, пока не нажата любая клавиша...");
getch();	/*Экран не закрывается, пока не нажата любая клавиша*/
return 0;
}
