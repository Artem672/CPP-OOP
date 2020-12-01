#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>

using namespace std;

class DiscountCard 
{
private:
	unsigned long CardNumber;
	double Discount = 1;
	unsigned int Cash = 0;
	string CardDateTime;
public:

	DiscountCard(unsigned long CardNumber, double Discount, unsigned int Cash)
	{
		this->CardNumber = CardNumber;
		this->Discount = Discount;
		this->Cash = Cash;
	}
	/*
	void GenerateCard()
	{
		CardNumber = rand() % 99999999 + 10000000;
	}*/

	unsigned long GetCardNumber()
	{
		return CardNumber;
	}
	
	void SetCardDate(string CardDateTime)
	{
		this->CardDateTime = CardDateTime;
	}

	double GetDiscount()
	{
		return Discount;
	}

	void SetDiscount(double Discount)
	{
		this->Discount = Discount;
	}

	void SetCash(unsigned int Cash)
	{
		this->Cash += Cash;
	}

	unsigned int GetCash()
	{
		return Cash;
	}

	const string CardDate()
	{
		time_t now = time(0);
		struct tm tstruct;
		char buf[80];
		tstruct = *localtime(&now);
		strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

		return buf;
	}

	void PrintInfo()
	{
		cout << "Номер картки: " << CardNumber << endl;
		cout << "Ви витратили коштів: " << Cash << endl;
		cout << "Ваша знижка " << Discount << "%" << endl;
		cout << "До наступної знижки: " << 1000 - (Cash % 1000) << endl;
	}
};

int main()
{
	srand(unsigned(time(NULL)));
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	unsigned long CardNumber = rand() % 99999999 + 10000000;
	int choice;

	DiscountCard Disc(CardNumber, 1, 0);
	Disc.SetCardDate(Disc.CardDate());

	while (true)
	{
		if (Disc.GetCash() < 1000)
		{
			Disc.SetDiscount(1);
		}
		else if (Disc.GetCash() >= 1000)
		{
			Disc.SetDiscount(1 + (Disc.GetCash() / 1000));
		}

		cout << "1. Купівля товарів" << endl
			<< "2. Вивід інформації" << endl
			<< "0. Вихід" << endl
			<< "Ваш вибір : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			int Sum;
			cout << endl << "Введіть суму для покупки: "; cin >> Sum;
			cout << "У вас є знижка у розмірі " << Disc.GetDiscount() << "%, тому з вас :" << Sum - (Sum * (Disc.GetDiscount() / 10)) << endl;
			cout << "Дякуємо за покупку!" << endl;
			Disc.SetCash(Sum - (Sum * (Disc.GetDiscount() / 10)));
			cout << endl;
			break;
		}
		case 2:
		{
			cout << endl;
			Disc.PrintInfo();
			cout << endl;
			break;
		}
		case 0:
		{
			exit(0);
			break;
		}
		default:
		{
			cout << "Incorrect value!" << endl;
			cout << endl;
			break;
		}
		}
	}
	Disc.PrintInfo();
}