#pragma once
#include <iostream>
#include <string>

using namespace std;

class Auto
{
private:
	string Number;
	size_t Max_Speed;
	size_t Current_Speed;

public:

	Auto();

	string GetNumber()
	{
		return this->Number;
	}

	size_t GetMaxSpeed()
	{
		return this->Max_Speed;
	}

	size_t GetCurrentSpeed()
	{
		return this->Current_Speed;
	}

	void SetNumber(string Number)
	{
		this->Number = Number;
	}

	void SetMaxSpeed(size_t Max_Speed)
	{
		this->Max_Speed = Max_Speed;
	}

	void SetCurrentSpeed(size_t Current_Speed)
	{
		this->Current_Speed = Current_Speed;
	}

	void RaiseSpeed()
	{
		this->Current_Speed += 5;
	}

	void ReduceSpeed()
	{
		this->Current_Speed -= 5;
	}
};

class WrongSpeedException : public Auto
{

};

class WrongMaxSpeedException
{

};

class InvalidNumberException : public Auto
{
public:
	void SetNumber()
	{
		if (GetNumber().length() > 8)
		{
			throw ("Invalid length");
		}
		else
		{
			if (isalpha(GetNumber()[0]) && isalpha(GetNumber()[1]) && isalpha(GetNumber()[6]) && isalpha(GetNumber()[7]))
			{
				if (isdigit(GetNumber()[2]) && isalpha(GetNumber()[3]) && isalpha(GetNumber()[4]) && isalpha(GetNumber()[5]))
				{
					throw("Succesfully");
				}
				else
				{
					throw("Invalid central numbers");
				}
			}
			else
			{
				throw("Invalid symbols");
			}
		}

	}
};

