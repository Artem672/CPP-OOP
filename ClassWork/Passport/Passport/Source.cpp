#include "Header.h"

int main()
{
	ForeignPassport Bill;
	size_t Choice;
	

	while (true)
	{
		cout << "0. Exit" << endl
			<< "1. Add passport" << endl
			<< "2. Add visa" << endl
			<< "3. Delete visa" << endl
			<< "4. Show passports info" << endl
			<< "5. Show all visa's" << endl
			<< "6. Edit passport's info" << endl
			<< "Your choice-> ";
		cin >> Choice;

		switch (Choice)
		{
		case 0:
		{
			exit(0);
			break;
		}
		case 1:
		{
			system("cls");
			Bill.AddPassport();
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			system("cls");
			Bill.AddVisa();
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			system("cls");
			Bill.DeleteVisa();
			system("pause");
			system("cls");
			break;
		}
		case 4:
		{
			system("cls");
			cout << "Passport's info: " << endl;
			Bill.ShowPassportInfo();
			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			system("cls");
			Bill.ShowAllVisa();
			system("pause");
			system("cls");
			break;
		}
		case 6:
		{
			system("cls");
			Bill.EditPassportInfo();
			system("pause");
			system("cls");
			break;
		}
		}
			
	}
}