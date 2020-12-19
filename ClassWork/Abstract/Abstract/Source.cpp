#include <iostream>
#include <string>
#include <windows.h>
#include <ctime>

using namespace std;

class House
{
private:

	class Room
	{
	private:
		double Width;
		double Heigth;
		unsigned int Floor;
	public:

		Room(double Width, double Heigth, unsigned int Floor)
		{
			this->Width = Width;
			this->Heigth = Heigth;
			this->Floor = Floor;
		}

		double GetRoomSquare()
		{
			return (Width * Heigth);
		}

		void SetWidth(double Width)
		{
			this->Width = Width;
		}

		void SetHeigth(double Heigth)
		{
			this->Heigth = Heigth;
		}

		void SetFloor(unsigned int Floor)
		{
			this->Floor = Floor;
		}

		double GetWidth()
		{
			return Width;
		}

		double GetHeigth()
		{
			return Heigth;
		}

		unsigned int GetFloor()
		{
			return Floor;
		}

		void RoomInfo()
		{
			cout << "Width: " << this->Width << endl;
			cout << "Heigth: " << this->Heigth << endl;
			cout << "Floor: " << this->Floor << endl;
		}

		void InputRoomInfo()
		{
			cout << "Enter width -> "; cin >> this->Width;
			cout << "Enter heigth -> "; cin >> this->Heigth;
			cout << "Enter floor -> "; cin >> this->Floor;
		}

		Room()
		{
			void InputRoomInfo();
		}
	};

public:
	int RoomNumber = 0;
	Room Kitchen;
	Room* Rooms;
	int FloorNumber = 0;

	House()
	{
		while (this->FloorNumber <= 0 || this->RoomNumber <= 0)
		{

			cout << "Enter number of floors-> ";
			cin >> this->FloorNumber;
			cout << "Enter number of rooms-> ";
			cin >> this->RoomNumber;

			if (this->FloorNumber <= 0 || this->RoomNumber <= 0)
			{
				cout << "\nSomething wrong! Try one more time!" << endl << endl;
			}
			else if (this->FloorNumber > 0 && this->RoomNumber > 0)
			{
				this->Rooms = new Room[this->RoomNumber];
				cout << "\nData were entered correctly!" << endl;
			}
		}
	}

	~House()
	{
		delete[] this->Rooms;
	}

	int TotalRoomSquare()
	{
		int RoomSquare = 0;

		for (auto i = 0; i < this->RoomNumber; i++)
		{
			RoomSquare += this->Rooms[i].GetRoomSquare();
		}

		return RoomSquare;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned)time(NULL));

	House house;
	int Menu = 0;

	while (true)
	{
		cout << endl << "~~Your functions~~" << endl
			<< "0. Exit " << endl
			<< "1. Information about house rooms" << endl
			<< "2. Output total room square" << endl
			<< "3. Output total room square by floor" << endl
			<< "4. Change room properties" << endl
			<< "5. Change kitchen properties" << endl
			<< "6. Output information about rooms on the floor" << endl
			<< "Your choice-> ";
		cin >> Menu;

		switch (Menu)
		{
		case 0:
		{
			exit(0);
			break;
		}
		case 1:
		{
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			break;
		}
		case 6:
		{
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