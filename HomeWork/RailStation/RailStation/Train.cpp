#include "Train.h"

Train::Train(int Number, string Name, string DeparturePlace, string ArrivalPlace)
{
	this->Number = Number;
	this->Name = Name;
	this->DeparturePlace = DeparturePlace;
	this->ArrivalPlace = ArrivalPlace;
}

void Train::Print()
{
	cout << "Number: " << this->Number << endl
		<< "Name: " << this->Name << endl
		<< "Place of departure: " << this->DeparturePlace << endl
		<< "Place of arrival: " << this->ArrivalPlace << endl;
}
