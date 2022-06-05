#include <iostream>
#include <string>

using namespace std;

class Circle {
private:
	int radius;
	char name[12];
public:
	Circle(const Circle& c);
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
	void setName(const char* np) { strcpy(name, np); }
	char* getName() { return name; }
};

Circle::Circle(const Circle& c) {
	this->radius = c.radius;
	strcpy(this->name, c.name);
	cout << "복사 생성자 실행 radius = " << radius << endl;
}

int main() {
	Circle src(30);
	src.setName("홍길동");
	cout << "원본의 면적 : " << src.getArea() << endl;
	cout << "name : " << src.getName() << endl;
	Circle dest(src);

	cout << "사본의 면적 : " << dest.getArea() << endl;
	cout << "name : " << dest.getName() << endl;
}