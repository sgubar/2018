int Factorial(int num)
{
    int factorial = 1;
    if (num > 0)
    {
      for(int i=1; i <= num; i++ )
        {
            factorial = factorial*i;
        }
    }
    return factorial;
}
float REsult(float A,float B,float C)
{
    if ( B < 0)
    {
        printf("ERROR. We did not learn the factorial of a negative number (((\n");
        return 0;
    }
    float drob;
    if (B + (C*C)==0)
    {
        printf("ERROR. To my regret I can not divide by zero, but I would like so much\n");
        return 0;
    }
    drob = (A*B)/(B+(C*C));
    float sum = 0;
        for(int D = 0; D <= B; D++)
        {
            sum = sum + Factorial(D);
        }
    float result = sum + drob ;
            return result;
}

