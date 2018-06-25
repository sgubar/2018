#include "Dz_6_sort.h"
#include "Dz_6_Node.h"

int partitionIt(IntList *aList, int aLeftIndex, int aRightIndex, int aPivot)
{
	int thePivot = SLNodeAtIndex(aList, aRightIndex)->value;
	int theLeft = aLeftIndex - 1;
	int theRight = aRightIndex + 1;

	while (1)
	{

		while (theLeft < aRightIndex && SLNodeAtIndex(aList, ++theLeft
		)->value < aPivot);


		while (theRight > aLeftIndex && SLNodeAtIndex(aList,--theRight)->value > aPivot);

		if (theLeft >= theRight)
		{
			break;
		}
		else
		{


			SLSwapNodesByIndex(aList, theLeft, theRight);
		}
	}

	return theLeft;
}


void quickSort(IntList *aList, int aLeftIndex, int aRightIndex)
{
	if (aRightIndex - aLeftIndex <= 0)
	{
		return;
	}

	
	int thePartitionIndex = partitionIt(aList, aLeftIndex, aRightIndex, thePivot);

	quickSort(aList, aLeftIndex, thePartitionIndex - 1);


	quickSort(aList, thePartitionIndex + 1, aRightIndex);
}

