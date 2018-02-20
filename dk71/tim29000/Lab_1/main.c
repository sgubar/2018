#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



 int main()
{
    int A;
    int B;
  printf("Enter A\n");
  printf("A = ");
  scanf("%d",&A);
  printf("Enter B\n");
  printf("B = ");
  scanf("%d",&B);
  if (B==-2*A)
    {
         printf("       EEEEE  RRRRR  RRRRR   OOO   RRRRR     4   4  00000  4   4\n");
         printf("       E      R   R  R   R  O   O  R   R     4   4  0   0  4   4\n");
         printf("       EEEEE  RRRRR  RRRRR  O   O  RRRRR     44444  0   0  44444\n");
         printf("       E      R R    R R    O   O  R R           4  0   0      4\n");
         printf("       EEEEE  R   R  R   R   OOO   R   R         4  00000      4\n");
         return 0;
    }
         else if(A<0)
         {
         printf("       EEEEE  RRRRR  RRRRR   OOO   RRRRR     4   4  00000  4   4\n");
         printf("       E      R   R  R   R  O   O  R   R     4   4  0   0  4   4\n");
         printf("       EEEEE  RRRRR  RRRRR  O   O  RRRRR     44444  0   0  44444\n");
         printf("       E      R R    R R    O   O  R R           4  0   0      4\n");
         printf("       EEEEE  R   R  R   R   OOO   R   R         4  00000      4\n");

  return 0;
         }


      int result_1;
      result_1 = fac(A);

      int result_2;

      result_2 = mod(A,B);

      double Q;
      Q = REPLY(result_1, result_2);
      printf("       A!        \n");
      printf("Q = -------- = %f\n",Q);
      printf("    |2A + B|     \n");
}

