#include <stdio.h>

int main()
{
    int length = 9;
    int array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    for (int i = 0; i < length; i++) {
        printf("%d", array[i]);
    }
    printf("\n\n");
    
    turnaround(array, length);
    
    for (int i = 0; i < length; i++) {
        printf("%d", array[i]);
    }
    printf("\n\n");
}
