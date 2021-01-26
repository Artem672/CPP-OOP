#include "Queue.h"

Queue::Queue(int max)
{
	maxLength = max;
	queue = new unsigned char[maxLength];
	queueLength = 0;
}

Queue::~Queue()
{
	delete[] queue;
}

void Queue::Add(unsigned char el)
{
	if (!isFull())
	{
		queue[queueLength++] = el;
	}
}

unsigned char Queue::Extract()
{
	if (!isEmpty())
	{
		unsigned char temp = queue[0];
		for (int i = 1; i < queueLength; i++)
		{
			queue[i - 1] = queue[i];
		}
		queue[queueLength - 1] = temp;

		return temp;
	}

	return CHAR_MIN;
}

bool Queue::isFull() const
{
	return queueLength == maxLength;
}

bool Queue::isEmpty() const
{
	return queueLength == 0;
}

int Queue::GetCount() const
{
	return queueLength;
}

void Queue::Clear()
{
	queueLength = 0;
}

void Queue::Show() const
{
	/*
	for (int i = 0; i < queueLength; i++)
	{
		cout << queue[i] << "\t";
	}
	*/
	cout << "\t\t|\t\t\t|" << endl
		<< "\t\tv\t\t\t|" << endl;
	cout << "\t\t" << queue[0] << "\t\t\t|" << endl
		<< "\t" << queue[1] << "\t\t" << queue[5] << "\t\t|" << endl
		<< "\t" << queue[2] << "\t\t" << queue[4] << "\t\t|" << "\tSymbol-> " << queue[0] << endl
		<< "\t\t" << queue[3] << "\t\t\t|" << endl;


	cout << endl << "-------------------------------------" << endl;
}

unsigned char Queue::GetFirstElement()
{
	if (!isEmpty())
	{
		return queue[0];
	}

	return CHAR_MIN;
}
