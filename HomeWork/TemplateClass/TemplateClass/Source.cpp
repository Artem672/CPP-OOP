#include <iostream>

using namespace std;

template<typename b, typename m, typename a>

class CShop
{
private:
	b book;
	m magazine;
	a audio;
public:

	CShop(b book, m magazine, a audio)
	{
		this->book = book;
		this->magazine = magazine;
		this->audio = audio;
	}

};

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

};

class Magazine
{
private:
	string Name;
	int Price;
	bool Status;
public:
	Magazine() {};

	Magazine(string Name, int Price, bool Status)
	{
		this->Name = Name;
		this->Price = Price;
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

	Audio(string Name, string Performer, int TrackNumber, int Price, bool Status)
	{
		this->Name = Name;
		this->Performer = Performer;
		this->TrackNumber = TrackNumber;
		this->Price = Price;
		this->Status = Status;
	}
};

int main()
{

}