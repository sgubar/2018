#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "dk_tool.h"

int transfer(char string[]){
    int k, p, s = 0;
    p = strlen(string) - 1;
    int i;
    for (i = 0; string[i] != '\0'; i++){
        switch (toupper(string[i])){
        	case '0': k = 0;
        	break;
            case '1': k = 1;
            break;
            case '2': k = 2;
            break;
            case '3': k = 3;
            break;
            case '4': k = 4;
            break;
            case '5': k = 5;
            break;
            case '6': k = 6;
            break;
            case '7': k = 7;
            break;
            case '8': k = 8;
            break;
            case '9': k = 9;
            break;
            case 'A': k = 10;
            break;
            case 'B': k = 11;
            break;
            case 'C': k = 12;
            break;
            case 'D': k = 13;
            break;
            case 'E': k = 14;
            break;
            case 'F': k = 15;
            break;
        }
        s = s + k * pow(16, p);
        p--;
    }
    return s;
}


int checkD(int *d) {
    printf("D = ");
    if (scanf("%i", d) == 1) {
	       return 0;
    }
    else {
        scanf("%*s");
        checkD(d);
    }
    return 0;
}


int checkA(int *a) {
    printf("A = ");
    if (scanf("%i", a) == 1) {
	       return 0;
    }
    else {
        scanf("%*s");
        checkA(a);
    }
    return 0;
}


int checkC(int *c) {
    printf("C = ");
    if (scanf("%i", c) == 1) {
	       return 0;
    }
    else {
        scanf("%*s");
        checkC(c);
    }
    return 0;
}
