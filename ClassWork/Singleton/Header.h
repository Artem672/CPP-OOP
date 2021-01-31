#pragma once
#include <iostream>
#include <string>

using namespace std;

class Logger {
	string name;
	static Logger* obj;
	Logger(string name)
	{}

public:
	string getName() const
	{
		return this->name;
	}
	static Logger* getObj(string name = "user");
	void setObj(string name)
	{
		this->name = name;
	}
	void Print()
	{
		cout << this->name << " has already logged in" << endl;
	}

};