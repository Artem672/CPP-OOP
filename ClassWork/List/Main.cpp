#include "Menu.h"

void main()
{
	Menu menu;

	srand((unsigned)time(NULL));

	menu.RandomSomeStuff(); 

	while (true)
	{
		int choice = 0;

		cout << "--------Functions------" << endl
			<< "0. Exit" << endl
			<< "1. Print the list" << endl
			<< "2. Add number to tail" << endl
			<< "3. Add number to head" << endl
			<< "4. Add number by index" << endl
			<< "5. Delete tail" << endl
			<< "6. Delete head" << endl
			<< "7. Delete by index" << endl
			<< "8. Search index by number" << endl
			<< "Your choice-> ";
		cin >> choice;

		switch (choice)
		{
		case 0:
		{
			exit(0);
			break;
		}
		case 1:
		{
			menu.Print();
			break;
		}
		case 2:
		{
			menu.AddToTail();
			break;
		}
		case 3:
		{
			menu.AddToHead();
			break;
		}
		case 4:
		{
			menu.AddbyIndex();
			break;
		}
		case 5:
		{
			menu.DeleteTail();
			break;
		}
		case 6:
		{
			menu.DeleteHead();
			break;
		}
		case 7:
		{
			menu.DeleteByIndex();
			break;
		}
		case 8:
		{
			menu.SearchByNumber();
			break;
		}
		default:
		{
			system("cls");
			cout << "Invalid code!" << endl;
			menu.PressButton();
		}
		}

	}

}