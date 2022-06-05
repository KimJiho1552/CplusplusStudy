#include <iostream>
#include <string>

using namespace std;

class Animal {
	string name;
	int age;
public:
	Animal(string name = "animal", int age = 0) : name(name), age(age) {
		cout << "Animal ����" << endl;
	}
	Animal(const Animal& a) : name(a.name), age(a.age) {}
	virtual ~Animal() { cout << "Animal �Ҹ�" << endl; }

	void setName(string name) { this->name = name; }
	void setAge(int age) { this->age = age; }
	string getName() { return this->name; }
	int getAge() { return this->age; }

	friend void running(Animal* pAnimal);
	virtual void crying() = 0;
};

class Dog : public Animal {
	string bark;
public:
	Dog(string name, int age, string bark) : Animal(name, age) {
		this->bark = bark;
		cout << "Dog ����" << endl;
	}
	Dog(const Dog& d) : Animal(d), bark(d.bark) {}

	void setBark(string bark) { this->bark = bark; }
	string getBark() { return bark; }

	virtual ~Dog() { cout << "Dog �Ҹ�" << endl; }
	virtual void crying() { cout << getName() << "�� " << bark << endl; }
};

class Cat : public Animal {
	string bark;
public:
	Cat(string name, int age, string bark) : Animal(name, age) {
		this->bark = bark;
		cout << "Cat ����" << endl;
	}

	void setBark(string bark) { this->bark = bark; }
	string getBark() { return bark; }

	virtual ~Cat() { cout << "Cat �Ҹ�" << endl; }
	virtual void crying() { cout << getName() << "�� " << bark << endl; }
};

void running(Animal* pAnimal) {
	cout << pAnimal->name << "�� �޸���." << endl;
}

void crying(Animal* pAnimal) {
	pAnimal->crying();
}

int main() {
	cout << "--�߻�Ŭ������ �Ļ�Ŭ���� ����--\n";
	Dog* dog = new Dog("������", 4, "�۸�");
	Cat* cat = new Cat("�����", 2, "�߿�");
	cout << "\n--�Ű������� ������ ����--\n";
	crying(dog);
	crying(cat);
	running(dog);
	running(cat);
	cout << "\n--�⺻ ��������� ���� ����--\n";
	Dog copyDog(*dog);
	cout << copyDog.getName() << endl;
	cout << copyDog.getAge() << endl;
	cout << copyDog.getBark() << endl;
	cout << "\n--�Ҹ��� ����--\n";
	delete dog;
	delete cat;

	return 0;
}