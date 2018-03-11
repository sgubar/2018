#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
/*Объявляем несколько переменных глобалными = "extern", чтобы их было видно при компиляции всех файлов*/
extern int SummaFaktorialov;
extern float Koren;
/* Задекларируем глобально пару функций (прототипы).
 * Точка с запятой не ставится в конце строки имени функции при ее определении,
 * но обязательно ставится, когда строка содержит прототип функции.
 */
 extern int Function_SummaFaktorialov (int, int);
 extern float FunctionKoren (int, int);
