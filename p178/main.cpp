#include <iostream>
#include <string>

using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14 * radius * radius; };
};

int main() {
	/*Circle* p, * q;
	p = new Circle;
	q = new Circle(30);
	cout << p->getArea() << endl << q->getArea() << endl;

	delete p, q;*/

	/*Circle* pArray = new Circle[3];

	pArray[0].setRadius(10);
	pArray[1].setRadius(20);
	pArray[2].setRadius(30);

	for (int i = 0; i < 3; i++) cout << pArray[i].getArea() << endl;

	Circle* p = pArray;
	for (int i = 0; i < 3; i++) cout << (p + i)->getArea() << endl;

	delete[] pArray;*/

	string str = "123456789123456789";
	cout << str.size() << endl;
	cout << str.capacity() << endl; //byte
	cout << str.find("58") << endl; //찾는 문자열의 시작 위치 값(없으면 -1 리턴됨)

	return 0;
}