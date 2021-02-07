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
			system("cls");
			system("pause");
			break;
		case 2:
			system("cls");
			
			system("pause");
			break;
		default:
			system("cls");
			cout << "Invalid code!" << endl;
			system("pause");
			break;
		}
	}
}