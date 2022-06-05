#include <iostream>

using namespace std;

void r_swap(int& a, int& b);
void p_swap(int* a, int* b);

int main() {
	int m = 2, n = 9;
	cout << "main() : " << m << " " << n << endl;
	r_swap(m, n);
	p_swap(&m, &n);
}

void r_swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
	cout << "r_swap() : " << a << " " << b << endl;
}

void p_swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	cout << "p_swap() : " << *a << " " << *b << endl;
}