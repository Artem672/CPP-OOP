#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

class Unit
{
protected:
	int HealthPoint;
	int Damage;
	int MissChance;
public:

	Unit();

	Unit(int HealthPoint, int Damage, int MissChance)
	{
		this->HealthPoint = HealthPoint;
		this->Damage = Damage;
		this->MissChance = MissChance;
	}

	int GetHP()
	{
		return this->HealthPoint;
	}

	int GetDamage()
	{
		return this->Damage;
	}

	int GetMiss()
	{
		return this->MissChance;
	}
};

class SwordsMan : public Unit
{
public:
	SwordsMan(int HealthPoint, int Damage, int MissChance) : Unit(HealthPoint, Damage, MissChance)
	{
	}
};

class Archer : public Unit
{
public:
	Archer(int HealthPoint, int Damage, int MissChance) : Unit(HealthPoint, Damage, MissChance)
	{
	}
};

class Mage : public Unit
{
public:
	Mage(int HealthPoint, int Damage, int MissChance) : Unit(HealthPoint, Damage, MissChance)
	{
	}
};

class teamRed
{
public:
	int HealthPoint;
	int Damage;
	int MissChance;

	void OutPut(teamRed *Arr)
	{
		static int i = 0;
		cout << "Team Red" << endl;
		cout << "Unit[" << i << "]" << endl;
		cout << "Hp: " << Arr[i].HealthPoint << endl;
		cout << "Damage: " << Arr[i].Damage << endl;
		cout << "Miss: " << Arr[i].MissChance << endl;
		i++;
	}
};

class teamBlue
{
public:
	int HealthPoint;
	int Damage;
	int MissChance;

	void OutPut(teamBlue* Arr)
	{
		static int i = 0;
		cout << "Team Blue" << endl;
		cout << "Unit[" << i << "]" << endl;
		cout << "Hp: " << Arr[i].HealthPoint << endl;
		cout << "Damage: " << Arr[i].Damage << endl;
		cout << "Miss: " << Arr[i].MissChance << endl;
		i++;
	}
};

int main()
{
	srand((unsigned)time(NULL));
	int chanceRed ,chanceBlue ;

	SwordsMan SwMan(15, 5, 60);
	Archer Ar(12, 4, 40);
	Mage M(8, 10, 30);

	teamRed RedArray[3];
	teamBlue BlueArray[3];

	for (int i = 0; i < 3; i++)
	{
		chanceRed = rand() % 3 + 1;
		if (chanceRed == 1)
		{
			RedArray[i].HealthPoint = SwMan.GetHP();
			RedArray[i].Damage = SwMan.GetDamage();
			RedArray[i].MissChance = SwMan.GetMiss();
		}
		else if (chanceRed == 2)
		{
			RedArray[i].HealthPoint = Ar.GetHP();
			RedArray[i].Damage = Ar.GetDamage();
			RedArray[i].MissChance = Ar.GetMiss();
			
		}
		else if (chanceRed == 3)
		{
			RedArray[i].HealthPoint = M.GetHP();
			RedArray[i].Damage = M.GetDamage();
			RedArray[i].MissChance = M.GetMiss();
			
		}
		chanceBlue = rand() % 3 + 1;
		if (chanceBlue == 1)
		{
			BlueArray[i].HealthPoint = SwMan.GetHP();
			BlueArray[i].Damage = SwMan.GetDamage();
			BlueArray[i].MissChance = SwMan.GetMiss();
		}
		else if (chanceBlue == 2)
		{
			BlueArray[i].HealthPoint = Ar.GetHP();
			BlueArray[i].Damage = Ar.GetDamage();
			BlueArray[i].MissChance = Ar.GetMiss();
		}
		else if (chanceBlue == 3)
		{
			BlueArray[i].HealthPoint = M.GetHP();
			BlueArray[i].Damage = M.GetDamage();
			BlueArray[i].MissChance = M.GetMiss();
		}
	}
	for (int i = 0; i < 3; i++)
	{
		RedArray[i].OutPut(RedArray);
	}
	
	for (int i = 0; i < 3; i++)
	{
		BlueArray[i].OutPut(BlueArray);
	}
}