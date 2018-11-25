#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <io.h>
#include <conio.h>
#include <process.h>
#include <Windows.h>



struct FIO {
	char name[50];
	char surname[50];
};

struct school {
	FIO date;
	int math;
	int eng;
	int phys;
	char pov[20];
	double aver;
} stud;

void InpStr(int);
void OutStr(int);

void main2() {

	setlocale(LC_CTYPE, "Russian");

	int pos = 1, n;

	while (pos > 0 && pos < 3) {
		system("cls");
		puts("�������� ����� ����:");
		puts("---------------------------------------------");
		puts("1. ������� ������");
		puts("2.�������� ���������");
			puts("3.�����");
				puts("---------------------------------------------");

		scanf("%d%*c", &pos);
		switch (pos) {
		case 1:
			puts("������� ���-�� ���������");
			scanf("%d", &n);
			InpStr(n);
			break;
		case 2:
			OutStr(n);
			break;
		default:
			puts("����� �� ���������.");
			break;
		}
	}
	_getch();
}

void InpStr(int n) {
	FILE *fp;
	school *stud = new school[n];

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	if ((fp = fopen("d:\\Students.txt", "w")) == NULL) {
		printf("Cannot open file.\n"); exit(1);
	}

	for (int i = 0; i < n; i++) {

		system("cls");
		printf("������� �%\d\n", i + 1);
		puts("������� ������� ��������:");
		fflush(stdin);
		gets_s(stud->date.surname);
		puts("������� ��� ��������:");
		fflush(stdin);
		gets_s(stud->date.name);
		puts("������� ������ �� ����������");
		scanf("%d", &stud->math);
		puts("������� ������ �� ����������� �����");
		scanf("%d", &stud->eng);
		puts("������� ������ �� ������");
		scanf("%d", &stud->phys);
		puts("������� ������ ���������");
		fflush(stdin);
		gets_s(stud->pov);
		fwrite(stud, sizeof(school), 1, fp);
	}

	fclose(fp);
}

void OutStr(int n) {

	FILE *fp;
	school *stud = new school[n];

	if ((fp = fopen("d:\\Students.txt", "r")) == NULL) {
		printf("Cannot open file.\n"); exit(1);
	}

	while (fread(stud, sizeof(school), 1, fp) != NULL) {

		printf("%s %10s %5d %10d %10d %10s \n", stud->date.surname,
			stud->date.name, stud->math, stud->eng, stud->phys, stud->pov);
	}
	fclose(fp);
	_getch();

}

