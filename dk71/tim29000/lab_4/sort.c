#include "sort.h"
#include "LinkedNode.h"

int partitionIt(IntList *List, int LeftIndex, int RightIndex, int Pivot)
{
	int Left = LeftIndex - 1;
	int Right = RightIndex + 1;

	while (1)
	{
		while (Left < RightIndex && NodeAtIndex(List, ++Left)->data < Pivot);

		while (Right > LeftIndex && NodeAtIndex(List,--Right)->data > Pivot);

		if (Left >= Right)
		{
			break;
		}
		else
		{

			SwapNodesByIndex(List, Left, Right);
		}
	}

	return Left;
}


void Sort(IntList *List, int LeftIndex, int RightIndex)
{
	if (RightIndex - LeftIndex <= 0)
	{
		return;
	}

	int Pivot = NodeAtIndex(List, RightIndex)->data;
	int PartitionIndex = partitionIt(List, LeftIndex, RightIndex, Pivot);

	Sort(List, LeftIndex, PartitionIndex - 1);

    Sort(List, PartitionIndex + 1, RightIndex);
}
