#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

void ReadData(map<string, string>& Country)
{
	ifstream Read("Data.txt");
	string Id, Value;
	if (Read.is_open())
	{
		while (Read.good())
		{
			Read >> Id;
			Read >> Value;
			Country.emplace(Id, Value);
		}
	}

	Read.close();
}

void OutputMap(map<string, string> Country)
{
	cout << "The map: " << endl;
	for (auto i = Country.begin(); i != Country.end(); i++)
	{
		cout << "[" << i->first << "]: " << i->second << endl;
	}
}

void UploadFile(map<string, string> Country)
{
	ofstream Upload("Data.txt");

	Upload.clear();

	for (auto i = Country.begin(); i != Country.end(); i++)
	{
		Upload << i->first << " " << i->second << endl;
	}

	Upload.close();
}

void SearchByCountry(map<string, string> Country)
{
	string Id;
	cout << "Enter id -> ";
	cin >> Id;

	try {
		Country.find(Id);
	}
	catch (const std::exception& ex) {
		cout << ex.what() << endl;
	}

	cout << Id << " : " << Country[Id] << endl;
}

void ChangeCityName(map<string, string>& Country)
{
	string CountryKey, CityName;
	cout << "Enter Country key-> ";
	cin >> CountryKey;
	cout << "Enter new city name-> ";
	cin >> CityName;	
	
	try 
	{
		Country.at(CountryKey) = CityName;
	}
	catch (const std::exception& ex) {
		cout << ex.what() << endl;
	}
}

void AddCountry(map<string, string>& Country)
{
	string CountryKey, CityName;
	cout << "Enter Country key-> ";
	cin >> CountryKey;
	cout << "Enter city name-> ";
	cin >> CityName;

	Country.emplace(CountryKey, CityName);
}

void DeleteCountry(map<string, string>& Country)
{
	string CountryKey;

	cout << "Enter country key to delete -> ";
	cin >> CountryKey;

	try
	{
		Country.erase(CountryKey);
	}
	catch (const std::exception& ex) {
		cout << ex.what() << endl;
	}
}

int main()
{
	map<string, string> Country;

	ReadData(Country);
	bool Process = true;

	while (Process)
	{
		int choice = 0;
		system("cls");
		cout << "0. Exit" << endl
			<< "1. Output the map" << endl
			<< "2. Output city by Country id" << endl
			<< "3. Change city name" << endl
			<< "4. Add country" << endl
			<< "5. Delete country" << endl;
		cout << "Your choice-> ";
		cin >> choice;

		switch (choice)
		{
		case 0:
			Process = false;
			break;
		case 1:
			system("cls");
			OutputMap(Country);
			system("pause");
			break;
		case 2:
			system("cls");
			SearchByCountry(Country);
			system("pause");
			break;
		case 3:
			system("cls");
			ChangeCityName(Country);
			system("pause");
			break;
		case 4:
			system("cls");
			AddCountry(Country);
			system("pause");
			break;
		case 5:
			system("cls");
			DeleteCountry(Country);
			system("pause");
			break;
		default:
			system("cls");
			cout << "Invalid code!" << endl;
		}
	}
	
	UploadFile(Country);

}



