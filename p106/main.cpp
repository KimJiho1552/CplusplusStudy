#include <iostream>
#include "Rectangle.h"

using namespace std;

int main() {
	Rectangle rect;
	rect.width = 3;
	rect.height = 5;

	cout << "�簢�� ���� : " << rect.getArea() << endl;
}