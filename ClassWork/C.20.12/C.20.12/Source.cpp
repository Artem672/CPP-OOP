#include <iostream>
#include <string>

using namespace std;

namespace Person {
	void Print() {
		cout << "namespace Person " << endl;
	}
}

namespace Building {
	void Print() {
		cout << "namespace Building " << endl;
	}
}

using namespace Person;

int main() {

	Person::Print();
	Building::Print();

	Print();


	system("pause");
	return 0;
}
		​​​​