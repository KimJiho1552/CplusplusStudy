#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	int a = 8;
	double b = 1.14;
	a = a << 1;

	cout << "Hello" << endl;
	cout << 5 << endl;
	cout << 3.14 << endl;
	cout << a << endl;
	cout << b << endl;
	
	cout << endl;
	cout << endl;

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << j << "X" << i << "=" << i * j << '\t';
			if (j == 9) cout << std::endl;
		}
	}
	
	return 0;
}