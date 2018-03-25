#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "dk_tool.h"

char str2[5];/*вспомогательная строка*/
int entered_character;/*это введённый символ*/
int result16=0;/*сюда результат запишем*/
int hexadecimal_factor=1;/*фактор шестнадцатеричного счисления*/

int translating16_10 (char *str)
{
sscanf(str,"%4s", str2 );/*считываем в переменную только 4 первых символа, некорректные отброшены*/
/*printf("str2=%.4s\n",str2);*/

char lenstr;/*эта переменная нужна для подсчёта количества символов функцией - "strlen"*/
lenstr=strlen(str2);
/*printf("lenstr=%d\n",lenstr);*/
for(int i=lenstr-1; i>=0; i--)
{
if (str2[i]=='A'||str2[i]=='a')
{entered_character=10;}
if (str2[i]=='B'||str2[i]=='b')
{entered_character=11;}
if (str2[i]=='C'||str2[i]=='c')
{entered_character=12;}
if (str2[i]=='D'||str2[i]=='d')
{entered_character=13;}
if (str2[i]=='E'||str2[i]=='e')
{entered_character=14;}
if (str2[i]=='F'||str2[i]=='f')
{entered_character=15;}
if (str2[i]<=57 && str2[i]>=48)
{entered_character=(int)(str2[i]-48); /*int обращает символ в цифру*/
}
result16=entered_character*hexadecimal_factor+result16;
hexadecimal_factor=hexadecimal_factor*16;
}
if (result16==0)
{
    printf("Incorrect value entered\n");
    printf("Введёно некорректное значение \n");
}
return result16;
}
