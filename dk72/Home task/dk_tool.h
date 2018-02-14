#include<stdio.h>
#include<ctype.h>
    int lengthofstring(char *s)/* We create the function that can calculate the number of symbol*/
        {
        int n;/*initiate the variable that can calculate the length of string (counter)  */
        for (n = 0; *s != '\0';s++) /* in the cycle we equate variable n to zero and check our pointer, if *s!='\0' then increase by one while *s woun`t be equal '\0'*/
                {
                    n++;
                }
    int space; /*initiate the variable space  and equate it to zero (we just create a counter) */
    int j;/* initiate the variable j (for cycle)*/
                    for(j=0;j<n;j++) /*cycle for checking each element in the string  */
                        {
                    if (s[j]==' ')/*we check if the element of string equals the space then we increase our counter by one */
                            {
                                space++;

                            }
        }
    int symbol; /*initiate the variable symbol (the number of symbols in the string ) */
    symbol=n-space; /*the number of symbol equals to subtraction of the length of string and the number of space */
    return symbol; /* we return to main.c the result of the number of symbols*/
    }
