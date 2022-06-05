#include <iostream>

using namespace std;

class Circle {
	int radius;
public :
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	void setRadius(int r) { radius = r; }
	double getArea();
};

double Circle::getArea() {
	return 3.14 * radius * radius;
}

void print_circle(Circle* p);

int main() {
	Circle circleArray[3] = { Circle(10), Circle(20), Circle(30) };

	/*circleArray[0].setRadius(10);
	circleArray[1].setRadius(20);
	circleArray[2].setRadius(30);*/

	for (int i = 0; i < 3; i++) cout << "Circle " << i << "의 면적은 " << circleArray[i].getArea() << endl;

	print_circle(circleArray);
	
	return 0;
}

void print_circle(Circle* p) {
	for (int i = 0; i < 3; i++) {
		cout << "Circle " << i << "의 면적은 " << p->getArea() << endl;
		p++;
	}
}