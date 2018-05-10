
  #include "dk_tool.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h> 


int countElem() {
	int f;
	 	printf("Введите кол-во элементов: ");
    	int result_A;
    		result_A = scanf("%d",&f);

			while(result_A != 1 || (int)f != f  || f < 0)
			{ 	
				printf("\nВведите заново кол-во элементов: ");
	   			result_A = scanf("%f",&f);
	   			scanf("%*[^\n]");   	
			}
	return f;
}
int* input(int f)
{
	srand(time(NULL));
    int*Arr;


	int p;
    Arr=(int*)malloc(sizeof(int)*f);
    for( p=0; p<f; p++)
    {
        Arr[p]=rand() % 100;
    }

    printf("\n");
   
    return Arr;
}
void print(int* arr, int f) 
{
	int p;

  for( p=0; p<f; p++)
    {
        printf("%d ", arr[p]);
    }
    printf("\n");
}

int* fromFile()
{
		int* A;
		int i,f;
		 printf("\nФайл для считывания данных: ");
            char *nameIn=(char *)malloc(256);
            scanf("%s",nameIn);
            FILE *fp1=fopen(nameIn,"r");
            while( (fp1=fopen(nameIn,"r")) == 0 )
            {
                printf("\nФайд не найден!!\n");
                printf("\nФайл для считывания данных: ");
                scanf("%s",nameIn);
            }
           f = countElem();
			  A = (int*)malloc(sizeof(int)*f);
            for (i=0;i<f;i++)
            {
                fscanf (fp1,"%i",&A[i]);
          
            }
           
            fflush(fp1);
            fclose(fp1);
            return A;
}
void inFile(int search_el) {
	int i;

			 printf("\nФайл для сохранения данных: ");
            char *nameOut=(char *)malloc(256);
            scanf("%s",nameOut);
            FILE *fp2=fopen(nameOut,"w");
             if (search_el != -1)
    {
        fprintf(fp2,"\nИндекс элемента %d\n", search_el); 
    } else {
        fprintf(fp2,"\nЭлемент не найден\n");
       
    }
                    
            
            fclose(fp2);
            fflush(fp2);
            printf("Данные успешно сохранены\n");
}
int* sortShell(int mass[], int n) {
	clock_t start = clock();
	 int i, j, step;
    int tmp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = mass[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp > mass[j - step])
                    mass[j] = mass[j - step];
                else
                    break;
            }
            mass[j] = tmp;
        }
        print(mass, n);
          clock_t end = clock();
  double seconds = (double)(end - start) / CLOCKS_PER_SEC;
  printf("Время выполнения: %f sec\n", seconds);
    return mass;
}
int binarysearch(int a, int mass[], int n)
{
    clock_t start = clock();
    int low, high, middle;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        middle = (low + high) / 2;
        if (a < mass[middle]) {
            high = middle - 1;
         
        }
        else if (a > mass[middle]) {
            low = middle + 1;
         
        }
            
        else {
                     clock_t end = clock();
  double seconds = (double)(end - start) / CLOCKS_PER_SEC;
  printf("Время выполнения: %f sec\n", seconds);
  
  return middle;
        }
            
    }
       clock_t end = clock();
  double seconds = (double)(end - start) / CLOCKS_PER_SEC;
  printf("Время выполнения: %f sec\n", seconds);
  getch();
    return -1;
}
 
int* sortInterface(int* A, int f) {
	int finish = 0;
	int var, a;
	int k;
	while(finish != 1) 
	{ 	
		printf("Сортировка/поиск: ");
		printf("\n1. Shell; ");
		printf("\n2. Двоичный поиск; ");
	   	scanf("%d",&var); 
		switch (var) {
		case 1:
		A = sortShell(A,f);
			finish = 2;
  		 break; 
  		 case 2:
  		 if(finish == 2) {
  		 printf("\nВведите элемент поиска: ");
    scanf("%d", &a);
    
    k = binarysearch(a, A, f);
    
   
  			
			finish = 1;
  		 } else {
  		     
  		     printf("\nОтсортируйте массив \n");
  		 }
  		 break;
	

		default:
 
  		break;
		} 	
	}
	return k;
	
}
void interface(void) {
	int finish = 0;
	int b_in_file = 0;
	int var = 0;
	int q = 0;
	int file_search = 0;
	int* A;
		int i;
	
	int f,search_el;
	
	while(finish != 1) 
	{ 	
		printf("Меню: ");
		printf("\n1. Создать/перезаписать массив с данными; ");
		printf("\n2. Сортировать и выполнить поиск; ");
		printf("\n3. Записать данные; ");
		printf("\n4. Получить из файла массив с данными; ");
		printf("\n5. Вывести массив с данными на экран; ");
		printf("\n6. Выход;\n");
	   	scanf("%d",&var); 
		switch (var) {
		case 1:
			
			 
  			f= countElem();
  			A = input(f);
  			q++;
  			system("cls");
  			print(A,f);
  			getch();
  		 break; 
  		 case 2:
  		 search_el = sortInterface(A, f);
  		 file_search = 1;
  		  if (search_el != -1)
    {
        printf("\nИндекс элемента %d\n", search_el);
    } else {
        
        printf("\nЭлемент не найден\n");
    }
   
  			
  		
  			
  			getch();
  			 system("cls");
  		 break;
		 case 3:
				if( file_search == 0 )
            {
                printf("\nДанных для записи нету");
                getch();
                continue;
            }
            inFile(search_el);
            getch();
            system("cls");
    
  		 break;
  		 case 4:
  		 	A = fromFile();
  		  system("cls");
           	print(A,f);
            q++;
            getch();
  		 break;
		case 5:
			system("cls");
			print(A,f);
			getch();
  		 break;
		case 6:
			finish = 1;
  		 break;
		default:
 
  		break;
		} 	
	}
	
}

