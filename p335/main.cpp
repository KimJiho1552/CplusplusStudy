#include <iostream>

using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) { this->kick = kick; this->punch = punch; }
	void show();
	Power operator+ (Power& op2);
	bool operator== (Power& op2);
	Power& operator+= (Power& op2);
};

void Power::show() {
	cout << "kick = " << kick << ", " << "punch = " << punch << endl;
}

Power Power::operator+(Power& op2) {
	Power tmp;
	tmp.kick = this->kick + op2.kick;
	tmp.punch = this->punch + op2.punch;
	return tmp;
}

bool Power::operator==(Power& op2) {
	if (this->kick == op2.kick && this->punch == op2.punch) return true;
	else return false;
}

Power& Power::operator+=(Power& op2) {
	kick = this->kick + op2.kick;
	punch = this->punch+ op2.punch;
	return *this;
}

int main() {
	Power a(3, 5), b(4, 6), c;
	c = a + b;
	a.show();
	b.show();
	c.show();
	if (a == b) cout << "�� �Ŀ��� ����." << endl;
	else cout << "�� �Ŀ��� ���� �ʴ�." << endl;
	for (int i = 0; i < 3; i++)
		c = a += b;
	c.show();
}