#include <iostream>
#include <ctime>

using namespace std;

template<typename T>

class CShop
{
private:

	T* Arr; int Count;


public:

	CShop()
	{
		this - Count = 0;
		this->Arr = nullptr;
	}

	~CShop()
	{
		delete[] this->Arr;
	}

	CShop(int Count)
	{
		this->Count = Count;
		this->Arr = new T[this->Count];
	}

	void FindMax()
	{
		T Max = this->Arr[0];

		for (int i = 1; i < this->Count; i++)
		{
			if (this->Arr[i].GetPrice() > Max.GetPrice())
			{
				Max = this->Arr[i];
			}
		}

		cout << "Item with the biggest price: " << endl;

		Max.PrintInfo();
	}

	void OutputNewElements()
	{
		cout << "New elements: " << endl << endl;
		T* TempItem;
		for (int i = 0; i < this->Count; i++)
		{
			//TempItem = this->Arr[i];
			if (this->Arr[i].GetStatus())
			{
				this->Arr[i].PrintInfo();
			}
		}
	}

	void OutputInfo()
	{
		for (int i = 0; i < this->Count; i++)
		{
			this->Arr[i].PrintInfo();
		}
	}

	void FindMin()
	{
		T Min = this->Arr[0];

		for (int i = 1; i < this->Count; i++)
		{
			if (this->Arr[i].GetPrice() < Min.GetPrice())
			{
				Min = this->Arr[i];
			}
		}

		cout << "Item with minimum price: " << endl;

		Min.PrintInfo();
	}

	void AveragePrice()
	{
		double AvP = 0;

		for (int i = 0; i < this->Count; i++)
		{
			AvP += this->Arr[i].GetPrice();
		}

		cout << "Arithmetic mean: " << AvP / this->Count << endl;
	}

	void SortByRisingPrice()
	{
		for (int i = 0; i < this->Count - 1; i++)
		{
			for (int j = 0; j < this->Count - i - 1; j++)
			{
				if (this->Arr[j].GetPrice() > this->Arr[j + 1].GetPrice())
				{
					swap(this->Arr[j], this->Arr[j + 1]);
				}
			}
		}
	}

	void SortByFallingPrice()
	{
		for (int i = 0; i < this->Count - 1; i++)
		{
			for (int j = 0; j < this->Count - i - 1; j++)
			{
				if (this->Arr[j].GetPrice() < this->Arr[j + 1].GetPrice())
				{
					swap(this->Arr[j], this->Arr[j + 1]);
				}
			}
		}
	}

	void SetFalseStatus()
	{
		for (int i = 0; i < this->Count - 1; i++)
		{
			this->Arr[i].SetStatus(0);
		}
	}

	T* GetArray()
	{
		return this->Arr;
	}

	void AddNewElement(T& Element)
	{
		T* TempArr = new T[this->Count + 1];

		this->SetFalseStatus();

		for (int i = 0; i < this->Count; i++)
		{
			TempArr[i] = this->Arr[i];
		}

		TempArr[this->Count] = Element;
		TempArr[this->Count].SetStatus(1);

		delete[] this->Arr;

		this->Arr = TempArr;
	}
};


/*void CreateDefoultLibs(CShop<Book> &book, CShop<Megazine> &megazine, CShop<Audio> &audio)
{
	book.GetMas()[0] = *(new Book("Dune", "Sandora", "Frenk Garbert", 132.0));
	book.AddNew(*(new Book("Harry Potter", "Sandora", "Joanne Rowling", 99.99)));
	megazine.GetMas()[0] = *(new Megazine("Fishing", 2.10));
	megazine.AddNew(*(new Megazine("PlayBoy ", 5.99)));
	audio.GetMas()[0] = *(new Audio("Splin", "New Human", 11, 72.0));
	audio.AddNew(*(new Audio("NANSI & SIDOROV", "Kaver", 15, 59.90)));}
*/


class Book
{
private:
	string Name;
	string Edition;
	string Author;
	int Price;
	bool Status;
public:

	Book* Books;

	Book() {};

	Book(string Name, string Edition, string Author, int Price, bool Status)
	{
		this->Name = Name;
		this->Edition = Edition;
		this->Author = Author;
		this->Price = Price;
		this->Status = Status;
	}

	void PrintInfo()
	{
		cout << "Name: " << this->Name << endl
			<< "Edition: " << this->Edition << endl
			<< "Author: " << this->Author << endl
			<< "Price: " << this->Price << endl
			<< "Status: " << this->Status << endl;
	}

	int GetPrice()
	{
		return this->Price;
	}

	void SetStatus(bool Status)
	{
		this->Status = Status;
	}

	bool GetStatus()
	{
		return this->Status;
	}
};

class Magazine
{
private:
	string Name;
	int Price;
	bool Status;
public:
	Magazine() {};

	bool GetStatus()
	{
		return this->Status;
	}

	Magazine(string Name, int Price, bool Status)
	{
		this->Name = Name;
		this->Price = Price;
		this->Status = Status;
	}

	void PrintInfo()
	{
		cout << "Name: " << this->Name << endl
			<< "Price: " << this->Price << endl
			<< "Status: " << this->Status << endl;
	}

	int GetPrice()
	{
		return this->Price;
	}

	void SetStatus(bool Status)
	{
		this->Status = Status;
	}
};

class Audio
{
private:
	string Name;
	string Performer;
	int TrackNumber;
	int Price;
	bool Status;
public:

	Audio() {};

	bool GetStatus()
	{
		return this->Status;
	}

	Audio(string Name, string Performer, int TrackNumber, int Price, bool Status)
	{
		this->Name = Name;
		this->Performer = Performer;
		this->TrackNumber = TrackNumber;
		this->Price = Price;
		this->Status = Status;
	}

	void PrintInfo()
	{
		cout << "Name: " << this->Name << endl
			<< "Performer: " << this->Performer << endl
			<< "Number of tracks: " << this->TrackNumber << endl
			<< "Price: " << this->Price << endl
			<< "Status: " << this->Status << endl;
	}

	int GetPrice()
	{
		return this->Price;
	}

	void SetStatus(bool Status)
	{
		this->Status = Status;
	}
};

void InputSomeInfo(CShop<Book>& book, CShop<Magazine>& magazine, CShop<Audio>& audio)
{
	string Names[] = { "Potter", "Veil","Gliph","Phenix", "Carl", "Mozgi","Wow" };

	int randName = rand() % 7;
	int randInfo = rand() % 7;
	int randPrice = rand() % 1000 + 1;
	int randStatus = rand() % 2;

	for (int i = 0; i < 2; i++)
	{
		book.GetArray()[i] = *(new Book(Names[randName], Names[randInfo], Names[randName], randPrice, randStatus));
		randName = rand() % 7;
		randInfo = rand() % 7;
		randPrice = rand() % 1000 + 1;
		randStatus = rand() % 2;
		magazine.GetArray()[i] = *(new Magazine("Gliph", randPrice, randStatus));
		randName = rand() % 7;
		randInfo = rand() % 7;
		randPrice = rand() % 1000 + 1;
		randStatus = rand() % 2;
		audio.GetArray()[i] = *(new Audio("Gliph", "Mozgi", 15, randPrice, randStatus));
		randName = rand() % 7;
		randInfo = rand() % 7;
		randPrice = rand() % 1000 + 1;
		randStatus = rand() % 2;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int BookCounter = 2, AudioCounter = 2, MagazineCounter = 2;
	int Choice;

	CShop<Book> book(BookCounter);
	CShop<Audio> audio(AudioCounter);
	CShop<Magazine> magazine(MagazineCounter);

	InputSomeInfo(book, magazine, audio);

	while (true)
	{
		cout << "0. Exit" << endl
			<< "1. Output information about all elements" << endl
			<< "2. Output information about the most expensive element" << endl
			<< "3. Output information about the cheapest element" << endl
			<< "4. Output arithmetic mean" << endl
			<< "5. Output information about new elements" << endl
			<< "Your choice: ";
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
			int Key;
			cout << "About: \n1.Book\n2.Magazine\n3.Audio\nYour choice-> ";
			cin >> Key;
			system("cls");
			if (Key == 1)
			{
				book.OutputInfo();
			}
			else if (Key == 2)
			{
				magazine.OutputInfo();
			}
			else if (Key == 3)
			{
				audio.OutputInfo();
			}
			else
			{
				cout << "Invalid code!" << endl;
			}

			system("PAUSE");
			system("cls");
			break;
		}
		case 2:
		{
			system("cls");
			int Key;
			cout << "About: \n1.Book\n2.Magazine\n3.Audio\nYour choice-> ";
			cin >> Key;
			system("cls");
			if (Key == 1)
			{
				book.FindMax();
			}
			else if (Key == 2)
			{
				magazine.FindMax();
			}
			else if (Key == 3)
			{
				audio.FindMax();
			}
			else
			{
				cout << "Invalid code!" << endl;
			}
			system("PAUSE");
			system("cls");
			break;
		}	
		case 3:
		{
			system("cls");
			int Key;
			cout << "About: \n1.Book\n2.Magazine\n3.Audio\nYour choice-> ";
			cin >> Key;
			system("cls");
			if (Key == 1)
			{
				book.FindMin();
			}
			else if (Key == 2)
			{
				magazine.FindMin();
			}
			else if (Key == 3)
			{
				audio.FindMin();
			}
			else
			{
				cout << "Invalid code!" << endl;
			}
			system("PAUSE");
			system("cls");
			break;
		}
		case 4:
		{
			system("cls");
			int Key;
			cout << "About: \n1.Book\n2.Magazine\n3.Audio\nYour choice-> ";
			cin >> Key;
			system("cls");
			if (Key == 1)
			{
				book.AveragePrice();
			}
			else if (Key == 2)
			{
				magazine.AveragePrice();
			}
			else if (Key == 3)
			{
				audio.AveragePrice();
			}
			else
			{
				cout << "Invalid code!" << endl;
			}
			system("PAUSE");
			system("cls");
			break;
		}
		case 5:
		{
			system("cls");
			int Key;
			cout << "About: \n1.Book\n2.Magazine\n3.Audio\nYour choice-> ";
			cin >> Key;
			system("cls");
			if (Key == 1)
			{
				book.OutputNewElements();
			}
			else if (Key == 2)
			{
				magazine.OutputNewElements();
			}
			else if (Key == 3)
			{
				audio.OutputNewElements();
			}
			else
			{
				cout << "Invalid code!" << endl;
			}
			system("PAUSE");
			system("cls");
			break;
		}
		default:
			system("cls");
			cout << "Invalid code!" << endl;
			system("PAUSE");
			system("cls");
			break;
		}
	}


	return 0;
}