#include <stdio.h>
#include <stdlib.h>
#include"dk_sort.h"
#include<time.h>


void read_it_from()
{
    FILE*file;
    int m=5043;
    int n =32;
    char *words[m][n];
    int i;
	if ((file = fopen("some words.txt","r")) == NULL)
        printf("impossible\n");
     else{
            i=0;
        while(!feof(file))
        {
           fscanf(file,"%s", &words[i]);
           printf("%s\n", &words[i]);
           i++;
        }
     }

     fclose(file);
     FILE*file_writing;
 Bubble_sort(words,file_writing);
 Choice_sort(words,file_writing);
 Inception_sort(words,file_writing);
}
void Bubble_sort(char *words[][32],FILE*file_writing)
{

    int m=5043,i,j;
    float TimeStart1,TimeStop1;
    char temp[32];
    if ((file_writing = fopen("sort.txt","w+")) == NULL)
        printf("impossible\n");
     else{

    TimeStart1 = clock()/(float)CLOCKS_PER_SEC;
for(i=0;i<m;i++)
{
for(j=i;j<m;j++)
{

if(strcmp(words[i],words[j])>0)
{

strcpy(temp,words[i]);
strcpy(words[i],words[j]);
strcpy(words[j],temp);
}
}
}
TimeStop1 = clock()/(float)CLOCKS_PER_SEC;
fprintf(file_writing,"SORTED\n\n");
for(i=0;i<m;i++)
{
fprintf(file_writing,"%s\n",words[i]);
}
fprintf(file_writing,"The bubble time is %f\n",TimeStop1-TimeStart1);
}
fclose(file_writing);
}
void Choice_sort(char *words[][32],FILE*file_writing)
{
    int m=5043,i,j;
    float TimeStart2,TimeStop2;
    char temp[32];
    if ((file_writing = fopen("sort.txt","a")) == NULL)
        printf("impossible\n");
     else
     {
   int min;
TimeStart2 = clock()/(float)CLOCKS_PER_SEC;
    for(i = 0; i < m-1; i++)
    {

    min=i;
        for(j = i+1; j < m; j++)
        {
            if(strcmp(words[min],words[j])>0)
{

                min = j;
    strcpy(temp, words[i]);
    strcpy(words[i], words[min]);
        strcpy(words[min],temp);
}
        }
    }
    TimeStop2 = clock()/(float)CLOCKS_PER_SEC;
    fprintf(file_writing,"The choice time is %f\n",TimeStop2-TimeStart2);
}
fclose(file_writing);
}

void Inception_sort(char *words[][32],FILE*file_writing)
{
     float TimeStart,TimeStop;
    char temp[32];
    int j,i;
     int m=5043;
     if ((file_writing = fopen("sort.txt","a")) == NULL)
        printf("impossible\n");
     else
     {
    TimeStart = clock()/(float)CLOCKS_PER_SEC;
    for (j = 1; j < m; j++) {
        strcpy(temp, words[j]);
        for (i = j; strcmp(words[i - 1],temp) > 0 && i > 0; i--) {
            strcpy(words[i], words[i - 1]);
        }

        strcpy(words[i],temp);
    }
    TimeStop = clock()/(float)CLOCKS_PER_SEC;
    fprintf(file_writing,"The inception time is %f\n",TimeStop-TimeStart);
}
fclose(file_writing);

}


