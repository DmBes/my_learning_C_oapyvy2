#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <process.h>
#include <conio.h>


struct list_element

{

	int value; //��������
	struct list_element * next; //��������� �� ��������� ���������
};

void maiadn()

{

	int N = 4;
	struct list_element * FIRST = NULL, *CURRENT = NULL; //FIRST --	��������� �� ������ ������, CURRENT -- ��������������� ����������
		for (int i = 0; i < N; i++)
		{
			if (FIRST == NULL) //��������� ������ �� ������ ������� ������
			{
				FIRST = new struct list_element; //���� ���, ������� ������ �������
				CURRENT = FIRST; //������������� ��� � �������� ��������
			}
			else
			{//���� ��� �� ������ �������
				CURRENT->next = new struct list_element; //������� � ������	���������, � ���� next ������� ��������� ���������� ����� ���������
					CURRENT = CURRENT->next;//� �������� ������� ������������� ���������
			}
			CURRENT->next = NULL; //����� ��������� �� ������� ������������� � NULL
			CURRENT->value = rand(); //������������� �������� ���� value ��������� ���������(��������� ��������� ����.�����)
			printf("%d - %d\n", i + 1, CURRENT->value); //������� �� ������	���������� �� � ��������� ���������
		}

		_getch();

}