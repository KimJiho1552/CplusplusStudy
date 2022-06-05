#include <stdio.h>

char* my_strcat(char* pd, char* ps);
char* my_strcpy(char* pd, char* ps);

int main(int argc, char* argv[]) {
	char fruit[80] = "straw";
	//char fruit[80] = {'s', 't', 'r', 'a', 'w'};
	int cnt = 0;

	/*for (int i = 0; i < argc; i++) {
		printf("argv[%d] Pointer : %p\n", i, argv[i]);
		printf("argv[%d] : %s\n", i, argv[i]);
	}*/

	/*while (1) {
		if (argv[cnt] != NULL) {
			printf("argv[%d] : %s\n", cnt, argv[cnt]);
			cnt++;
		}
		else break;
	}*/

	/*do {
		printf("argv[%d] Pointer : %p\n", cnt, *(argv + cnt));
		printf("argv[%d] : %s\n", cnt, *(argv + cnt));
		cnt++;
	} while (argv[cnt] != '\0');*/
	
	printf("문자열 : %s\n", fruit);
	//printf("문자열 주소 : %p\n", "straw");
	my_strcat(fruit, "berry");
	printf("연결된 문자열 : %s\n", fruit);

	my_strcpy(fruit, "banana");
	printf("변경된 문자열 : %s\n", fruit);

	return 0;
}