#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <process.h>
#include <conio.h>
#include <string.h>
#define N 20
#define M 20

struct der
{
	char *inf; // �������������� ����
	int n; // ����� ������ ���. ���� � �������� ������
	der *l, *r; // ��������� �� ����� � ������ ���������
};

void see_2(der *);
der *sozd(der *);
void add(der *);
void main(void)
{
	setlocale(LC_CTYPE, "Rus");
	der *dr;
	dr = NULL; // ����� ����� ��������� ������
	system("cls");
	while (1)
	{
		puts("��� �������� : \n1 - ������� ������");
		puts("2-����� ����������� ������");
		puts("3-���������� ��������� � ������");
		puts("4-�����");
		fflush(stdin);
		switch (_getch())
		{
		case '1': dr = sozd(dr); break;
		case '2': see_2(dr); _getch(); break;
		case '3': add(dr); break;
		case '4': return;
		}
		system("cls");
	}
}

der *sozd(der *dr)

{
	if (dr)
	{
		puts("�������� ������ ��� �������");
		return (dr);
	}
	if (!(dr = (der *)calloc(1, sizeof(der))))
	{
		puts("��� ��������� ������");
		_getch();
		return NULL;
	}
	puts("������� ���������� � ������ ������");
	dr->inf = (char *)calloc(1, sizeof(char)*N);
	fgets(dr->inf,50,stdin);
	dr->n = 1; // ����� �������� ���������� � ������
	return dr;
}

void add(der *dr)

{
	der *dr1, *dr2;
	char *st; // ������ ��� ������� ����������
	int k; // ��������� ��������� ���� �����
	int ind;
	if (!dr)
	{
		puts("��� ����� ������ \n");
		_getch();
		return;
	}
	do
	{
		puts("������� ���������� � ��������� ���� ������ (0 - �����)");
		st = (char *)calloc(1, sizeof(char)*N); //������ ��� ���������� ���.
		fgets(st,50, stdin);
		if (!*st) return; // ����� � ������� main
		dr1 = dr;
		ind = 0; // 1 - ������� ������ �� ����� ������
		do
		{
			if (!(k = strcmp(st, dr1->inf)))
			{
				dr1->n++; // ���������� ����� ������ ���������� ����
				ind = 1; // ��� ������ �� ����� do ... while
			}
			else
			{
				if (k < 0) // ����. ������ < ������ � ������������� ����
				{
					if (dr1->l) dr1 = dr1->l; // ��������� ����� ���� ������
					else ind = 1; // ����� �� ����� do ... while
				}
				else // ����. ������ > ������ � ������������� ����
				{
					if (dr1->r) dr1 = dr1->r; // ��������� ����� ���� ������
					else ind = 1; // ����� �� ����� do ... while
				}
			}
		} while (ind == 0);
		if (k) // �� ������ ���� � ����������� �����������
		{
			if (!(dr2 = (struct der *) calloc(1, sizeof(struct der))))
			{
				puts("��� ��������� ������");
				return;
			}
			if (k < 0) dr1->l = dr2; // ������ � dr1 ������
			else dr1->r = dr2; // ............ �������
			dr2->inf = (char *)calloc(1, sizeof(char)*N);
			strcpy(dr2->inf, st); // ���������� ������ ���� dr2
			dr2->n = 1;
		}
		free(st);
	} while (1); // ����� ������� �.�. ����� �� ����� �� return
}

//����� ����������� ��������� ������

void see_2(der *dr1)
{
	struct stek
	{
		der *d;
		stek *s;
	} *st, *st1 = NULL;
	int pr = 1;
	for (int i = 0; i < 2; i++) // � ���� ��������� 2 �������� ���������� ���������
	{
		st = (stek *)calloc(1, sizeof(stek)); // �� ������ ������ ��� ������� ��
		st->d = dr1; // ������ � ������� �����������
		st->s = st1; // ��������� �� ���� ����
		st1 = st;
	}
	printf("���� �������� : %s \n", dr1->inf);
	while (st)
	{
		do
		{
			if (pr && dr1->l) dr1 = dr1->l; // ������� �� ���� �����
			else if (dr1->r) dr1 = dr1->r; // ������� �� ���� c�����
			pr = 1; // ����� ��������������� �������� ������
			if (dr1->l && dr1->r) // ���� � 2 ������� ����
			{
				st1 = st;
				st = (stek *)calloc(1, sizeof(stek));
				st->d = dr1; // ��������� �� �������� ����
				st->s = st1; // ��������� �� ���� ����
			}
			printf("���� �������� : %s \n", dr1->inf);
		} while (dr1->l || dr1->r);
		dr1 = st->d; // ������� �� ���� ���������
		st1 = st->s; // � ����� ����� ���� ���� ����������
		free(st); // �������� �� ����� ��������� �� ���� ����� ������� ����� ���� ������
			st = st1;
		if (dr1->r) pr = 0; // ������� ��������������� �������� ��
		// ���� ������������� ������ �� dr1, �.�. dr1->inf ��� ������� ��� ������� �����
	}
}