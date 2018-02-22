#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main(int argc, char *argv[]) {
	int i;
	int *array;
	int size;
	
	
	printf("Type number of array elements: ");
    scanf("%d", &size); // ввод данных о размере массива
	array = (int*)malloc(size * sizeof(int)); // создание динамического массива array с размером size
  	printf("Fill array: \n");
  	for (i = 0; i < size; i++)
  	{
   	 printf("Array[%d] = ", i);
   	 scanf("%d", &array[i]); // ввод данных в массив
 	}

	rever_t arr_info = {size,array}; // присваиваем обьекту arr_info данные о массиве и сам массив
	rever_t finish = ArrRever(arr_info); // присваиваем обьекту finish результат обработки функции ArrRever библиотеки dk_tool
	printf("Finish array: \n");
	for(i = 0; i < finish.size; i ++) 
		printf("Array[%d] = %d \n", i, finish.array[i]); //вывод данных
system("pause");
	return 0;
}
