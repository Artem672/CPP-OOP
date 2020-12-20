#include <iostream>
#include <string>

using namespace std;


class Cat {
private:
	string name;
	string breed;
	int age;
public:
	Cat(string name, string breed, int age) {
		this->name = name;
		this->breed = breed;
		this->age = age;
	};
	Cat() {}
	void Print() {
		cout << "Name: " << this->name << "\nBreed: " << this->breed << "\nAge: " << this->age << endl;
	}
};

class Dog {
private:
	string name;
	string breed;
	int age;
public:
	Dog(string name, string breed, int age) {
		this->name = name;
		this->breed = breed;
		this->age = age;
	};
	Dog() {}
	void Print() {
		cout << "Name: " << this->name << "\nBreed: " << this->breed << "\nAge: " << this->age << endl;
	}
};

template<typename T, typename T2>
class Animal {
private:
	T animal;
public:
	Animal(T animal) {
		this->animal = animal;
		ShowAnimal();
	}

	void ShowAnimal() {
		this->animal.Print();
	}
};

int main()
{
	Cat cat("Mirzik", "GoodBreed", 5);
	Dog dog("Bobik", "Labrador", 2);

	Animal<Cat> animal(cat);
	Animal<Dog> animal2(dog);

	system("pause");
	return 0;
}