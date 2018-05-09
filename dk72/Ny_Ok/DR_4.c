#include "kvadratV3.h"
#include "kvAraay.h"

void outputConsoleArrayKvadrats(KvadratArray* anArray)
{
    if (NULL == anArray)
    {
        return;
    }
    for (int i = 0; i < anArray->count; i ++)
    {

printf("index-%d ",i);
output_console_Kvadrat(anArray->kvadrats[i]);
printf(", S = %f.\n",anArray->S[i]);
/*printf("count===%d\n",anArray->count);*/
      }
    printf("\n");
/*demoS=anArray->S[anArray->count-3];сохраняем цифру для демонстрации функции поиска*/
}
/*-----------------------------------------------*/
/*Сортировка методом пузырька*/
void bubble(KvadratArray *arr)
{
for (int i = 0; i < arr->count - 1; i++)
  {
    for (int j = 0; j < (arr->count-1-i); j++)
      {
    if(arr->S[j] < arr->S[j+1])
{
Kvadrat *t = arr->kvadrats[j+1];
float tS = arr->S[j+1];
arr->kvadrats[j+1] = arr->kvadrats[j];
arr->S[j+1] = arr->S[j];
arr->kvadrats[j] = t;
arr->S[j] = tS;
}
}
}
printf("Отсортировали по убыванию методом ПУЗЫРЬКА\n");
outputConsoleArrayKvadrats(arr);
demoS=arr->S[arr->count-7];/*сохраняем цифру для демонстрации функции поиска*/
}
/*-----------------------------------------------*/
/*Сортировка методом SHELL*/
void shell(KvadratArray *arr)
{
unsigned i,j,k;
Kvadrat *t;
float tS;
for (k=arr->count/2; k > 0; k/=2)
    for (i=k; i < (arr->count); i++)
{
t = arr->kvadrats[i];
tS = arr->S[i];
      for (j=i; j>=k; j-=k)
{
        if(tS < arr->S[j-k])
{

arr->kvadrats[j]=arr->kvadrats[j-k];
arr->S[j]=arr->S[j-k];
}
else
break;
}

arr->kvadrats[j]=t;
arr->S[j] = tS;
}
printf("Отсортировали по возрастанию методом SHELL\n");
outputConsoleArrayKvadrats(arr);

}
/*-----------------------------------------------*/
void find2(KvadratArray *arr)
{
/*Будем искать квадрат с площадью, размер которой находится во "float demoS"*/
printf("Ищем квадрат площадью = %f\n", demoS);
unsigned flag;/*флаг находки, если нашли то поставим*/
unsigned middle=arr->count/2;/*индекс средины массива*/
if (arr->S[middle] == demoS)
{
printf("Сразу же и нашли\n");
printf("\n Квадрат с площадью = %f , находится в массиве под индексом -- %d\n",demoS,middle);
return;
}
if (arr->S[middle]<demoS)
{
printf ("Получили при сравнении, что искомое больше срединного значения. \nПри отсортированом массиве по возрастанию стартуем с индекса =  %d\n",middle);
for(int i=middle;i<arr->count;i++)
{
if (arr->S[i]==demoS)
{
printf("\n Квадрат с площадью = %f , находится в массиве под индексом -- %d\n",demoS,i);
flag =1;/*нашли - поставили флаг = 1*/
break;/*нашли - выходим из цикла*/
}
}
}
if (arr->S[middle]>demoS)
{
printf ("Получили при сравнении, что искомое меньше срединного значения. \nПри отсортированом массиве по возрастанию стартуем с индекса =  %d\n",0);
printf ("Но только до индекса middle = %d\n",middle);


for(int i=0;i<middle;i++)
{
if (arr->S[i]==demoS)
{
printf("\n Квадрат с площадью = %f , находится в массиве под индексом -- %d\n",demoS,i);
flag =1;/*нашли - поставили флаг = 1*/
break;/*нашли - выходим из цикла*/
}
}
}

if (flag !=1) printf("\n LINE NOT FOUND. Увы, ничего не найдено");
}

