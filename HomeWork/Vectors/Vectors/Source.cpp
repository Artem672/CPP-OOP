#include <iostream>
#include <vector>

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

void PrintVector(vector<int> Vector)
{
	cout << "Print vector : ";
	for (auto i = Vector.begin(); i != Vector.end(); ++i)
	{
		cout << *i << ",  ";
	}
}

int main()
{
	vector<int> V1;
	vector<int> V2;
	vector<int> V3;
	vector<int> V4;
	vector<int> V5;

	FillFirstV(V1);
	system("cls");
	PrintVector(V1);
	FillSecondV(V2);
	system("pause");
	system("cls");
	PrintVector(V2);

}