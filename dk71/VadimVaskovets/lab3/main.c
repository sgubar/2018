#include <stdio.h>
#include <locale.h>
#include "dk_tool.h"
int main() {
	setlocale(LC_ALL, "RUS");
    remove("Finded.txt");

    long SIZE;
    int WhatFind;
    printf("������� ������ ������� - ");

    SIZE = ValueCheck();
    int i, a[SIZE];

    Random(a, SIZE);
    printArrToFile(a, SIZE, "UNsortedARR.txt");

    unsigned int start_time =  clock();
    quickSort(a, 0, SIZE - 1);
    printArrToFile(a, SIZE, "sortedARR.txt");
    unsigned int end_time = clock();
    unsigned int sort_time = end_time - start_time;
    printf("����� ���������� : %d ms\n", sort_time);

    printf("������� ����� ������� ���� �����");
    WhatFind = ValueCheck();
    Seach(a,WhatFind,SIZE);


    return 0;
}
