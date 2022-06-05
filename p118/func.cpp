#include "Rectangle.h"

Rectangle::Rectangle() : Rectangle(1) {
	//width = height = 1;
}

Rectangle::Rectangle(int w, int h) : width(w), height(h) {
	/*width = w;
	height = h;*/
}

Rectangle::Rectangle(int length) : Rectangle(length, length) {
	//width = height = length;
}

bool Rectangle::isSquare() {
	if (width == height) return true;
	else return false;
}