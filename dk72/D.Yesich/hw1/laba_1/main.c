
#include <stdio.h>
 #include <string.h>
 #include <ctype.h>
 #include"htd.h"


 int main()
 {
 int a,d,f,c,q;
 printf("%d",q);
 printf("%d",q);
 printf("enter the variable C \n");
 scanf("%d", &c);
  printf("enter the variable D \n",d);
 scanf("%d", &d);
 printf("%d",d);
  char s[10];
printf ( "Plese, enter string: \n");
scanf("%s",&s) ;
 printf ("\nRezult: \n");
 f = HEX_TO_DEC(s);
printf("\n%d \n",f);
  for(a=0;a<d;a++)
  {
      q = a*(f-c)+q;
  }
  printf("q=%d",q);
}
