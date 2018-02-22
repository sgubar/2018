

#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //библиотека дл€ отображени€ русского €зыка
#include <math.h> //бибилиотека математических операци€

long long int factorial(long int n) // функци€, котора€ вычисл€ет факториал
{
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1); // рекурсивна€
}
int main()
{
  int variable_A; //факториал может быть только от целого числа
  float variable_B, Q; //
  setlocale(LC_ALL, "Rus");
  do {
  		printf("¬ведите переменную A (она должна быть целой и не меньше 0, не больше 20): ");
    	float f;//проверочна€ переменна€ 
    	int result_A = scanf("%f",&f);
    	
		while(result_A != 1 || (int)f != f || f < 0 || f > 20) //проверка на корректность ввода
		{
			
	   		printf("\n¬ведите заново переменную A (она должна быть целой и не меньше 0, не больше 20): ");
	   		result_A = scanf("%f",&f);
	   		
	  		scanf("%*[^\n]");
	   	
		}
		variable_A = f;
  		printf("\n¬ведите переменную B: ");
  		float result_B = scanf("%f", &f);
  		scanf("%*[^\n]");
  		while(result_B != 1)
		{
			
	   		printf("\n¬ведите заново переменную B: ");
	   		result_B = scanf("%f",&f);
	  		scanf("%*[^\n]");
	   	
		}
		variable_B = f;
	} while (variable_A == 2 && variable_B == -4);

  Q = factorial(variable_A) / (fabs(2 * variable_A + variable_B)); //формула из задани€
  printf("\n–езультат Q = %f",Q);

  return 0;
}
