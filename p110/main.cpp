#include <iostream>
#include "Circle.h"

using namespace std;

int main() {
	Circle donut;
	double area = donut.getArea();
	cout << "donut area : " << area << endl;

	Circle pizza(30);
	area = pizza.getArea();
	cout << "pizza area : " << area << endl;
}