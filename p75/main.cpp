#include <iostream>

using namespace std;

int main() {
	cout << "주소 : ";
	char address[100];
	cin.getline(address, 100, '\n');

	cout << "주소는 " << address << "입니다.\n";
}