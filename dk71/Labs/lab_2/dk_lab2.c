#include <stdlib.h>
#include "dk_lab2.h"


void Type_chooser(int *mass, int quantity, int choice)
{
  scanf("%d", &choice);
 while(choice != 1 && choice != 2 && choice != 3)
    {
        printf("Specify the sort type: ");
        scanf("%d", &choice);
    }
      switch(choice)
    {
        case 1:
            Bubble(mass, quantity);
            Filewriter(mass, quantity, "Bubble.txt");
            break;
        case 2:
            Select(mass, quantity);
            Filewriter(mass, quantity, "Select.txt");
            break;
        case 3:
            Insert(mass, quantity);
            Filewriter(mass, quantity, "Insert.txt");
            break;
    }
}
void Bubble(int *mass, int quantity)
{
    int i, j;
    for (i = 1; i <= quantity - 1; i++)
    {
        for (j = 0; j <= quantity - 2; j++) {
            if (mass[j] > mass[j + 1])
            {
                swap(&mass[j], &mass[j + 1]);
            }
        }
    }
}
void Select(int *mass, int quantity)
{
 int i;
    for ( i = 0; i < quantity; i++) {
        int d = i;
         int j;
        for ( j = i+1; j < quantity; j++)
        {
            if (mass[j] < mass[d])
                d = j;
        }
        swap(&mass[d], &mass[i]);
    }
}
void Insert(int *mass, int quantity)
{
    int i;
    for ( i = 1; i <= quantity - 1; i++)
    {
        int x = mass[i];

        int j = i;
        while (j > 0 && mass[j - 1] > x)
        {
            mass[j] = mass[j - 1];
            j--;
        }
        mass[j] = x;
    }
}
void swap (int *x, int *y)
{
    int position = *x;
    *x = *y;
    *y = position;
}

void random(int *mass, int quantity)
{
    srand(time(NULL));
    int i;
    for( i = 0; i < quantity; i++)
    {

            mass[i] = rand() % 89 + 25;

    }
}

void Filewriter(int *mass, int quantity, char* name) {
    int i;
    FILE *file = fopen(name, "w");
    for ( i = 0; i < quantity; i++)
    {
        fprintf(file, "%c ", mass[i]);
    }
    fclose(file);
}


