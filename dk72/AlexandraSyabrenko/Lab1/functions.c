#include <stdio.h>
#include "functions.h"

int factorial(int number) {
    
    int result = 1;
    
    for (int i = 1; i <= number; i++) {
        result *= i;
    }
    
    return result;
}

float power(int number,int power) {
    for (int i = 0; i < power - 1; i++) {
        number *= number;
    }
    
    return number;
}
