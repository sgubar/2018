#include "Sort_V10.h"
int main()
{
setlocale(LC_ALL, "Russian");
/*SetConsoleOutputCP(1251);*/
/*time_t start, end;*/
float TimeStart,TimeStop;

/*time (&start);*/
/*char str[80];*/
/*scanf ("%5s----", str);*/
TimeStart = clock()/(float)CLOCKS_PER_SEC;
sort_pus();
/*time (&end);*/
/*printf("Время для сортировки методом Пузырёк в секндах = %f\n",difftime(end, start));*/
TimeStop = clock()/(float)CLOCKS_PER_SEC;
printf("Время для сортировки методом Пузырёк в секндах с учётом тиков-тактов = %f\n",TimeStop-TimeStart);
/*===============================================================================*/
TimeStart = clock()/(float)CLOCKS_PER_SEC;
sort_vybr();
TimeStop = clock()/(float)CLOCKS_PER_SEC;
printf("Время для сортировки методом Выборка в секндах = %f\n",TimeStop-TimeStart);
/*===============================================================================*/
TimeStart = clock()/(float)CLOCKS_PER_SEC;
sort_vctavka();
TimeStop = clock()/(float)CLOCKS_PER_SEC;
printf("Время для сортировки методом Вставка в секндах = %f\n",TimeStop-TimeStart);
/*===============================================================================*/
printf("Количество отсортированных слов = %d\n", n_word());
printf("******************************************************************************\n");
printf("\nPress any key to exit...\n");
printf ("Экран не закрывается, пока не нажата любая клавиша...");
getch();	/*Экран не закрывается, пока не нажата любая клавиша*/
return 0;
}
