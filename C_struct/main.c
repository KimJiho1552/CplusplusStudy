#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student {
	int id;
	char name[10];
	double grade;
} student;

void print_st(student* st);
void input_st(student* st);
void save_st(student* st);
void read_st(student* st, int count, FILE* rfp);
char* my_strcpy(char* pd, char* ps);

int main() {
	/*student st[2] = { { 1, "ABC", 85.0 }, { 2, "DEF", 95.1 } };

	print_st(st);
	input_st(st);
	save_st(st);
	print_st(st);*/

	student* st;
	FILE* rfp;
	rfp = fopen("st.db", "r");
	if (!rfp) { //예외 처리
		fputs("st.db 파일을 열 수 없습니다.\n", stdout);
		return 1;
	}
	fseek(rfp, 0, SEEK_END); //파일을 열면 제일 첫 번째 위치를 가리킴 -> 맨 끝(SEEK_END)으로 이동

	int size = ftell(rfp); //파일 크기
	int cnt = size / sizeof(student); //구조체 갯수 확인(48 / 24 = 2)
	
	st = (student*)malloc(cnt * sizeof(student));
	//st = (student*)calloc(cnt, sizeof(student));
	
	fseek(rfp, 0, SEEK_SET); //맨 처음(SEEK_SET)으로 이동

	read_st(st, cnt, rfp);
	print_st(st);

	free(st);
	return 0;
}

void save_st(student* st) {
	FILE* wfp;
	wfp = fopen("st.db", "w");
	if (wfp == NULL) { //예외 처리
		fputs("st.db 파일을 열 수 없습니다.\n", stdout);
		exit(1);
	}
	fwrite(st, sizeof(student), 2, wfp);
}

void read_st(student* st, int count, FILE* rfp) {
	fread(st, sizeof(student), count, rfp);
}

void print_st(student* st) {
	//for (int i = 0; i < 2; i++) printf("%d, %s, %.1lf\n", st[i].id, st[i].name, st[i].grade);
	//for (int i = 0; i < 2; i++) printf("%d, %s, %.1lf\n", (*(st + i)).id, (*(st + i)).name, (*(st + i)).grade);
	for (int i = 0; i < 2; i++) printf("%d, %s, %.1lf\n", (st + i)->id, (st + i)->name, (st + i)->grade);
}

void input_st(student* st) {
	my_strcpy(st[0].name, "abc");
	my_strcpy(st[1].name, "def");
}

char* my_strcpy(char* pd, char* ps) {
	char* po = pd;

	while (*ps != '\0') {
		*pd = *ps;
		pd++;
		ps++;
	}
	*pd = '\0';

	return po;
}