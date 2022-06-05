#include <iostream>
#include "Circle.h"

using namespace std;

void print_circle(Circle* p);

int main(int argc, char* argv[]) {
	/*Circle donut;
	donut.radius = 1;
	double area = donut.getArea();
	cout << "donut 면적은 " << area << endl;*/

	/*Circle pizza;
	pizza.radius = 30;
	area = pizza.getArea();
	cout << "pizza 면적은 " << area << endl;*/

	Circle donut;
	donut.radius = 1;
	print_circle(&donut);

	return 0;
}

void print_circle(Circle* p) {
	double area;
	area = p->getArea();
	cout << "donut 면적은 " << area << endl;
}