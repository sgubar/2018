#include "SortShel.h"
/*#define N 1000*/
#define M 16 /*это макрос на максим длинну слова*/

int n_word()/*Данный код подсчитывает количество слов в файле "__.txt "*/
{
int fSpace = 1, nCount = 0;
char ch[2] = {0};
FILE *fh = fopen("input.txt", "r");
while (! feof(fh))
{
fgets(ch, 2, fh);/*читаю один символ: ch[0] - непосредственно символ ch[1] символ '\0'*/
if (ch[0] > 32)/* если печатный символ*/
fSpace = 0;/* ставим флаг - не пробел*/
else if (0 == fSpace)/*если пробел и тп И до этого был не пробел*/
{
nCount++;/*увеличиваем счетчик слов*/
fSpace = 1;/*ставим флаг - пробел что бы если на след итерции встретился пробел мы на него забили*/
}
ch[0] = 0;
}
fclose(fh);
/*printf("%d\n", nCount);*/
return nCount;
}
/*=============================================*/
int sort_vctavka()
{
int n=n_word();
int i=0;
char a[n][M], a2[M];/*a2 - вспомогательный массив  */
FILE *fo,*fi;
fo=fopen( "input.txt", "r");
fi=fopen( "vctavka.txt", "w");
while (!feof(fo)){
fscanf(fo,"%s",a[i]);
i++;
}
fclose(fo);
/*Сортировка метод "Вставками" по убыванию*/
int z;
int index_do; /* индекс предыдущего элемента*/
for (int i = 1; i < n; i++)
{
strcpy (a2, a[i]);/*копируем слово, запоминаем*/
index_do = i-1;/*устанавливаем, запоминаем индекс на предыдущего слова*/
z=strcmp (a[index_do], a[i]);/*сравниваем предыдущее слово с текущим, возвращается или "0", или "1", или "-1"*/
while(index_do >=0 && z<=0)
{
strcpy (a[index_do+1], a[index_do]);
strcpy (a[index_do], a2);
index_do--;
}
}
/*Это вывод массива на экран или запись в файл vctavka.txt*/
for (int j=0; j<n; j++){
/*printf("%s\n", a[j]);*/
fprintf(fi,"%s\n",a[j]);
}
fclose(fi);
return 0;
}
/*=============================================*/
void sort_Shell() /*сортировка Шелла*/
{
int n=n_word();
char a[n][M], a2[M];/*a2 - вспомогательный массив  */
int k=0;
FILE *fo,*fi;
fo=fopen( "input.txt", "r");
fi=fopen( "shell.txt", "w");
while (!feof(fo)){
fscanf(fo,"%s",a[k]);
k++;
}
fclose(fo);
/*Сортировка метод "Шелла" по убыванию*/
int i, j, d, z;
d=n/2;
/*d=d/2;*/
while (d>0)
{
for (i=0; i<n-d; i++)
{
j=i;
/*strcpy (a2, a[j]);копируем слово, запоминаем*/
z=strcmp (a[j+d], a[j]);/*сравниваем предыдущее слово с текущим, возвращается или "0", или "1", или "-1"*/
while (j>=0 && z>=0)
{
strcpy (a2, a[j]);/*копируем слово, запоминаем*/
strcpy (a[j], a[j+d]);
strcpy (a[j+d], a2);
j--;
z=strcmp (a[j+d], a[j]);/*сравниваем отстоящее на ПРИРАЩЕНИЕ слово с текущим, возвращается или "0", или "1", или "-1"*/
}
}
d=d/2;
}
/*Это вывод массива на экран или запись в файл shell.txt*/
for (int j=0; j<n; j++){
/*printf("%s\n", a[j]);*/
fprintf(fi,"%s\n",a[j]);
}
fclose(fi);
/*return 0;*/
}
/*=============================================*/
char find2()
{
int n=n_word();
char a[n][M], a2[M];/*a2 - вспомогательный массив  */
char word[]="hundred";/*Искомое*/
int flag;/*флаг находки, если нашли то поставим*/
/*загружаем массив из файла ======*/
int k=0;
FILE *fo;
fo=fopen( "shell.txt", "r");
while (!feof(fo))
{
fscanf(fo,"%s",a[k]);
k++;
}
fclose(fo);
/*================================*/
int middle=n/2;/*индекс средины массива*/
printf("S E A R C H --- %s\n",word);/*это будем искать*/
sscanf(word,"%s", a2);
/*printf("%s\n", a2);*/
if (strcmp (a[n/2], a2)==0)
{
printf("Строки идентичны\n");
printf("\n слово-строка находится в массиве по индексу --  %d",n/2);
printf("\n слово находится в файле shell.txt в строке --  %d",n/2+1);
}

if (strcmp (a[n/2], a2)==1)
{
printf ("Получили при сравнении слов-строк +1, искомая строка меньше. \nПри отсортированом массиве по убыванию стартуем с индекса =  %d\n",middle);
for(int i=middle;i<n;i++)
{
if(strcmp (a[i], a2)==0)
{
printf("\n слово-строка находится в массиве по индексу --  %d",i);
printf("\n слово находится в файле shell.txt в строке --  %d",i+1);
flag =1;/*нашли - поставили флаг = 1*/
break;/*нашли - выходим из цикла*/
}
}
}
if (strcmp (a[n/2], a2)== -1)
{
printf ("Получили при сравнении слов-строк -1, искомая строка больше. \nПри отсортированом массиве по убыванию стартуем с индекса =  %d\n",0);
printf ("Но только до индекса middle = %d\n",middle);
for(int i=0;i<middle;i++)
{
if(strcmp (a[i], a2)==0)
{
printf("\n слово-строка находится в массиве по индексу --  %d",i);
printf("\n слово находится в файле shell.txt в строке --  %d",i+1);
flag =1;/*нашли - поставили флаг = 1*/
break;/*нашли - выходим из цикла*/
}
/*else */
}
}
if (flag !=1) printf("\n LINE NOT FOUND. Увы, ничего не найдено");
return 0;
}
