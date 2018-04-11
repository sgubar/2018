#include "dk72_tool.h"

void turnaround(int array[], int length) {
    int temp;
    for (int i = 0; i < length / 2; i++) {
        temp = array[i];
        array[i] = array[length - 1 - i];
        array[length - 1 - i] = temp;
    }
}
