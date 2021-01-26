#include <iostream>
#include <vector>

using namespace std;

class Vagon
{
private:
	int Number;
	string Name;
	string Out;
	string To;

public:
	Vagon()
	{

	}

	Vagon(int Number, string Name, string Out, string To)
	{
		this->Number = Number;
		this->Name = Name;
		this->Out = Out;
		this->To = To;
	}

	void OutPut()
	{
		cout << "Number: " << this->Number << endl
			<< "Name: " << this->Name << endl
			<< "Out: " << this->Out << endl
			<< "To: " << this->To << endl;
	}
};


int main()
{
	vector<Vagon> Station;
	Vagon V;
	Station.push_back(Vagon(15,"153","45235","sdfs"));
	Station[0].OutPut();
	Station.push_back(Vagon(19, "1sdfvs", "45vwef235", "sdfvws"));
	Station[1].OutPut();
	//Station.push_back();
}