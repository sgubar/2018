#include "DR_6_V2.h"
#include "SortDR6V2.h"

void sPrintList(const FloatList *aList)
{
	for (int i = 0; i < CountList(aList); i++)
	{
		FloatNode *theNode = NodeAtIndex(aList, i);
		if (NULL != theNode)
		{

      printf("|%6.1f|",  theNode->value);
		}

	}
printf("\n\n");
}

/*========================================================*/
void ShellsSort(FloatList *aList)
{
printf("FloatList->count================   %d\n",aList->count);
int i,j,k,n=aList->count;
FloatNode *i_Node;
FloatNode *j_Node;
FloatNode *jk_Node;
float temp;
for (k=n/2; k > 0; k/=2)
    for (i=k; i < n; i++)
{
i_Node = NodeAtIndex(aList, i);
temp=i_Node->value;
printf("===================   i_Node->value =========   Узел[%d].value = %8.2f\n", i, i_Node->value);
      for (j=i; j>=k; j-=k)
{
jk_Node = NodeAtIndex(aList, j-k);
j_Node = NodeAtIndex(aList, j);
 printf("jk_Node = NodeAtIndex(aList, j-k);======================Узел[%d].value = %8.2f\n", j-k, jk_Node->value);
printf("========j_Node->value===========================Узел[%d].value = %8.2f\n", j, j_Node->value);


        if(temp < jk_Node->value)
{
j_Node->value=jk_Node->value;
}
    else
        break;
}
j_Node->value=temp;

}
printf("Отсортировали по возрастанию методом SHELL\n");

PrintList(aList);
}
