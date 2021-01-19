#pragma once
#include <iostream>

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
	void AddTail(int value);
	void DeleteHead();
	int GetCount() const;
	void Clear();
	void AddToHead(const int& value);
	void DeleteTail();
	void DeleteByIndex(int value);
};