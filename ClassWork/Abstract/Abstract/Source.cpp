#include <iostream>
#include <string>

using namespace std;

class House
{
private:

	class Room
	{
	private:
		double Width;
		double Heigth;
		int Floor;
	public:

		Room(double Width, double Heigth, int Floor)
		{
			this->Width = Width;
			this->Heigth = Heigth;
			this->Floor = Floor;
		}

		double RoomSquare()
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

	int RoomNumbers = 10;
	int FloorNumbers = 5;
	Room Kitchen;
	
	Room* rooms = new Room[RoomNumbers];


	~House()
	{
		delete[] rooms;
	}


};

int main()
{
	
}