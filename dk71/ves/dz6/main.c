#include "shell_sort.h"

void doTestSLList();
void doPrintSLList(const FloatList *aList);

int main(int argc, const char * argv[])
{
	doTestSLList();
	system("pause");
	return 0;
}

void doTestSLList()
{
	printf("Start to demo a single-linked list ...\n");

	FloatNode *theNode1 = SLCreateNodeWithFloatValue(7.5);
	
	FloatList *theList = SLCreateList();
	printf("number of elements: %d\n", SLCountList(theList));

	SLAddNode(theList, theNode1);
	printf("number of elements: %d\n", SLCountList(theList));


	SLAddNode(theList, SLCreateNodeWithFloatValue(1));
	SLAddNode(theList, SLCreateNodeWithFloatValue(7.85));
	SLAddNode(theList, SLCreateNodeWithFloatValue(8.43));

	FloatNode *theNode = SLCreateNodeWithFloatValue(5.01);

	SLInsertNodeAtIndex(theList, theNode, 4);
	SLInsertNodeAtIndex(theList, SLCreateNodeWithFloatValue(10), 4);

	doPrintSLList(theList);
	theNode = SLRemovedNodeAtIndex(theList, 2);
	SLInsertNodeAtIndex(theList, theNode, 4);
	//theNode = SLRemovedNodeAtIndex(theList, 1);
	//SLInsertNodeAtIndex(theList, theNode, 3);



	printf("After removing: \n");
	doPrintSLList(theList);

	printf("Sorting: \n");
	shellSort(theList);

	doPrintSLList(theList);

	SLFreeList(theList);

	printf("Done.\n");
}

void doPrintSLList(const FloatList *aList)
{
	for (int i = 0; i < SLCountList(aList); i++)
	{
		FloatNode *theNode = SLNodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("node[%d].value = %.2f\n", i, theNode->value);
		}
	}
}