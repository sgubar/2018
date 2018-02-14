#include <stdio.h>
#include "dk_tool.h"

int main(int argc, const  char * argv [])
{
printf("Please enter the string\n");/*Program write on screen "Please enter the string" */
char *s;/* initiate the pointer s (or string)*/
scanf("%s",&s);/*Enter the string*/
printf("%d\n",lengthofstring(&s));/*Program write the result */

}
