
  #include "dk_tool.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h> 


int countElem() {
	int f;
	 	printf("¬ведите кол-во элементов: ");
    	int result_A;
    		result_A = scanf("%d",&f);

			while(result_A != 1 || (int)f != f  || f < 0)
			{ 	
				printf("\n¬ведите кол-во элементов заново: ");
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
		 printf("\n‘айл дл€ считывани€ данных: ");
            char *nameIn=(char *)malloc(256);
            scanf("%s",nameIn);
            FILE *fp1=fopen(nameIn,"r");
            while( (fp1=fopen(nameIn,"r")) == 0 )
            {
                printf("\n‘айл не найден!\n");
                printf("\n‘айл дл€ считывани€ данных: ");
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
void inFile(int* A, int f) {
	int i;

			 printf("\n‘айл дл€ сохранени€ данных: ");
            char *nameOut=(char *)malloc(256);
            scanf("%s",nameOut);
            FILE *fp2=fopen(nameOut,"w");
            for (i = 0; i < f; i++) 
            {
                fprintf(fp2,"%i ",A[i]);     
            }
            fclose(fp2);
            fflush(fp2);
            printf("ƒанные успешно сохранены");
}
int* sortBuble(int* A, int f) {
	
	int i,j;
clock_t start = clock();   //јјјјјјјјјјјјјјјјјјјјјјјјјјјј	
	for(i = 0 ; i < f - 1; i++) { 
       // сравниваем два соседних элемента.
       for(j = 0 ; j < f - i - 1 ; j++) {  
           if(A[j] > A[j+1]) {           
              // если они идут в неправильном пор€дке, то  
              //  мен€ем их местами. 
              int tmp = A[j];
              A[j] = A[j+1] ;
              A[j+1] = tmp; 
           }
        }
         clock_t end = clock();   double seconds = (double)(end - start) / CLOCKS_PER_SEC; 
		 printf("¬рем€ выполнени€: %f sec\n", seconds);////////аааааааааааааааа
    }
    return A;
}
    int* sortPush(int* A, int f) {
	
	int pass, j, hold;
clock_t start = clock();//јјјјјјјјјјјјјјјјјјјјјјјјјјјјјјјјјјјјјја
	for (pass = 0; pass < f-1; pass++){
		for (j = pass+1; j < f; j++){
			if (A[pass]>A[j]){
				hold = A[j];
				A[j] = A[pass];
				A[pass] = hold;
			}
		}
		clock_t end = clock();   double seconds = (double)(end - start) / CLOCKS_PER_SEC; 
		 printf("¬рем€ выполнени€: %f sec\n", seconds);////////аааааааааааааааа
	}

    return A;
}
int* sortChoose(int* A, int f) {
	
	int i,j;
	clock_t start = clock();//јјјјјјјјјјјјјјјјјјјјјјјјјјјјјјјјјјјјјја
	for (i = 0; i < f - 1; i++) {
/* устанавливаем начальное значение минимального индекса */
        int min_i = i;
	/* находим индекс минимального элемента */
	for (j = i + 1; j < f; j++) {
		if (A[j] < A[min_i]) {
			min_i = j;
		}
	}
	/* мен€ем значени€ местами */
	int temp = A[i];
	A[i] = A[min_i];
	A[min_i] = temp;
	clock_t end = clock();   double seconds = (double)(end - start) / CLOCKS_PER_SEC; 
		 printf("¬рем€ выполнени€: %f sec\n", seconds);////////аааааааааааааааа
}

    return A;
}
int* sortInterface(int* A, int f) {
	int finish = 0;
	int var;
	while(finish != 1)
	{ 	
		printf("—ортировать: ");
		printf("\n1. ѕузырьком; ");
		printf("\n2. ¬ыбором; ");
		printf("\n3. ¬ставкой; ");;
	   	scanf("%d",&var); 
		switch (var) {
		case 1:
		A = sortBuble(A,f);
			finish = 1;
  		 break; 
  		 case 2:
  		 	A = sortChoose(A,f);
			finish = 1;
  		 break;
		 case 3:
			A = sortPush(A,f);
			finish = 1;
    
  		 break;

		default:
 
  		break;
		} 	
	}
	return A;
	
}
void interface(void) {
	int finish = 0;
	int b_in_file = 0;
	int var = 0;
	int q = 0;
	int* A;
		int i;
	
	int f;
	
	while(finish != 1) //проверка на корректность ввода
	{ 	
		printf("ћеню: ");
		printf("\n1. —оздать/перезаписать массив с данными; ");
		printf("\n2. —ортировать массив с данными; ");
		printf("\n3. «аписать в файл массив с данными; ");
		printf("\n4. ѕолучить из файла массив с данными; ");
		printf("\n5. ¬ывести массив с данными на экран; ");
		printf("\n6. ¬ыход;\n");
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
  		 A = sortInterface(A, f);
  		 system("cls");
  			print(A,f);
  			getch();
  		 break;
		 case 3:
				if( q == 0 )
            {
                printf("\nƒанных дл€ записи нету");
                getch();
                continue;
            }
            inFile(A,f);
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
