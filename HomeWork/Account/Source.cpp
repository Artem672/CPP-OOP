#include <iostream>
#include <string>
#include <cstddef>
#include <random>
#include <Windows.h>

using namespace std;

class Account
{
private:
	string PinCode;
	string Currency;
	string CardNumber;
	long double Balance = 0;
	bool CorrectPinCode = false;
public:

	void SetPinCode(string PinCode)
	{
		this->PinCode = PinCode;
	}

	string GetPinCode()
	{
		return PinCode;
	}

	long double GetBalance()
	{
		return Balance;
	}

	void SetBalance(long double Balance)
	{
		if (Balance >= 0)
		{
			this->Balance += Balance;
		}
		else
		{
			cout << "Invalid number!" << endl;
		}
	}

	void SetCardNumber(string CardNumber)
	{
		this->CardNumber = CardNumber;
	}

	string GetCardNumber()
	{
		return CardNumber;
	}

	void SetCurrency(string Currency)
	{
		this->Currency = Currency;
	}

	void OutPutBalance()
	{
		cout << endl << "Credit card number: " << CardNumber << endl
			<< "Credit card balance: " << Balance << Currency << endl << endl;
	}

	void WithdrawMoney(int Balance)
	{
		if (Balance <= this->Balance && Balance >= 0)
		{
			this->Balance -= Balance;
		}
		else if(Balance >= this->Balance)
		{
			cout << endl << "Not enough money!" << endl;
		}
		else if (Balance < 0)
		{
			cout << endl << "Invalid number!" << endl;
		}
	}

	void SetCorrectPinCode(bool CorrectPinCode)
	{
		this->CorrectPinCode = CorrectPinCode;
	}

	bool GetCorrectPinCode()
	{
		return CorrectPinCode;
	}
};

int main()
{
	mt19937 gen{ std::random_device()() };
	uniform_int_distribution<uint64_t> dist(00000000, 99999999);
	uniform_int_distribution<uint64_t> gist(1000, 9999);
	Account Person;
	int Try_Number = 0;
	Person.SetCardNumber(to_string(dist(gen)));
	Person.SetPinCode(to_string(gist(gen)));
	
	cout << "Welcome!Your pincode is: " << Person.GetPinCode() << " .Remember it!" << endl; Sleep(5000);
	system("cls");
	/*В завданні не було вказано як саме повинен отримуватися пін-код, тому я зробив, щоб код рандомився і користувач його запам'ятав, а потів ввів*/
	/*Якщо щось не так, напишіть , перероблю*/
	while (Try_Number != 3)
	{
		string pincode, currency;
		cout << "Enter pin-code-> ";
		cin >> pincode;
		
		if (pincode == Person.GetPinCode())
		{
			cout << endl << "You are log in!" << endl; Sleep(1000);
			cout << "Enter currency-> "; cin >> currency;
			Person.SetCurrency(currency);
			Person.SetCorrectPinCode(true);
			system("cls");
			break;
		}
		else
		{
			Try_Number++;
			if (Try_Number == 3)
			{
				cout << endl << "You lost all your tries! Try next time! Bye!" << endl;
				break;
			}
			system("cls");
			cout << "You have " << 3 - Try_Number << " more tries!" << endl;
		}
	}


	while (Person.GetCorrectPinCode())
	{
		int choice = 0;
		cout << "1. Withdraw money" << endl
			<< "2. Enroll money" << endl
			<< "3. Output balance" << endl
			<< "0. Exit" << endl << endl 
			<< "Your choice-> ";
		cin >> choice;

		switch (choice)
		{
		case 0:
		{
			Person.SetCorrectPinCode(false);
			break;
		}
		case 1:
		{
			int Cash = 0;
			cout << endl << "Input value of cash to withdraw-> ";
			cin >> Cash;
			Person.WithdrawMoney(Cash);
			cout << endl;
			break;
		}
		case 2:
		{
			int Cash = 0;
			cout << endl << "Input value of cash-> ";
			cin >> Cash;
			Person.SetBalance(Cash);
			cout << endl;
			break;
		}
		case 3:
		{
			Person.OutPutBalance();
			break;
		}
		default:
		{
			cout << "Invalid code!" << endl;
			break;
		}
		}
	}

}