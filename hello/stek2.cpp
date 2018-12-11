#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <io.h>
#include <conio.h>
#include <process.h>
#include <time.h>
#include <stdlib.h>




struct list_element

{
	int value;
	struct list_element * next;
};

void print_list(struct list_element *);
struct list_element * create_LIFO(int);
void delete_list(struct list_element *);

void main1233()

{
	int N;
	struct list_element *FIRST = NULL; //��������� �� ������ ������� ������
	setlocale(LC_CTYPE, "Russian");
	printf("������� ���-�� ��������� ������ (N - ����� �����):\n");
	scanf("%d", &N);
	srand(time(0));
	puts("�������� ������:");
	FIRST = create_LIFO(N);
	puts("�������� ������:");
	print_list(FIRST);
	delete_list(FIRST);
	_getch();

}

struct list_element *create_LIFO(int N)
{
	struct list_element * FIRST = NULL, *TMP = NULL;
	for (int i = 0; i < N; i++)

	{
		TMP = FIRST;
		FIRST = new list_element;
		FIRST->next = TMP;
		FIRST->value = rand();
		printf("%d - %d\n", i + 1, FIRST->value);

	}
	return FIRST;
	}


void print_list(struct list_element * list)

{
	int i = 1; //����������, ������� �������� ����� �������������� ���������(�������.��� ������ ��� ������� �����������)

		while (list) //���������� ����, ��� ����������� ���� list �� ������ ����� NULL
		{
		printf("%2.d ADDR: %p VALUE: %d\tADDR_NEXT: %p\n", i, list,
		list->value, list->next); //����� ���������� �� �������� ������
		list = list->next; //�������� � list ����� �������� ���������� �� ���������, ����� �������� �� ������ �������� �������� � list
		i++; //������. ������� ��������
		}

}


void delete_list(struct list_element *list)

{
	struct list_element *tmp; //�������. ����������, ������� ����� ������� ����� ����.���������
	while (list) //���� ���. ���� list �� ������ ������ NULL (�� ������ �� ��������� ���������)
	{
	tmp = list; //����� �������� �������� � ������ ������� �� ��������� (���������������)����������
	list = list->next; //� �������� ������� ��������� ������������� ���������
	delete tmp; //������� ���������, ������� ������������ �� ������ ��������
	}

}