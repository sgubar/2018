#include "FileZagolovok.h"
int SummaFaktorialov;

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


