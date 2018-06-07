#include "dk_tool.h"

int main() {
	List* FirstList = newList();
	Add(14, FirstList);
	Add(5, FirstList);
	Add(13, FirstList);
	Add(8, FirstList);
	Add(11, FirstList);
	Add(52, FirstList);
	Add(1, FirstList);
	AddAtIndex(123321, 3, FirstList);
	Write(FirstList);
	Sort(FirstList);
	Write(FirstList);
	return 0;
}
