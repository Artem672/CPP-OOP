#pragma once
#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

struct Node
{
	int value;
	Node* pNext;
};

class List
{
	Node* pHead;
	Node* pTail;
	int count;

public:
	List();
	~List();

	void Print() const;
	bool AddTail(int value);
	bool DeleteHead();
	int GetCount() const;
	void Clear();
	bool AddToHead(const int& value);
	bool DeleteTail();
	bool DeleteByIndex(int value);
	int* SearchByNumber(const int Number, int& Size);
	bool AddbyIndex(int Index,int Value);
};