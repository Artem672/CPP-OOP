#include "GameProcess.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned)time(NULL));

	cout << "Press Enter to start the game..." << endl;
	getchar();

	system("cls");

	GameProcess Start;


	Start.Rolling();
	return 0;
}