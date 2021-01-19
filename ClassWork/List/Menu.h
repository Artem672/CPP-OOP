#pragma once
#include "List.h"

class Menu
{
private:
	List L;

public:

	void PressButton() const;
	void Print() const;
	void RandomSomeStuff();
	void AddToTail();
	void AddToHead();
	void AddbyIndex(); 
	void DeleteTail();
	void DeleteHead();
	void DeleteByIndex();
	void SearchByNumber();
};



