#include <stdio.h>

void user_strcat(char* str1, char* str2);

int main() {
	char fruit[80] = "straw";
	user_strcat(fruit, "berry");
	printf("%s", fruit);

	return 0;
}

void user_strcat(char* str1, char* str2) {
	int a = strlen(str1);
	int b = strlen(str2);
	int cnt = 0;

	while (cnt < b) {
		//str1[a + cnt] = str2[cnt];
		*(str1 + (a + cnt)) = *(str2 + cnt);
		cnt++;
	}
	str1[a + b] = '\0';
}