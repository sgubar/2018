#include <stdio.h>
#include <stdlib.h>
#include "dk_tools.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int word_ct(char myString[100])
{
    int pusto = 0;
    int slovo = 0;
    int length = strlen(myString);
    int i = 0;
    for (; i<=length; i++)// ��� ����� �����������
    {

        if (myString[i] == ' ' && myString[i+1] != ' ' )//������� �������
        {
            slovo++;
        }
        
    }
    if(length < 1 ) // ���� ��������
    {
     slovo = 0;
    }
    else if( length != 0 && slovo == 0 && myString[length-1] != ' ') // ���� ��������
    {
      slovo = 1;
    }
    else
    {
       slovo++;
    }
    return slovo;
}
