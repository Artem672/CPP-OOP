#include <iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;
class Book
{
private:
	int Number;
	string Author;
	string BookName;
	int Year;
	bool IsPresent = true;
public:
	Book();

	Book(int Number, string Author, string BookName, int Year)
	{
		this->Number = Number;
		this->Author = Author;
		this->BookName = BookName;
		this->Year = Year;
	}
	void ShowBooks()
	{

		cout << "Id:  " << this->Number << endl
			<< "Name: " << this->BookName << endl
			<< "Author: " << this->Author << endl
			<< "Year: " << this->Year << endl
			<< "Present: ";
		if (this->IsPresent == true)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
		cout << endl;
	}

	bool GetPresent()
	{
		return this->IsPresent;
	}

	string GetAuthor()
	{
		return this->Author;
	}
	string GetBookName()
	{
		return this->BookName;
	}

	void SetPresent(bool IsPresent)
	{
		this->IsPresent = IsPresent;
	}

	int GetNumber()
	{
		return this->Number;
	}
	
};
class Library
{
public:
	void SortList(list<Book>& book)
	{
		//sort(book.begin()->GetAuthor(), book.end()->GetAuthor(), [](string a, string b) {return a < b; });
	}
	void AddBook(list<Book>& book)
	{
		string Author;
		string Name;
		int Year;
		cin.ignore();
		cout << "Enter the author of the book-> ";
		getline(cin, Author);
		cout << "Enter the name of the book-> ";
		getline(cin, Name);
		cout << "Enter the year of the book-> ";
		cin >> Year;
		book.push_back(Book(book.size(), Author, Name, Year));
	}

	void ShowAllTheList(list<Book> book) const
	{
		if (!book.empty())
		{
			cout << endl;
			for (auto i = book.begin(); i != book.end(); ++i)
			{
				i->ShowBooks();
			}
		}
		else
		{
			cout << "Empty" << endl;
		}
	}

	void ShowRentBooks(list<Book> book)
	{
		if (!book.empty())
		{
			bool EmptyList = false;
			cout << endl;
			for (auto i = book.begin(); i != book.end(); ++i)
			{
				if (i->GetPresent() == false)
				{
					EmptyList = true;
					i->ShowBooks();
				}
			}

			if (!EmptyList)
			{
				cout << "Empty" << endl;
			}

		}
		else
		{
			cout << "Empty" << endl;
		}
	}
	void RentBook(list<Book>& book)
	{
		string Author;
		string Name;
		bool was_find = false;
		if (!book.empty())
		{
			cin.ignore();
			cout << "Enter the author of the book-> ";
			getline(cin, Author);
			cout << "Enter the name of the book-> ";
			getline(cin, Name);
			for (auto i = book.begin(); i != book.end(); ++i)
			{
				if (i->GetAuthor() == Author && i->GetBookName() == Name)
				{
					system("cls");
					cout << "The book was found! Now it`s in rent!" << endl;
					i->SetPresent(false);
					was_find = true;
				}
			}

			if (!was_find)
			{
				system("cls");
				cout << "Can`t find the book!" << endl;
			}
		}
		else
		{
			cout << "List is empty!" << endl;
		}
	}

	void FindBook(list<Book> book)
	{
		string Author;
		string Name;
		bool was_find = false;
		
		if (!book.empty())
		{
			cin.ignore();
			cout << "Enter the author of the book-> ";
			getline(cin, Author);
			cout << "Enter the name of the book-> ";
			getline(cin, Name);
			system("cls");
			cout << "Result: " << endl;
			for (auto i = book.begin(); i != book.end(); ++i)
			{
				if (i->GetAuthor() == Author && i->GetBookName() == Name)
				{
					i->ShowBooks();
					was_find = true;
				}
			}

			if (!was_find)
			{
				system("cls");
				cout << "Can`t find the book!" << endl;
			}
		}
		else
		{
			cout << "List is empty!" << endl;
		}
	}


	void FindBooksByTheAuthor(list<Book> book)
	{
		string Author;
		bool was_find = false;

		if (!book.empty())
		{
			cin.ignore();
			cout << "Enter the author of the book-> ";
			getline(cin, Author);
			system("cls");
			cout << "Result: " << endl;
			for (auto i = book.begin(); i != book.end(); ++i)
			{
				if (i->GetAuthor() == Author)
				{
					i->ShowBooks();
					was_find = true;
				}
			}

			if (!was_find)
			{
				system("cls");
				cout << "Can`t find the book!" << endl;
			}
		}
		else
		{
			cout << "List is empty!" << endl;
		}
	}

	void GetBookOutRent(list<Book>& book)
	{
		if (!book.empty())
		{
			int Number;
			cout << "Books in the rent: ";
			ShowRentBooks(book);
			cout << endl << "Enter number of the book to get out of rent-> ";
			cin >> Number;

			auto f = book.begin();
			
			try
			{
				for (int i = 0; i < Number; i++)
				{
					f++;
				}

				f->SetPresent(true);
				system("cls");
				cout << "The book was handed out!" << endl;
			}
			catch (const std::exception& ex) {
				cout << ex.what() << endl;
			}

		}
		else
		{
			cout << "List is empty!" << endl;
		}
		
	}
};

int main()
{
	list<Book> BookList;
	Library L;
	while (true)
	{
		int choice;
		cout << "0. Exit" << endl
			<< "1. Add book" << endl
			<< "2. Find book" << endl
			<< "3. Rent a book" << endl
			<< "4. Print the list" << endl
			<< "5. Print list with book in rent" << endl
			<< "6. Edit the book" << endl
			<< "7. Find books by the author " << endl
			<< "8. Get book out of rent" << endl
			<< "Your choice-> ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			exit(0);
			break;
		case 1:
		{
			system("cls");
			L.AddBook(BookList);
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			system("cls");
			L.FindBook(BookList);
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			system("cls");
			L.RentBook(BookList);
			system("pause");
			system("cls");
			break;
		}
		case 4:
		{
			system("cls");
			cout << "The list: ";
			//L.SortList(BookList);
			L.ShowAllTheList(BookList);
			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			system("cls");
			cout << "Books in the rent: ";
			L.ShowRentBooks(BookList);
			system("pause");
			system("cls");
			break;
		}
		case 6:
		{
			
		}
		case 7:
		{
			system("cls");
			L.FindBooksByTheAuthor(BookList);
			system("pause");
			system("cls");
			break;
		}
		case 8:
		{
			system("cls");
			L.GetBookOutRent(BookList);
			system("pause");
			system("cls");
			break;
		}
		default:
		{
			system("cls");
			cout << "Invalid code!" << endl;
			system("pause");
			system("cls");
			break;
		}
		}
	}
}