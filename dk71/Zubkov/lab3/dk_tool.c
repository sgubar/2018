
  #include "dk_tool.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h> 


int countElem() {
	int f;
	 	printf("������� ���-�� ���������: ");
    	int result_A;
    		result_A = scanf("%d",&f);

			while(result_A != 1 || (int)f != f  || f < 0)
			{ 	
				printf("\n������� ������ ���-�� ���������: ");
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
		 printf("\n���� ��� ���������� ������: ");
            char *nameIn=(char *)malloc(256);
            scanf("%s",nameIn);
            FILE *fp1=fopen(nameIn,"r");
            while( (fp1=fopen(nameIn,"r")) == 0 )
            {
                printf("\n���� �� ������!!\n");
                printf("\n���� ��� ���������� ������: ");
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

			 printf("\n���� ��� ���������� ������: ");
            char *nameOut=(char *)malloc(256);
            scanf("%s",nameOut);
            FILE *fp2=fopen(nameOut,"w");
             if (search_el != -1)
    {
        fprintf(fp2,"\n������ �������� %d\n", search_el); 
    } else {
        fprintf(fp2,"\n������� �� ������\n");
       
    }
                    
            
            fclose(fp2);
            fflush(fp2);
            printf("������ ������� ���������\n");
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
  printf("����� ����������: %f sec\n", seconds);
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
  printf("����� ����������: %f sec\n", seconds);
  
  return middle;
        }
            
    }
       clock_t end = clock();
  double seconds = (double)(end - start) / CLOCKS_PER_SEC;
  printf("����� ����������: %f sec\n", seconds);
  getch();
    return -1;
}
 
int* sortInterface(int* A, int f) {
	int finish = 0;
	int var, a;
	int k;
	while(finish != 1) 
	{ 	
		printf("����������/�����: ");
		printf("\n1. Shell; ");
		printf("\n2. �������� �����; ");
	   	scanf("%d",&var); 
		switch (var) {
		case 1:
		A = sortShell(A,f);
			finish = 2;
  		 break; 
  		 case 2:
  		 if(finish == 2) {
  		 printf("\n������� ������� ������: ");
    scanf("%d", &a);
    
    k = binarysearch(a, A, f);
    
   
  			
			finish = 1;
  		 } else {
  		     
  		     printf("\n������������ ������ \n");
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
		printf("����: ");
		printf("\n1. �������/������������ ������ � �������; ");
		printf("\n2. ����������� � ��������� �����; ");
		printf("\n3. �������� ������; ");
		printf("\n4. �������� �� ����� ������ � �������; ");
		printf("\n5. ������� ������ � ������� �� �����; ");
		printf("\n6. �����;\n");
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
        printf("\n������ �������� %d\n", search_el);
    } else {
        
        printf("\n������� �� ������\n");
    }
   
  			
  		
  			
  			getch();
  			 system("cls");
  		 break;
		 case 3:
				if( file_search == 0 )
            {
                printf("\n������ ��� ������ ����");
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

