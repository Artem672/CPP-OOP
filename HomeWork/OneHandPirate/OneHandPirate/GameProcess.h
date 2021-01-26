#pragma once
#include "Queue.h"

class GameProcess
{
private:
	int Cash = 0;
	const int Size = 6;
	
public:
	
	int GetCash();
	void SetCash(int Cash);
	void Rolling();
};

