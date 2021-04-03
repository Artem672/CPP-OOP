#include "Train.h"

Train::Train(int Number, string Name, string DeparturePlace, string ArrivalPlace)
{
	this->Number = Number;
	this->Name = Name;
	this->DeparturePlace = DeparturePlace;
	this->ArrivalPlace = ArrivalPlace;

	for (int i = 0; i < rand() % 5 + 1; i++)
	{
		int TypeRandom = rand() % 3;
		int SittingNumber = rand() % 20 + 1;
		TrainVagons.push_back(Vagon(TypeArray[TypeRandom], SittingNumber));
	}
}

void Train::Print()
{
	cout << "Number: " << this->Number << endl
		<< "Name: " << this->Name << endl
		<< "Place of departure: " << this->DeparturePlace << endl
		<< "Place of arrival: " << this->ArrivalPlace << endl << endl;
}

void Train::PrintDetailInfo()
{
	cout << "Number: " << this->Number << endl
		<< "Name: " << this->Name << endl
		<< "Place of departure: " << this->DeparturePlace << endl
		<< "Place of arrival: " << this->ArrivalPlace << endl
		<< "All vagons numer: " << TrainVagons.size() << endl
		<< "All sitting number: " << this->GetAllSittingNumber() << endl;
	cout << "----Vagons----" << endl;
	for (int i = 0; i < TrainVagons.size(); i++)
	{
		cout << "Type: " << TrainVagons[i].GetType() << endl
			<< "Sitting number: " << TrainVagons[i].GetSittingNumber() << endl << endl;		
	}

}

int Train::GetNumber()
{
	return this->Number;
}

int Train::GetAllSittingNumber()
{
	int AllSittingNumber = 0;
	for (int i = 0; i < TrainVagons.size(); i++)
	{
		AllSittingNumber += TrainVagons[i].GetSittingNumber();
	}
	return AllSittingNumber;
}
