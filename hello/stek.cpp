#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <io.h>
#include <conio.h>
#include <process.h>

#include <stdlib.h>

struct list_element

{

	int value; //��������

	struct list_element * next;//��������� �� ��������� ���������

};

void main22() {
	struct list_element * FIRST = NULL, *TMP = NULL;
	int N = 4;

	//FIRST -- ��������� �� ������ ������, TMP -- ��������������� ����������

		for (int i = 0; i < N; i++) {

		TMP = FIRST; // ���������� � TMP ����� ���������, ������� ����������� �� ���������� ��������(1 - � �������� -- NULL)
		FIRST = new list_element; //������� � ������ ����� ���������

		FIRST->next = TMP; //������� ��������� ��������� �� ���������� ����a�� ������ ��������(���� next) ��������� ����� ���������
		//����.�����.����(����� ��� �������� � TMP)

		FIRST->value = rand();//������������� �������� ���� value ��������� ���������

		printf("%d - %d\n", i + 1, FIRST->value); //������� �� ������ ���������� �� � ��������� ���������

		}

	_getch();

}



