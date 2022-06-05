#include <iostream>
#include <string>

using namespace std;

class Circle {
private:
	int radius;
public:
	//Circle() { radius = 1; } //기본 생성자
	Circle(int r = 1) { radius = r; }
	~Circle() { cout << radius << " 소멸" << endl; } //소멸자
	double getArea() { return 3.14 * radius * radius; } //출력

	void setRadius(int r) { radius = r; }
	double getRadius() { return 3.14; }

	Circle(const Circle& c) { //디폴트 복사 생성자
		this->radius = c.radius;
		cout << "복사 생성자 실행 radius = " << radius << endl;
	}

	friend bool equals(Circle i, Circle j); //friend
};

void v_increase(Circle c) {
	int r = c.getRadius();
	c.setRadius(r + 1);
}

void p_increase(Circle* c) {
	int r = c->getRadius();
	c->setRadius(r + 1);
}

bool equals(Circle i, Circle j) { //friend
	if (i.radius == j.radius) return true;
	else return false;
}

int main() {
	Circle r1;
	Circle r2(30);
	
	cout << r1.getArea() << endl;
	cout << r2.getArea() << endl;

	Circle r3[3] = { Circle(100), Circle(200), Circle(300) };
	Circle* p;
	p = r3;
	for (int i = 0; i < 3; i++) {
		cout << "r[" << i << "] : " << r3[i].getArea() << endl;
		cout << "r[" << i << "] : " << (p + i)->getArea() << endl;
	}

	Circle* a, * b;
	a = new Circle();
	b = new Circle(2);
	cout << "*a : " << a->getArea() << ", *b : " << b->getArea() << endl;
	delete a, b;

	Circle r4(50);
	v_increase(r4);
	cout << r4.getRadius() << endl;
	p_increase(&r4);
	cout << r4.getRadius() << endl;

	Circle r5(50);
	Circle copy(r5);

	if (equals(r1, r2)) cout << "equal" << endl;
	else cout << "not equal" << endl;
}