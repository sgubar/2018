#include <stdio.h>
#include <locale.h>
#include "DKsort.h"

int main()
{
    setlocale(LC_CTYPE, "Ukr");
    int size = 0, selection = 0;

    printf("Введiть розмiр масиву: ");
    scanf("%d", &size);
    while(size <= 0)
    {
        printf("Непiдходяще значення, спробуйте знову: ");
        scanf("%d", &size);
    }
    int arr[size];

    randsymbol(arr, size);

    infile(arr, size, "Не відсортовані дані.txt");

    printf("Оберiть спосiб сортування:\n 1 - Сортування бульбашкою\n 2 - Сортування вибором\n 3 - Сортування вставкою\nВаш вибiр: ");

    sortingtype(arr, size, selection);
}
