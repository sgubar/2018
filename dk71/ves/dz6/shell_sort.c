#include "shell_sort.h"
#include "SingleLinkedNode.h"
#include "SingleLinkedList.h"


void shellSort(FloatList *aList)
{
	int i, j, step;
	int count = SLCountList(aList);
	FloatNode *buffer;

	for (step = count / 2; step > 0; step /= 2)
	{
		for (i = step; i < count; i++) 
		{
			buffer = SLNodeAtIndex(aList, i);
			for (j = i; j >= step; j -= step)
			{
				if (buffer->value < SLNodeAtIndex(aList, j - step)->value) {
					SLSwapNodesByIndex(aList, j - step, j);
				}
				else {
					break;
				}
			}
		}
	}
		return;
}


	