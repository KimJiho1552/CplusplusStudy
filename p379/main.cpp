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
	/*다운 캐스팅*/
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

	/*업 캐스팅*/
	testShow(&cp);
	testShow(&gp);

#if 0
	/*업 캐스팅*/
	ColorPoint cp;
	ColorPoint* pDer = &cp;
	Point* pBase = pDer; //축소시켰다고 생각하면 편함

	pDer->set(3, 4);
	pBase->showPoint();
	pDer->setColor("Red");
	pDer->showColorPoint();

	/*다운 캐스팅*/
	pDer = (ColorPoint*)pBase;
#endif

#if 0
	Point p(0, 0);
	p.showPoint(); //쓰레기 값 들어있음

	ColorPoint cp;
	cp.showPoint();
	cp.set(3, 4);
	cp.setColor("Red");
	cp.showColorPoint();
#endif
}