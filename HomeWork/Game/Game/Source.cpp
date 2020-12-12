#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <Windows.h>

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

class TeamMaker
{
public:
	int HealthPoint;
	int Damage;
	int MissChance;
	string Name;
	bool Alive;
	bool RedWon = false, BlueWon = false;

	void TeamGeneration(TeamMaker* Arr)
	{
		unsigned int chance;

		SwordsMan SwMan(15, 5, 60);
		Archer Ar(12, 4, 40);
		Mage M(8, 10, 30);


		for (int i = 0; i < 3; i++)
		{
			chance = rand() % 3 + 1;
			if (chance == 1)
			{
				Arr[i].Name = "SwordsMan";
				Arr[i].HealthPoint = SwMan.GetHP();
				Arr[i].Damage = SwMan.GetDamage();
				Arr[i].MissChance = SwMan.GetMiss();
				Arr[i].Alive = true;
			}
			else if (chance == 2)
			{
				Arr[i].Name = "Archer";
				Arr[i].HealthPoint = Ar.GetHP();
				Arr[i].Damage = Ar.GetDamage();
				Arr[i].MissChance = Ar.GetMiss();
				Arr[i].Alive = true;
			}
			else if (chance == 3)
			{
				Arr[i].Name = "Mage";
				Arr[i].HealthPoint = M.GetHP();
				Arr[i].Damage = M.GetDamage();
				Arr[i].MissChance = M.GetMiss();
				Arr[i].Alive = true;
			}
		}

	}

	void OutPut(TeamMaker* Arr)
	{
		for (int i = 0; i < 3; i++)
		{
			cout << "Unit[" << i << "]" << endl;
			cout << "Name: " << Arr[i].Name << endl;
			cout << "Hp: " << Arr[i].HealthPoint << endl;
			cout << "Damage: " << Arr[i].Damage << endl;
			cout << "Miss: " << Arr[i].MissChance << endl;
			cout << "Alive status: " << Arr[i].Alive << endl << endl;
		}
	}
};

class BattleManager : public TeamMaker
{
public:

	TeamMaker TeamRed[3];
	TeamMaker TeamBlue[3];
	//TeamMaker TM;


	void GenerateTeam()
	{
		TeamGeneration(TeamBlue);
		TeamGeneration(TeamRed);
	}

	void OutputTeamRed()
	{
		OutPut(TeamRed);
	}

	void OutputTeamBlue()
	{
		OutPut(TeamBlue);
	}

	void RedAttack(int MissChanceRed, int ChooseRed, int ChooseBlue)
	{
		cout << "------------------Team Red choice------------------" << endl;
		if (TeamRed[ChooseRed].Alive == true)
		{
			
			if (MissChanceRed <= TeamRed[ChooseRed].MissChance)
			{
				cout << "Hero: " << TeamRed[ChooseRed].Name << " missed in: " << TeamBlue[ChooseBlue].Name << "!" << endl;
			}
			else
			{
				TeamBlue[ChooseBlue].HealthPoint -= TeamRed[ChooseRed].Damage;
				cout << "Hero: " << TeamRed[ChooseRed].Name << " damaged : " << TeamBlue[ChooseBlue].Name << " .Total damage: " << TeamRed[ChooseRed].Damage << ", rest health: " << TeamBlue[ChooseBlue].HealthPoint << endl;
				if (TeamBlue[ChooseBlue].HealthPoint <= 0)
				{
					cout << "Hero: " << TeamBlue[ChooseBlue].Name << " died!" << endl;
					TeamBlue[ChooseBlue].Alive = false;
				}
			}
			
		}
		else
		{
			cout << TeamRed[ChooseRed].Name<< " is dead!" << endl;
		}
		cout << "---------------------------------------------------" << endl;
	}

	void BlueAttack(int MissChanceBlue, int ChooseBlue, int ChooseRed)
	{	
		cout << "------------------Team Blue choice------------------" << endl;
		if (TeamBlue[ChooseBlue].Alive == true)
		{
			if (MissChanceBlue <= TeamBlue[ChooseBlue].MissChance)
			{
				cout << "Hero: " << TeamBlue[ChooseBlue].Name << " missed in: " << TeamRed[ChooseRed].Name << "!" << endl;
			}
			else
			{
				TeamRed[ChooseRed].HealthPoint -= TeamBlue[ChooseBlue].Damage;
				cout << "Hero: " << TeamBlue[ChooseBlue].Name << " damaged : " << TeamRed[ChooseRed].Name << " .Total damage: " << TeamBlue[ChooseBlue].Damage << ", rest health: " << TeamRed[ChooseRed].HealthPoint << endl;
				if (TeamRed[ChooseRed].HealthPoint <= 0)
				{
					cout << "Hero: " << TeamRed[ChooseRed].Name << " died!" << endl;
					TeamRed[ChooseRed].Alive = false;
				}
			}
			
		}
		else
		{
			cout << TeamBlue[ChooseBlue].Name << " is dead!" << endl;
		}
		cout << "---------------------------------------------------" << endl;
	}

	void GameSession()
	{
		
		if (RedWon != true || BlueWon != true)
		{
			while (RedWon != true || BlueWon != true)
			{
				int ChooseRed, ChooseBlue;
				bool SuccesfullyChosen = false;

				do
				{
					ChooseBlue = rand() % 3;
					ChooseRed = rand() % 3;
					if (TeamBlue[ChooseBlue].Alive == true && TeamRed[ChooseRed].Alive == true)
					{
						SuccesfullyChosen = true;
						cout << "--------------Fight--------------------------------" << endl;
						cout << "Heroes are chosen for a fight!" << endl;
					}
				} while (SuccesfullyChosen != true);

				//Fight process
				int MissChanceRed = rand() % 100 + 1, MissChanceBlue = rand() % 100 + 1, TeamStarter = rand() % 2;
				/*
				if (TeamStarter == 0)//First attack by Red Team
				{
					RedAttack(MissChanceRed, ChooseRed, ChooseBlue);
					cout << endl;
					BlueAttack(MissChanceBlue, ChooseBlue, ChooseRed);
				}
				else if (TeamStarter == 1)
				{
					BlueAttack(MissChanceBlue, ChooseBlue, ChooseRed);
					cout << endl;
					RedAttack(MissChanceRed, ChooseRed, ChooseBlue);
				}*/
				RedAttack(MissChanceRed, ChooseRed, ChooseBlue);
				cout << endl;
				BlueAttack(MissChanceBlue, ChooseBlue, ChooseRed);
				//-------------
				if (TeamRed[0].Alive == false && TeamRed[1].Alive == false && TeamRed[2].Alive == false)
				{
					cout << "Team Blue wins!" << endl;
					RedWon = true;
					break;
				}
				else if (TeamBlue[0].Alive == false && TeamBlue[1].Alive == false && TeamRed[2].Alive == false)
				{
					cout << "Team Red wins!" << endl;
					BlueWon = true;
					break;
				}
				cout << endl << endl;
				//system("PAUSE");
			}
		}
		else
		{
			cout << "The match already completed!" << endl;
		}
		
	}

};

int main()
{
	srand((unsigned)time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	BattleManager BM;
	BM.GenerateTeam();
	int choice = 0;
	do
	{

		cout << "-------------Menu------------" << endl
			<< "0. Exit" << endl
			<< "1. Output Red Team" << endl
			<< "2. Output Blue Team" << endl
			<< "3. Start a fight" << endl
			<< "Your choice-> ";
		cin >> choice;
		cout << endl << endl;


		switch (choice)
		{
		case 0:
		{
			exit(0);
			break;
		}
		case 1:
		{
			BM.OutputTeamRed();
			break;
		}
		case 2:
		{
			BM.OutputTeamBlue();
			break;
		}
		case 3:
		{
			BM.GameSession();
			break;
		}
		default:
		{
			cout << "Invalid code!" << endl << endl;
		}
		}
	} while (true);


}