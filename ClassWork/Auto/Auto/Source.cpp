#include "Auto.h"

int main()
{
	Auto A;

	try
	{
		A.SetNumber("B125");
	}
	catch ( InvalidNumberException& e)
	{
		e.SetNumber();
	}
}