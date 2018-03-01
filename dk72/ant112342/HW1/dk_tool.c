#include<stdio.h>
#include<ctype.h>
#include "dk_tool.h"
int lengthofstring(char *s,char *w)
{
    int i=0,j=0,counter=0;/*initiate our variables */
    for (i = 0;s[i] != '\0';i++)/*cicle for (змінна і буде інкрементуватися до того моменту поки масив s[i] не буде рівним '\0') */
        {
        if(s[i]==w[j])/*if first element of string massive is equal to elenent of word massive then we check if the next element of is equal to '\0'  */
        {
            if(w[j+1]=='\0')/*if the next element of word massive is equal '\0' then out couner will increment and variable j will equal to zero (thats means that we continue to check word with next element of massive of string)   */
            {
                counter++;
                j=0;
            }
    else/*another way incrementation of the j (next element of massive of word) */
        {
                j++;
        }
        }
        else
            j=0;/*if s[i] is not equal to w[j] then j will equal to zero*/
            }
return counter;/*return the number of words or counter*/
    }

