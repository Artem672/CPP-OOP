#include "Menu.h"

void Menu::PressButton() const
{
	cout << endl << "Press 'q' to return into menu!" << endl;
	while (!_kbhit());
	if (_getch() == 81);
	system("cls");
}

void Menu::Print() const
{
	system("cls");
	this->L.Print();
	this->PressButton();
}

void Menu::RandomSomeStuff()
{
	int Amount = rand() % 4 + 2;

	for (int i = 0; i < Amount; i++)
	{
		int Number = rand() % 10;
		this->L.AddTail(Number);
	}
}

void Menu::AddToTail()
{
	system("cls");
	int Number = 0;
	cout << "Enter number to add-> ";
	cin >> Number;

	this->L.AddTail(Number);
	this->PressButton();
}

void Menu::AddToHead()
{
	system("cls");
	int Number = 0;
	cout << "Enter number to add-> ";
	cin >> Number;

	this->L.AddToHead(Number);
	this->PressButton();
}

void Menu::AddbyIndex()
{
	int Index = 0, Value = 0;
	system("cls");

	cout << "Enter the index of number-> ";
	cin >> Index;
	cout << "Enter the number to add-> ";
	cin >> Value;

	system("cls");

	if (this->L.AddbyIndex(Index, Value) == true)
	{
		cout << "Number with index: " << Index << " was added!" << endl;
	}
	else if (this->L.AddbyIndex(Index, Value) == false)
	{
		cout << "Can`t add the number with index: " << Index << "!" << endl;
	}

	this->PressButton();
}

void Menu::DeleteTail()
{
	system("cls");

	if (this->L.DeleteTail() == true)
	{
		cout << "Tail was deleted!" << endl;
	}
	else if (this->L.DeleteTail() == false)
	{
		cout << "Can`t delete the tail!" << endl;
	}

	this->PressButton();
}

void Menu::DeleteHead()
{
	system("cls");
	if (this->L.DeleteHead() == true)
	{
		cout << "Head was deleted!" << endl;
	}
	else if (this->L.DeleteHead() == false)
	{
		cout << "Can`t delete the head!" << endl;
	}

	this->PressButton();
}

void Menu::DeleteByIndex()
{
	int Index = 0;
	system("cls");

	cout << "Enter the index of number-> ";
	cin >> Index;

	system("cls");

	if (this->L.DeleteByIndex(Index) == true)
	{
		cout << "Number with index: " << Index << " was deleted!" << endl;
	}
	else if (this->L.DeleteByIndex(Index) == false)
	{
		cout << "Can`t delete the number with index: " << Index << "!" << endl;
	}

	this->PressButton();
}

void Menu::SearchByNumber()
{
	system("cls");
	int Number = 0, Size = 0;

	cout << "Enter number (to find the index)-> ";
	cin >> Number;

	system("cls");

	int * Index = this->L.SearchByNumber(Number, Size);

	if (Size != 0)
	{
		cout << "The index of number " << Number << " is: ";
		for (int i = 0; i < Size; i++)
		{
			cout << Index[i] << "  ";
		}
	}
	else if (Size == 0)
	{
		cout << "Can`t find number: " << Number << endl;
	}

	this->PressButton();
}
