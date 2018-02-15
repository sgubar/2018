#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h>
#include <conio.h>
#include "first_lab_func.h"

int main()
{
    setlocale(LC_ALL, "Rus"); // Подключение русскоязычной раскладки
    int variable_B = 0; // Объявление и определение переменной B
    int variable_A = 0; // Объявление и определение переменной A
    int variable_C = 0; // Объявление и определение переменной C
    float result_Q = 0; // Объявление и определение переменной для вывода результата всего выражения
    int value_result = 0; // Объявление и определение переменной для проверки на правильность ввода
    printf("Данная программа выполняет вычисления выражения: \n"); // Диалог с пользователем
    printf("\n\t(A^2) + (B^2)\n\t------------- + B!\n\t  B + (5^C)\n\n"); // Диалог с пользователем
    printf("Введите целочисленное значение для переменной 'A':\nA = "); // Диалог с пользователем
    do
    {
        value_result = scanf("%i", &variable_A);
        fflush(stdin);
        if (value_result == 1)
        {
           printf("Введенное вами значение: %i\n", variable_A); // Диалог с пользователем
        }else
        {
           printf("Введенное вами значение не соответствует условию программы.\nПовторите попытку:\nA = "); // Диалог с пользователем
        }
    }while(value_result != 1);
    printf("Введите целочисленное значение для переменной 'B':\nB = "); // Диалог с пользователем
    do
    {
        value_result = scanf("%i", &variable_B);
        fflush(stdin);
        if (value_result == 1 && variable_B >= 1)
        {
           printf("Введенное вами значение: %i\n", variable_B); // Диалог с пользователем
        }else
        {
           printf("Введенное вами значение не соответствует типу в условии программы или факториал от введенного вами числа не извлекается.\nПовторите попытку:\nB = "); // Диалог с пользователем
        }
    }while(value_result != 1);
    printf("Введите целочисленное значение для переменной 'C':\nC = "); // Диалог с пользователем
    do
    {
        value_result = scanf("%i", &variable_C);
        fflush(stdin);
        if (value_result == 1 && variable_C >= 0)
        {
           printf("Введенное вами значение: %i\n", variable_C); // Диалог с пользователем
        }else
        {
           printf("Введенное вами значение не соответствует типу в условии программы или указана неверная степень.\nПовторите попытку:\nC = "); // Диалог с пользователем
        }
    }while(value_result != 1);
    int output_factorial = factorial(variable_B); // Объявление и определение переменной для конечного значения факториала
    int output_numerator = numerator(variable_A, variable_B);
    int output_denominator = denominator(variable_B, variable_C);
    result_Q = all_expression(output_factorial, output_numerator, output_denominator);
    printf("\nРезультатом данного выражения при введенных вами данных (A = %i; B = %i; C = %i) будет равен значению: %f\n", variable_A, variable_B, variable_C, result_Q); // Диалог с пользователем
    return 0;
}
