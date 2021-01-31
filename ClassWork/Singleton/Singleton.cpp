#include "Header.h"

Logger* Logger::getObj(string name)
{
	if (obj == nullptr)
		obj = new Logger(name);

	return obj;
}
Logger* Logger::obj = 0;
void main()
{
	Logger* l1 = Logger::getObj();
	l1->Print();
	Logger* l2 = Logger::getObj("admin");
	l2->Print();
	l2->setObj("admin");
	cout << "l2->Print()" << endl;
	l2->Print();
	cout << "l1->Print()" << endl;
	l1->Print();
	system("pause");
}