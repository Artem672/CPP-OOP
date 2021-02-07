#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Train
{
private:
	int Number;
	string Name;
	string DeparturePlace;
	string ArrivalPlace;
public:

	Train(int Number, string Name, string DeparturePlace, string ArrivalPlace);

	void Print();
};

