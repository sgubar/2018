#include "first_lab_func.h"

int factorial(int factorial_value) // Функция по вычислению факториала из переменной B
{
    int output_value = 1;
    while(factorial_value != 1)
    {
        output_value *= factorial_value;
        factorial_value--;
    }
    return output_value;
}

int numerator(int numerator_A, int numerator_B) // Функция по вычислению операции сложения в числителе
{
    int value_A = second_degree(numerator_A);
    int value_B = second_degree(numerator_B);
    return value_A += value_B;
}

int second_degree(int value_degree) // Функция по вычислению квадарата из передаваемой переменной
{
    return value_degree *= value_degree;
}

int denominator(int denominator_B, int denominator_C) // Функция по вычислению операции сложения в знаменателе
{
    int C_degree_of_5 = C_degree(denominator_C);
    return denominator_B + C_degree_of_5;
}

int C_degree(int C_value) // Функция по вычислению С-степени из числа 5
{
    int result_of_C_degree = 5;
    while(C_value > 1)
    {
        result_of_C_degree *= 5;
        C_value--;
    }
    return result_of_C_degree;
}

float all_expression(int factorial_result, float numerator_result, float denominator_resut) // Функция по вычислению результата из всего выражения
{
    float division_of_expression = numerator_result / denominator_resut;
    float sum_of_expression = division_of_expression + factorial_result;
    return sum_of_expression;

}

