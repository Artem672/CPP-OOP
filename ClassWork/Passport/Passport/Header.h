#include <iostream>
#include <vector>
#include <string> 
#include <ctime>

using namespace std;

class Passport
{
private:
	string PIB;
	string SeriesNumber;

public:

	void AddPassport()
	{
		cin.ignore();
		cout << "Enter your PIB-> ";
		getline(cin, this->PIB);
		cout << "Enter your series and number-> ";
		getline(cin, this->SeriesNumber);
		
	}

	void ShowPassportInfo()
	{
		cout << "PIB: " << this->PIB << endl
			<< "Series and number: " << this->SeriesNumber << endl;
	}

	void EditPassportInfo()
	{
		cin.ignore();
		cout << "Enter new PIB-> ";
		getline(cin, this->PIB);
		cout << "Enter your new series and number-> ";
		getline(cin, this->SeriesNumber);
	}

};

class ForeignPassport : public Passport
{	
private:

	class Visa
	{
	private:
		size_t Id;
		string Country;
		string Date;
	public:

		Visa(size_t Id, string Country, string Date)
		{
			this->Id = Id;
			this->Country = Country;
			this->Date = Date;
		}

		void ShowVisaInfo()
		{		
			cout << "Id: " << this->Id << endl
				<< "Country: " << this->Country << endl
				<< "Date: " << this->Date << endl;
		}

	};

	vector<Visa> Visas;

	size_t Visa_Id = 0;
public:

	int Random(int min, int max) 
	{
		return min + rand() % (max - min);
	}

	void AddVisa()
	{
		int Year, Month, Day;
		string Country, Date;
		cin.ignore();
		cout << "Enter your country-> ";
		getline(cin, Country);
		Year = Random(2022, 2050);
		Month = Random(1, 12);
		Day = Random(1, 31);
		
		Date = to_string(Year) + "/" + to_string(Month) + "/" + to_string(Day);

		Visas.push_back(Visa(this->Visa_Id++, Country, Date));
		cout << "Visa was added!" << endl;
		
	}

	void ShowAllVisa()
	{
		cout << "All visas: " << endl;
		if (!Visas.empty())
		{
			
			for (int i = 0; i < Visas.size(); i++)
			{
				this->ShowPassportInfo();
				Visas[i].ShowVisaInfo();
				cout << endl;
			}

		}
		else
		{
			cout << "Empty!" << endl;
		}
		
	}

	void DeleteVisa()
	{
		int Delete_Id;

		ShowAllVisa();

		if (!Visas.empty())
		{
			cout << "Enter visa's Id-> ";
			cin >> Delete_Id;

			auto Iterator = Visas.begin() + Delete_Id;

			Visas.erase(Iterator);
		}
		
	}
};