#pragma once
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <ctime>
#include <time.h>
#include <conio.h>

using namespace std;

class Queue
{
	unsigned char* queue;
	int maxLength;
	int queueLength;

public:
	Queue(int max);
	~Queue();

	void Add(unsigned char el);
	unsigned char Extract();

	bool isFull() const;
	bool isEmpty() const;
	int GetCount() const;
	void Clear();
	void Show() const;
	unsigned char GetFirstElement();
};
