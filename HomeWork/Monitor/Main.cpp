#include <iostream>

using namespace std;

class Monitor
{
private:
	unsigned int Resolution;
	unsigned int Price;
	unsigned int Brightness;
	double Diagonal;
public:

	Monitor();

	Monitor(unsigned int Resolution, unsigned int Price, unsigned int Brightness, double Diagonal)
	{
		this->Resolution = Resolution;
		this->Price = Price;
		this->Brightness = Brightness;
		this->Diagonal = Diagonal;
	}

	~Monitor()
	{
		cout << endl << "This is the end of Programm!" << endl;
	}

	void SetResolution(unsigned int Resolution)
	{
		this->Resolution = Resolution;
	}

	void SetPrice(unsigned int Price)
	{
		this->Price = Price;
	}

	void SetBrightness(unsigned int Brightness)
	{
		this->Brightness = Brightness;
	}

	void SetDiagonal(double Diagonal)
	{
		this->Diagonal = Diagonal;
	}

	unsigned int GetResolution()
	{
		return Resolution;
	}

	unsigned int GetPrice()
	{
		return Price;
	}

	unsigned int GetBrightness()
	{
		return Brightness;
	}

	double GetDiagonal()
	{
		return Diagonal;
	}

	void Print()
	{
		cout << "Monitor's reference" << endl
			<< "Resolution: " << Resolution << endl
			<< "Price: " << Price << endl
			<< "Brightness: " << Brightness << endl
			<< "Diagonal: " << Diagonal << endl;
	}
};

int main()
{
	Monitor HP(140,2000,340,500);

	HP.Print();

}