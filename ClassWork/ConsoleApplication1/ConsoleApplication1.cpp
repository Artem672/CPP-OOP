#include "List.h"

void main()
{
	List list;

	list.AddTail(100);
	list.AddTail(3);
	list.AddTail(56);

	list.Print(); // 100 3 56
	list.DeleteHead();
	list.AddTail(51);
	list.Print(); // 3 56 51

	list.AddToHead(50); // 50 3 56 51
	list.Print();
	//list.DeleteTail();//50 3 56
	list.AddTail(15);
	list.DeleteByIndex(2); // 50 3 51 15
	list.Print();
	list.DeleteByIndex(3); // 50 3 51
	list.Print();
	list.DeleteByIndex(1);// 50 51
	list.Print();
}