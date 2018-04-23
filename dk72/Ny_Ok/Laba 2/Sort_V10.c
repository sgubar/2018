#include "Sort_V10.h"
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
int sort_pus()
{
int n=n_word();
int i=0;
char a[n][M], a2[M];/*a2 - вспомогательный массив  */
FILE *fo,*fi;
fo=fopen( "input.txt", "r");
fi=fopen( "pusrek.txt", "w");
while (!feof(fo)){
fscanf(fo,"%s",a[i]);
i++;
}
fclose(fo);
/*метод "пузырёк" по убыванию*/
for(int i = 0 ; i < n - 1; i++) {
/*сравниваем два соседних элемента.*/
for(int j = 0 ; j < n - i - 1 ; j++) {
if(strcmp(a[j], a[j+1])< 0){/*сортировка по возрастанию или убыванию зависит от направления знака"<"*/
strcpy (a2, a[j]);/*если они идут в неправильном порядке, то меняем их местами.*/
strcpy (a[j], a[j+1]);
strcpy (a[j+1],a2);
}
}
}
/*Это вывод массива на экран или запись в файл pusrek.txt*/
for (int j=0; j<n; j++){
/*printf("%s\n", a[j]);*/
fprintf(fi,"%s\n",a[j]);
}
fclose(fi);
return 0;
}
/*=============================================*/
int sort_vybr()
{
int n=n_word();
int i=0;
char a[n][M], a2[M];/*a2 - вспомогательный массив  */
FILE *fo,*fi;
fo=fopen( "input.txt", "r");
fi=fopen( "vybor.txt", "w");
while (!feof(fo)){
fscanf(fo,"%s",a[i]);
i++;
}
fclose(fo);
/*Сортировка метод "Выборка" по убыванию*/
int position;
for(int i = 0 ; i < n; i++) {
position=i;
/*.*/
for(int j = i+1;j < n; j++) {
if(strcmp(a[position], a[j])< 0){/*сортировка по возрастанию или убыванию зависит от направления знака"<"*/
position=j;
/**/
strcpy (a2, a[position]);/*копируем во вспомогательный "а2"*/
strcpy (a[position], a[i]);/*меняем местами*/
strcpy (a[i],a2);/*меняем местами*/
}
}
}

/*Это вывод массива на экран или запись в файл vybor.txt*/
for (int j=0; j<n; j++){
/*printf("%s\n", a[j]);*/
fprintf(fi,"%s\n",a[j]);
}
fclose(fi);
return 0;
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


