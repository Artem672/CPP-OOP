#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>

using namespace std;

void FillFirstV(vector<int>& V1)
{
	int Size; int Number;
	cout << "Enter size of vector-> ";
	cin >> Size;
	system("cls");
	
	for (int i = 0; i < Size; i++)
	{	
		cout << "------First vector-----" << endl;
		cout << "Enter element to add-> ";
		cin >> Number;
		V1.push_back(Number);
		system("cls");
	}
}

void FillSecondV(vector<int>& V2)
{
	for (int i = 0; i < 10; i++)
	{
		V2.push_back(0);
	}
}

void FillThirdV(vector<int>& V3)
{
	int Size;
	cout << "Enter size of vector-> ";
	cin >> Size;
	system("cls");
	for (int i = 0; i < Size; i++)
	{
		V3.push_back(rand() % 10);
	}
	cout << "Vector was randomized!" << endl;
}

void FillFourthV(vector<int>& V4, vector<int> V1)
{
	for (auto i = V1.begin(); i != V1.end(); i++)
	{
		V4.push_back(*i);
	}
}

void FillFifthV(vector<int>& V5, vector<int> V3)
{
	for (auto i = V3.begin() + 1; i != V3.end() - 1; i++)
	{
		V5.push_back(*i);
	}
}

void PrintVector(vector<int> Vector)
{
	if (!Vector.empty())
	{
		cout << "Vector : ";
		for (auto i = Vector.begin(); i != Vector.end(); ++i)
		{
			cout << *i << ",  ";
		}
	}
	else
	{
		cout << "Vector is empty!" << endl;
	}
	
}

void BackwardsFirstV(vector<int> V1)
{
	ofstream Fill("Numbers.txt");
	Fill.clear();

	
	for (auto i = V1.end() - 1; i != V1.begin(); i--)
	{
		Fill << *i << " ";
	}

	auto i = V1.begin();
	Fill << *i;
	
	Fill.close();
}

void EditSecondV(vector<int>& V2)
{
	V2.clear();
	for (int i = 0; i < 10; i++)
	{
		V2.push_back(i + 1);
	}

	auto i = V2.begin() + 1;

	V2.erase(i);

	auto g = V2.end() - 1;

	V2.erase(g);
}

void DoubleFourthV(vector<int>& V4)
{
	int size = V4.size();
	int* Array = new int[size];
	int i = 0;

	for (auto b = V4.begin(); b != V4.end(); b++)
	{
		Array[i] = *b;
		i++;
	}

	V4.clear();

	for (int i = 0; i < size; i++)
	{
		V4.push_back(Array[i]);
		V4.push_back(Array[i]);
	}

	delete Array;
}

void DeleteAndSaveFifthV(vector<int>& V5, vector<int> V4)
{
	V5.clear();

	for (auto i = V4.begin(); i != V4.end(); i++)
	{
		if (*i % 2 == 0)
		{
			V5.push_back(*i / 2);
		}
	}
}

void Swapvectors(vector<int>& V4, vector<int>& V5)
{
	int Size = V4.size();
	int* Array = new int[Size];

	int i = 0;
	for (auto b = V4.begin(); b != V4.end(); b++)
	{
		Array[i] = *b;
		i++;
	}

	V4.clear();

	for (auto i = V5.begin(); i != V5.end(); i++)
	{
		V4.push_back(*i);
	}

	V5.clear();

	for (int i = 0; i < Size; i++)
	{
		V5.push_back(Array[i]);
	}

}

int main()
{
	srand((unsigned)time(NULL));
	vector<int> V1;
	vector<int> V2;
	vector<int> V3;
	vector<int> V4;
	vector<int> V5;

#pragma region FirstPart
	FillFirstV(V1);
	//system("cls");
	//PrintVector(V1);
	FillSecondV(V2);
	//system("pause");
	//system("cls");
	//PrintVector(V2);
	//system("pause");
	//system("cls");
	FillThirdV(V3);
	//system("pause");
	//system("cls");
	//PrintVector(V3);
	//system("pause");
	//system("cls");
	FillFourthV(V4, V1);
	//PrintVector(V4);
	//system("pause");
	//system("cls");
	FillFifthV(V5, V3);
	//PrintVector(V3);
	//cout << endl;
	//PrintVector(V5);
	//system("pause");
	//system("cls");
#pragma endregion

#pragma region SecondPart
	cout << "Third ";
	PrintVector(V3);
	BackwardsFirstV(V1);
	system("pause");
	system("cls");
#pragma endregion
#pragma region ThirdPart
	EditSecondV(V2);
	PrintVector(V2);
	system("pause");
	system("cls");
#pragma endregion
#pragma region FourthPart
	DoubleFourthV(V4);
	PrintVector(V4);
	system("pause");
	system("cls");
#pragma endregion
#pragma region FifthPart
	DeleteAndSaveFifthV(V5, V4);
	PrintVector(V4);
	cout << endl;
	PrintVector(V5);
	system("pause");
	system("cls");
#pragma endregion
#pragma region SixPart
	Swapvectors(V4, V5);
	PrintVector(V4);
	cout << endl;
	PrintVector(V5);
	system("pause");
	system("cls");
#pragma endregion


}