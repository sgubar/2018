
int word_ct(char myString[100])
{
    int nospace = 0;
    int space = 0;
    int length = strlen(myString);
    for (int i = 0; i<=length; i++)// прохождение по всем знакам предложения
    {

        if (myString[i] == ' ' && myString[i+1] != ' ' )//выкидываем лишние пробелы и считаем один из нескольки
        {
            space++;
        }
        if ( space == 1 && i != 0 && nospace == 0)//проверка, если строка начинается с пробела
        {
            nospace = 1;
            space = 0;
        }
        if ( i == 0 && myString[i] != ' ') //если строка не начинается с пробела
        {
            nospace = 1;
        }
    }
    if(length < 1 ) // когда в стороке нету символов
    {
     space = 0;
    }
    else if( length != 0 && space == 0 && myString[length-1] != ' ') // когда в строке нету пробелов ( 1 слово )
    {
      space = 1;
    }
    else if( myString[length-1] == ' ' || space == 0) //когда ничего не делаем ( строка заканчивается пробелом или в строке нету слов ( только пробелы) )
    {

    }

    else
    {
       space++;
    }
    return space;
}
