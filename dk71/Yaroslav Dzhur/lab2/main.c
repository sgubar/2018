#include <stdio.h>
#include <locale.h>
#include "DKsort.h"

int main()
{
    setlocale(LC_CTYPE, "Ukr");
    int size = 0, selection = 0;

    printf("����i�� ����i� ������: ");
    scanf("%d", &size);
    while(size <= 0)
    {
        printf("���i������� ��������, ��������� �����: ");
        scanf("%d", &size);
    }
    int arr[size];

    randsymbol(arr, size);

    infile(arr, size, "�� ���������� ���.txt");

    printf("����i�� ����i� ����������:\n 1 - ���������� ����������\n 2 - ���������� �������\n 3 - ���������� ��������\n��� ���i�: ");

    sortingtype(arr, size, selection);
}
