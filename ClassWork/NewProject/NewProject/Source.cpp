#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class Array
{
private:
	int Size;
	int* array;
public:

	void EnterData()
	{
		cout << "Enter size of the array: ";
		cin >> this->Size;	

		this->array = new int[this->Size];
	}

	void GetSave()
	{
		char Path[] = "array.txt";

		ifstream Read;
		Read.exceptions(ifstream::badbit | ifstream::failbit);

		try
		{
			this->ReadTheFile();
			if (this->Size <= 0)
			{
				this->EnterData();
			}
		}
		catch (const char* ex)
		{		
			cout << ex << endl;
			this->EnterData();
		}
	}

	Array()
	{
		this->GetSave();
	}

	~Array()
	{
		delete[] this->array;
	}

	void Fill()
	{
		for (int i = 0; i < this->Size; i++)
		{
			array[i] = rand() % 20;
		}

		cout << "Array was filled!" << endl;
	}

	void Print()
	{
		cout << "Array: ";
		for (int i = 0; i < this->Size; i++)
		{
			cout << array[i] << " ";
		}

		cout << endl;
	}

	void BubbleSort()
	{
		for (int i = 0; i < this->Size - 1; i++)
		{
			for (int j = 0; j < this->Size - i - 1; j++)
			{
				if (this->array[j] > this->array[j + 1])
				{
					swap(this->array[j], this->array[j + 1]);
				}
			}
		}

		cout << "Array was sorted!" << endl;
	}

	void MaxElement()
	{
		int Max = this->array[0];
		int SaveId = 0;

		for (int i = 0; i < this->Size; i++)
		{
			if (this->array[i] > Max)
			{
				Max = this->array[i];
				SaveId = i;
			}
		}

		cout << "Max element: " << Max << endl;
		cout << "It's id: " << SaveId << endl;
	}

	void AddNewElement(int Number)
	{
		int* tempArr = new int[this->Size + 1];

		for (int i = 0; i < this->Size; i++)
		{
			tempArr[i] = this->array[i];
		}

		tempArr[this->Size] = Number;
		
		delete[] this->array;

		this->array = tempArr;

		this->Size++;

		cout << "Element was added!" << endl;
	}

	void DeleteLastElement()
	{
		int* tempArr = new int[this->Size - 1];

		for (int i = 0; i < this->Size - 1; i++)
		{
			tempArr[i] = this->array[i];
		}

		delete[] this->array;

		this->array = tempArr;
		this->Size--;

		cout << "Element was deleted!" << endl;
	}

	void RecordArray()
	{
		ofstream Rec("array.txt");
		Rec.clear();

		Rec << this->Size << " ";

		for (int i = 0; i < this->Size; i++)
		{
			Rec << this->array[i] << " ";
		}

		Rec.close();

		cout << "Array was recorded!" << endl;
	}

	void ReadTheFile()
	{
		ifstream Read("array.txt");

		Read >> this->Size;

		this->array = new int[this->Size];

		int i = 0;
		if (Read.is_open())
		{
			while (i < this->Size)
			{
				Read >> this->array[i];
				i++;
			}
			Read.close();
		}
		else
		{
			throw("Couldn't read the file");
		}
	}
};




int main()
{
	srand((unsigned)time(NULL));
	int choice;

	Array Arr;

	while (true)
	{
		system("cls");
		cout << "0. Exit" << endl
			<< "1. Fill the array" << endl
			<< "2. Print" << endl
			<< "3. Add to the end" << endl
			<< "4. Delete from the end" << endl
			<< "5. Find max element and it's id" << endl
			<< "6. Sort array by rising" << endl
			<< "7. Record an array to the file" << endl
			<< "8. Read array out of file" << endl
			<< "Your choice-> ";
		cin >> choice;

		switch (choice)
		{
		case 0:
		{
			system("cls");
			exit(0);
			break;
		}
		case 1:
		{
			system("cls");
			Arr.Fill();
			system("PAUSE");
			system("cls");
			break;
		}
		case 2:
		{
			system("cls");
			Arr.Print();
			system("PAUSE");
			system("cls");
			break;
		}
		case 3:
		{
			system("cls");
			int Numb;
			cout << "Enter number to add: ";
			cin >> Numb;
			Arr.AddNewElement(Numb);
			system("PAUSE");
			system("cls");
			break;
		}
		case 4:
		{
			system("cls");
			Arr.DeleteLastElement();
			system("PAUSE");
			system("cls");
			break;
		}
		case 5:
		{
			system("cls");
			Arr.MaxElement();
			cout << endl;
			system("PAUSE");
			system("cls");
			break;
		}
		case 6:
		{
			system("cls");
			Arr.BubbleSort();
			cout << endl;
			system("PAUSE");
			system("cls");
			break;
		}
		case 7:
		{
			system("cls");
			Arr.RecordArray();
			system("PAUSE");
			system("cls");
			break;
		}
		case 8:
		{
			system("cls");
			Arr.ReadTheFile();
			system("PAUSE");
			system("cls");
			break;
		}
		default:
		{
			cout << "Invalid code!" << endl;
			break;
		}
		}
	}

	system("PAUSE");
	return 0;
}