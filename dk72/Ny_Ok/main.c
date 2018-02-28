
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Объявляем переменные, при этом переменная "Koren" будет иметь вещественный тип,
дабы результат извлечения корня мог иметь некоторое количество цифр после запятой. */
int A, B, C, SummaFaktorialov; /*объявили переменные, имена можно длинной до 31 символа, но и так понятно*/
float Koren;
float Q;

/*int Function_SummaFaktorialov (int,int); Прототип функции.*/
/*Точка с запятой не ставится в конце строки имени функции при ее определении,
но обязательно ставится, когда строка содержит прототип функции.*/
/*функция для суммы факториалов*/
int Function_SummaFaktorialov (int A,int C)
{
SummaFaktorialov = 0;
for (int D=0; D<=C; D++)
    {
    A=A+D;
    int factorial = 1;   /*обновлённое значение факториала*/
    for (int i = 1; i<=A; i++)/*вложенный цикл для факториала*/
    {
    /*printf( "i ==============%d\n", i);*/
    factorial = factorial * i;
    /*printf( "factorial==============%d\n", factorial);*/
    }
    /*printf( "D======%d\n", D );*/
    SummaFaktorialov = SummaFaktorialov + factorial;
    /*printf( "SummaFaktorialov===%d\n", SummaFaktorialov );*/
    }
    printf( "SummaFaktorialov===%d\n", SummaFaktorialov );
return SummaFaktorialov;
}
