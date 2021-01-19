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

	cout << "List:\t";
	while (temp != NULL)
	{
		cout << temp->value << "\t";
		temp = temp->pNext; 
	}
	cout << endl;
}

bool List::AddTail(int value)
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
	
	return true;
}

bool List::DeleteHead()
{
	if (GetCount() == 0)
	{
		return false;

	}
	else if (GetCount() >= 1)
	{
		Node* temp = pHead;
		if (pHead != NULL)
		{
			pHead = pHead->pNext;
		}

		count--;

		delete temp;
		return true;
	}
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

bool List::AddToHead(const int& value)
{
	Node* temp = new Node;

	temp->value = value;
	temp->pNext = pHead;

	pHead = temp;

	count++;
	return true;
}

bool List::DeleteTail()
{
	if (GetCount() == 0)
	{
		return false;
	}
	else if (GetCount() > 1)
	{
		Node* del = pTail;
		Node* temp = pHead;

		while (temp->pNext != pTail)
		{
			temp = temp->pNext;
		}

		temp->pNext = NULL;
		pTail = temp;
		count--;
		delete del;

		return true;
	}
	else if (GetCount() == 1)
	{
		Clear();
		List();
		return true;
	}

}

bool List::DeleteByIndex(int value)
{
	int maxIndex = 0;

	if (value < count)
	{
		Node* temp = pHead;//Last
		Node* tmp = pHead;//last but one

		for (int i = 0; i < value; i++)
		{
			temp = temp->pNext;
		}

		if (temp != pTail && temp != pHead)
		{
			while (tmp->pNext != temp)
			{
				tmp = tmp->pNext;
			}

			tmp->pNext = temp->pNext;
			delete temp;
			count--;

			return true;
		}
		else if (temp == pHead)
		{
			return DeleteHead();
		}
		else if (temp == pTail)
		{
			return DeleteTail();
		}
		else
		{
			return false;
		}

	}
	else
	{
		return false;
	}

}

int *List::SearchByNumber(const int Number, int& Size)
{
	bool FindSimilar = false;
	Node* temp = pHead;
	int Count = 0, index = 0;

	while (temp != NULL)
	{
		if (temp->value == Number)
		{
			Count++;
		}
		temp = temp->pNext;
	}
	delete temp;
	int* Index = new int[Count]; 
	Size = Count;
	Count = 0;
	Node* tmp = pHead;

	while (tmp != NULL)
	{
		if (tmp->value == Number)
		{
			Index[Count] = index;
			Count++;
		}
		index++;
		tmp = tmp->pNext;
	}

	delete tmp;

	return Index;
}

bool List::AddbyIndex(int Index, int Value)
{
	if (Index > 0 && Index < (count - 1))
	{
		Node* temp = pHead;
		Node* tmp = pHead;
		Node* Add = new Node;

		for (int i = 0; i < Index; i++)
		{
			temp = temp->pNext;
		}

		while (tmp->pNext != temp)
		{
			tmp = tmp->pNext;
		}

		Add->value = Value;
		Add->pNext = temp;
		tmp->pNext = Add;

		return true;
	}
	else if (Index == 0)
	{
		return AddToHead(Value);
	}
	else if (count > 1 && Index == count - 1)
	{
		return AddTail(Value);
	}
	else if (count == 1 && Index == count)
	{
		AddTail(Value);
	}
	else
	{
		return false;
	}
}
