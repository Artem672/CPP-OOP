#include <iostream>
#include <string>
#include <windows.h>
#include <ctime>
#include <conio.h>

using namespace std;

class House
{
private:

	class Room
	{
	private:
		int Id;
		double Width;
		double Heigth;
		int Floor;
	public:

		void SetId(int Id)
		{
			this->Id = Id;
		}

		int GetId()
		{
			return Id;
		}

		void InputRoom(double Width, double Heigth, int Floor, int Id)
		{
			this->Width = Width;
			this->Heigth = Heigth;
			this->Floor = Floor;
			this->Id = Id;
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

		void SetFloor(int Floor)
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

		int GetFloor()
		{
			return Floor;
		}

		void RoomInfo()
		{
			cout << "Room ¹" << this->Id + 1<< endl;
			cout << "Width: " << this->Width << endl;
			cout << "Heigth: " << this->Heigth << endl;
			cout << "Floor: " << this->Floor << endl << endl;
		}

	};

public:
	int RoomNumber = 0;
	Room Kitchen;
	Room* Rooms;
	int FloorNumber = 0;
	int* LevelSquare;

	void ShowRoomInfo()
	{
		for (int i = 0; i < this->RoomNumber; i++)
		{
			this->Rooms[i].RoomInfo();
		}
	}

	void EnterData()
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
				cout << "\nData were entered correctly!" << endl << endl;
			}
		}
		this->PressTheButton();
		//system("cls");
	}

	House()
	{
		this->EnterData();
		this->Rooms = new Room[this->RoomNumber];
		this->InputRoomData();
		this->PressTheButton();
		this->LevelSquare = new int[this->FloorNumber];
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

	void OutputTotalRoomsSquare()
	{
		cout << "There are " << this->RoomNumber << " rooms!" << endl;
		cout << "Total rooms square is: " << this->TotalRoomSquare() << endl;
	}

	void PressTheButton()
	{
		cout << "Press any button to continue!" << endl;
		while (!_kbhit());
		if (_getch() == 81);
		system("cls");
	}

	int LevelRoomSquare()
	{
		for (auto i = 0; i < this->FloorNumber; i++)
		{
			this->LevelSquare[i] = 0;
		}

		for (auto i = 0; i < this->RoomNumber; i++)
		{
			this->LevelSquare[this->Rooms[i].GetFloor() - 1] += this->Rooms[i].GetRoomSquare();
		}

		return 0;
	}

	void OutputLevelSquare()
	{
		this->LevelRoomSquare();
		for (auto i = 0; i < this->FloorNumber; i++)
		{
			cout << "Floor ¹" << i + 1 << endl;
			cout << "Floor square: " << this->LevelSquare[i] << endl << endl;
		}
	}

	void InputRoomData()
	{
		double heigth = 0, width = 0;
		int floor = 0;
		for (auto i = 0; i < this->RoomNumber; i++)
		{
			cout << "Info about " << i + 1 << " room!" << endl;
			cout << "Enter the width of the room : ";
			cin >> width;
			cout << "Enter the heigth of the room : ";
			cin >> heigth;
			cout << "Enter the floor of the room (max " << this->FloorNumber << "): ";
			cin >> floor;

			if (heigth < 0 || width < 0 || (floor > this->FloorNumber || floor <= 0))
			{
				cout << "\nSomething wrong! Try one more time!" << endl << endl;
				i--;
			}
			else if (heigth > 0 && width > 0 && (floor > 0 && floor <= this->FloorNumber))
			{
				cout << "Room " << i + 1 << " was added!" << endl;
				this->Rooms[i].InputRoom(width, heigth, floor, i);
			}
			cout << endl;
		}
		cout << endl;
	}

	void ChangeRoomProperties()
	{
		int _id; bool findRoom = false;
		cout << "Enter number of the room: ";
		cin >> _id;

		for (auto i = 0; i < this->RoomNumber; i++)
		{
			if (this->Rooms[i].GetId() == _id - 1)
			{
				findRoom = true;
				double _width = 0, _heigth = 0;
				
				while (_width <= 0 || _heigth <= 0)
				{
					cout << "Enter the width of the room : ";
					cin >> _width;
					cout << "Enter the heigth of the room : ";
					cin >> _heigth;

					if (_width > 0 && _heigth > 0)
					{
						cout << "\nProperties have been changed!" << endl << endl;
						this->Rooms[i].SetHeigth(_heigth);
						this->Rooms[i].SetWidth(_width);
					}
					else
					{
						cout << "\nSomething wrong! Try one more time!" << endl << endl;
					}
				}
			}
		}
	}

	void RoomsOnTheFloor()
	{
		int _floor;

		cout << "Enter the floor to know info about it: ";
		cin >> _floor;

		system("cls");

		if (0 < _floor <= this->FloorNumber)
		{
			cout << "Floor ¹" << _floor << endl << endl;

			for (auto i = 0; i < this->RoomNumber; i++)
			{
				if (this->Rooms[i].GetFloor() == _floor)
				{
					this->Rooms[i].RoomInfo();
				}
			}
		}
		else
		{
			cout << "\nSomething wrong! Try one more time!" << endl << endl;
		}
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
		cout << "~~Your functions~~" << endl
			<< "0. Exit " << endl
			<< "1. Information about house rooms" << endl
			<< "2. Output total rooms square" << endl
			<< "3. Output total room square by floor" << endl
			<< "4. Change room properties" << endl
			<< "5. Output information about rooms on the floor" << endl
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
			system("cls");
			house.ShowRoomInfo();
			house.PressTheButton();
			break;
		}
		case 2:
		{
			system("cls");
			house.OutputTotalRoomsSquare();
			house.PressTheButton();
			break;
		}
		case 3:
		{
			system("cls");
			house.OutputLevelSquare();
			house.PressTheButton();
			break;
		}
		case 4:
		{
			system("cls");
			house.ChangeRoomProperties();
			house.PressTheButton();
			break;
		}
		case 5:
		{
			system("cls");
			house.RoomsOnTheFloor();
			house.PressTheButton();
			break;
		}
		default:
		{
			cout << "Invalid code!" << endl;
			house.PressTheButton();
			break;
		}
		}
	}
}