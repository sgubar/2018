
  #include "dk_tool.h"
 rever_t ArrRever(rever_t arr_info) //инициализация функции обработки массива. arr_info - обьект структуры rever_t
 {
 	rever_t t; //обьект структуры rever_t
 	t.size = arr_info.size; 
 	t.array = (int*)malloc(t.size * sizeof(int)); // заполняем новый обьект данными. size - количество елементов массива. array - создаем новый динамический массив с размером size
 	int i;
    for (i = 0; i < t.size; i++)
    	t.array[i] = arr_info.array[arr_info.size-i-1]; // цикл обработки массива arr_info.array (заполнение массива t.array в обратном порядке)
    return t; // возвращаем обьект t с выполненой задачей
 }
