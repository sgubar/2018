
  #include "dk_tool.h"
 long long int factorial_t(long long int n) //инициализация функции обработки факторила
 {
  if (n == 0 || n == 1) return 1;
    return n * factorial_t(n - 1); // рекурсивная

 }
 float module_t(float data) //инициализация функции обработки модуля
{

	if(data < 0) {

		 return data*(-1); 
	} else {
    	return data;	
	}
}
