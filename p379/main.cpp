#include <iostream>
#include <string>

using namespace std;

class Point {
private:
	int x, y;
public:
	Point(int x = 0, int y = 0) { this->x = x; this->y = y; }
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() { cout << "(" << x << ", " << y << ")" << endl; }
};

class ColorPoint : public Point {
private:
	string color;
public:
	void setColor(string color) { this->color = color; }
	void showColorPoint() {
		cout << color << ":";
		showPoint();
	}
};

class GrayPoint : public Point {
private:
	string color;
	string color1;
public:
	void setColor(string color) { this->color = color; }
	void showColorPoint() {
		cout << color << ":";
		showPoint();
	}
	void setColor1(string color1) { this->color1 = color1; }
	void showColorPoint1() {
		cout << color1 << ":";
		showPoint();
	}
};

/*
void testShow(ColorPoint& p) {
	p.showColorPoint();
}

void testShow(GrayPoint& p) {
	p.showColorPoint();
}
*/

void testShow(Point* p) {
	/*�ٿ� ĳ����*/
	if (typeid(*p) == typeid(ColorPoint)) {
		ColorPoint* cp = (ColorPoint*)p;
		cp->showColorPoint();
	}
	else if (typeid(*p) == typeid(GrayPoint)) {
		GrayPoint* gp = (GrayPoint*)p;
		gp->showColorPoint1();
	}
}

int main() {
	ColorPoint cp;
	GrayPoint gp;

	cp.set(3, 4);
	cp.setColor("Red");

	gp.set(1, 2);
	gp.setColor1("Black");

	//testShow(cp);
	//testShow(gp);

	/*�� ĳ����*/
	testShow(&cp);
	testShow(&gp);

#if 0
	/*�� ĳ����*/
	ColorPoint cp;
	ColorPoint* pDer = &cp;
	Point* pBase = pDer; //��ҽ��״ٰ� �����ϸ� ����

	pDer->set(3, 4);
	pBase->showPoint();
	pDer->setColor("Red");
	pDer->showColorPoint();

	/*�ٿ� ĳ����*/
	pDer = (ColorPoint*)pBase;
#endif

#if 0
	Point p(0, 0);
	p.showPoint(); //������ �� �������

	ColorPoint cp;
	cp.showPoint();
	cp.set(3, 4);
	cp.setColor("Red");
	cp.showColorPoint();
#endif
}