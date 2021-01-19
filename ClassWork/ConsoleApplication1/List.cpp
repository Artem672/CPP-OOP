#include "List.h"

List::List()
{
	pHead = pTail = NULL;
	count = 0;
}

List::~List()
{
	Clear();
}

void List::Print() const
{
	Node* temp = pHead;

	while (temp != NULL)
	{
		cout << temp->value << "\t";
		temp = temp->pNext; // ïåðåõîäèìî íà íàñòóïíó íîäó
	}
	cout << endl;
}

void List::AddTail(int value)
{
	
	Node* forAdd = new Node;
	forAdd->value = value; 
	forAdd->pNext = NULL; 

	if (pHead != NULL) 
	{
		pTail->pNext = forAdd;
		pTail = forAdd; 
	}
	else pHead = pTail = forAdd; 

	count++;
}

void List::DeleteHead()
{
	Node* temp = pHead;
	if (pHead != NULL)
	{
		pHead = pHead->pNext;
	}

	count--;

	delete temp;
}

int List::GetCount() const
{
	return count;
}

void List::Clear()
{
	while (pHead)
	{
		DeleteHead();
	}

	count = 0;
}

void List::AddToHead(const int& value)
{
	Node* temp = new Node;

	temp->value = value;
	temp->pNext = pHead;

	pHead = temp;
}

void List::DeleteTail()
{
	Node* del = pTail;
	Node* temp = pHead;

	while (temp->pNext != pTail)
	{
		temp = temp->pNext;
	}

	temp->pNext = NULL;
	pTail = temp;

	delete del;
	
}

void List::DeleteByIndex(int value)
{
	int maxIndex = 0;

	Node* temp = pHead;
	Node* tmp = pHead;
	if (value <= count)
	{
		for (int i = 0; i < value; i++)
		{
			temp = temp->pNext;
		}

		while (tmp->pNext != temp)
		{
			tmp = tmp->pNext;
		}

		if (temp != pTail)
		{
			tmp->pNext = temp->pNext;

			delete temp;
		}
		else if (temp == pHead)
		{
			DeleteHead();
		}
		else
		{
			DeleteTail();
		}
	}

}
