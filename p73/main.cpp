#include <iostream>
#include <cstring>
using namespace std;

static int my_strcmp(char* pd, const char* ps);

int main(int argc, char* argv[]) {
	char name[11];
	cout << "이름 입력" << endl;

	while (true) {
		cout << " 이름 : ";
		cin >> name;
		if (my_strcmp(name, "kjh") == 0) {
			cout << "종료" << endl;
			break;
		}
		else cout << "다시 입력" << endl;
	}

	return 0;
}

static int my_strcmp(char* pd, const char* ps) {
	static int temp;
	
	if (*pd > *ps) temp = 1;
	if (*pd == *ps) temp = 0;
	if (*pd < *ps) temp = -1;

	return temp;
}