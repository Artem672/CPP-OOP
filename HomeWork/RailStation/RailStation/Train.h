#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Train
{
private:
	int Number;
	string Name;
	string DeparturePlace;
	string ArrivalPlace;
	string TypeArray[3] = { "Plackart","Coupe","Luxe" };

	class Vagon
	{
	private:
		string Type;
		int SittingNumber;
	public:

		Vagon(string Type, int SittingNumber)
		{
			this->SittingNumber = SittingNumber;
			this->Type = Type;
		}

		string GetType()
		{
			return this->Type;
		}

		int GetSittingNumber()
		{
			return this->SittingNumber;
		}

	};

	vector<Vagon> TrainVagons;

public:
	
	Train(int Number, string Name, string DeparturePlace, string ArrivalPlace);

	void Print();

	void PrintDetailInfo();

	int GetNumber();

	int GetAllSittingNumber();
};

