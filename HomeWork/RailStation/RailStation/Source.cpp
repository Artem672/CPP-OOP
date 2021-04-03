#include "Train.h"

int main()
{
	
	vector<Train> Station;

	int Key;
	bool Process = true;
	while (Process)
	{
		system("cls");
		cout << "0. Exit" << endl
			<< "1. Add data" << endl
			<< "2. Print info about all trains" << endl
			<< "3. Print info about entered train" << endl
			<< "Your choice-> ";
		cin >> Key;

		switch (Key)
		{
		case 0:
			Process = false;
			break;
		case 1:
		{
			system("cls");
			int number;
			string name, departurePlace, arrivalPlace;
			cout << "Enter train number: ";
			cin >> number;
			cout << "Enter train name: ";
			cin >> name;
			cout << "Enter train departure place: ";
			cin >> departurePlace;
			cout << "Enter train arrival place: ";
			cin >> arrivalPlace;
			Station.push_back(Train(number, name, departurePlace, arrivalPlace));
			system("pause");
			break;
		}			
		case 2:
		{
			system("cls");
			if (!Station.empty())
			{
				for (int i = 0; i < Station.size(); i++)
				{
					Station[i].Print();
				}
			}
			else
			{
				cout << "Empty!" << endl;
			}
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			if (!Station.empty())
			{
				int TrainNumber;
				cout << "Train numbers:" << endl;
				for (int i = 0; i < Station.size(); i++)
				{					
					cout << "\t" << Station[i].GetNumber() << endl;
				}
				cout << "Enter train number: ";
				cin >> TrainNumber;

				system("cls");
				for (int i = 0; i < Station.size(); i++)
				{
					if (TrainNumber == Station[i].GetNumber())
					{
						Station[i].PrintDetailInfo();
					}
				}			
			}
			else
			{
				cout << "Empty!" << endl;
			}
			system("pause");
			break;
		}
		default:
			system("cls");
			cout << "Invalid code!" << endl;
			system("pause");
			break;
		}
	}
}