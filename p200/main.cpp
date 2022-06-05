#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cout << "µ¡¼À" << endl;
	getline(cin, s, '\n');
	int sum = 0;
	int startIndex = 0;
	while (true) {
		int fIndex = s.find('+', startIndex);
		if (fIndex == -1) {
			string part = s.substr(startIndex);
			if (part == "") break;
			cout << part << endl;
			sum += stoi(part);
			break;
		}
		int cnt = fIndex - startIndex;
		string part = s.substr(startIndex, cnt);

		cout << part << endl;
		sum += stoi(part);
		startIndex = fIndex + 1;
	}
	cout << "ÇÕ " << sum;
}