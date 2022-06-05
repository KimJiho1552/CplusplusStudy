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
	if (!rfp) { //���� ó��
		fputs("st.db ������ �� �� �����ϴ�.\n", stdout);
		return 1;
	}
	fseek(rfp, 0, SEEK_END); //������ ���� ���� ù ��° ��ġ�� ����Ŵ -> �� ��(SEEK_END)���� �̵�

	int size = ftell(rfp); //���� ũ��
	int cnt = size / sizeof(student); //����ü ���� Ȯ��(48 / 24 = 2)
	
	st = (student*)malloc(cnt * sizeof(student));
	//st = (student*)calloc(cnt, sizeof(student));
	
	fseek(rfp, 0, SEEK_SET); //�� ó��(SEEK_SET)���� �̵�

	read_st(st, cnt, rfp);
	print_st(st);

	free(st);
	return 0;
}

void save_st(student* st) {
	FILE* wfp;
	wfp = fopen("st.db", "w");
	if (wfp == NULL) { //���� ó��
		fputs("st.db ������ �� �� �����ϴ�.\n", stdout);
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