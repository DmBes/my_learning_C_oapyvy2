#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <process.h>
#include <conio.h>



/*
��������������� ������
�������� ��������� �� ��������, ���������, ���������� � ������� ������������ ������ ��� ���������������� ��������� ������.
>>>>>>>>>>>2. ������� ��� ������ �� ��������� ����� �����. � ������ ����� ������������ ������� � �� ��� �������� �������� �������.
*/

struct str
{
	int item;
	struct str *previus;
	struct str *next;
};

int menu_9_2();
struct str *create_structure(int i);
int print_structure(str *, str *);
struct str *add_structure(str *, int);
struct str *max_element();
struct str *start_f(str *, str *);
int printik(str *spisok, int keys);


int main32(int argc, char *argv[])
{
	int vib = 0;
	str *FIRST = NULL, *SECOND = NULL;

	setlocale(LC_CTYPE, "rus");
	srand(time(NULL));



	do
	{
		vib = menu_9_2();
		system("cls");
		int  prosto = 1;
		switch (vib)
		{
		case 1:

			FIRST = create_structure(prosto);
			prosto++;
			SECOND = create_structure(prosto);
			prosto--;
			break;
		case 2:
			print_structure(FIRST, SECOND);
			break;
		case 3:
			FIRST = add_structure(FIRST, prosto);
			prosto++;
			SECOND = add_structure(SECOND, prosto);
			prosto--;
			break;
		case 4:
			FIRST = start_f(FIRST, SECOND);
			break;
		case 5:
			return 0;
		}
	} while (vib <= 5 || vib >= 1);

	_getch();
	return 0;
}

int menu_9_2()
{
	int choice2 = 0;
	system("cls");
	printf_s("\t\t\t�������� ���� ��������\n\t1 -�������� �����\n\t2 - �������� �����\n\t3 - ���������� �����\n\t4 - ���������� ������\n\t5 - �����\n");

	do
	{
		printf_s("\t������� ���� ��������: \t");
		scanf("%d%*c", &choice2);
	} while (choice2 < 1 || choice2 > 5);
	return choice2;
}


struct str *create_structure(int i)
{
	int amont = 0;
	system("cls");
	printf("������� ������ ������������ ������ %i: ", i);
	scanf_s("%d*c*", &amont);
	str *elements = NULL, *NEXT = NULL;

	for (int i = 0; i < amont; i++)
	{
		if (elements == NULL)
		{
			NEXT = new str;
			NEXT->next = NULL;
			NEXT->previus = NULL;
			NEXT->item = rand() % 1000;
			elements = NEXT;
		}
		else
		{
			NEXT = new str;
			NEXT->next = NULL;
			NEXT->item = rand() % 1000;
			NEXT->previus = elements;
			elements->next = NEXT;
			elements = NEXT;
		}
	}




	return elements;
}


int print_structure(str *FIRST, str *SECOND)
{

	int keys = 0;
	do
	{
		printf("\t������� ����������� ��������\n\t 1 - ������ ������\n\t 2 - ������ ������ : ");
		scanf("%d%*c", &keys);
	} while (keys < 1 || keys > 2);
	system("cls");
	printf("����� ��������� 1\n__________________________________________________________\n");
	printik(FIRST, keys);
	printf("����� ��������� 2\n__________________________________________________________\n");
	printik(SECOND, keys);


	system("pause");
	return 0;
}



struct str *max_element(str *element)
{
	str *step, *start;
	step = start = element;


	while (step->previus)
	{
		step = step->previus;
		if (start->item >= step->item) continue;
		else
		{
			start = step;
		}

	}

	return start;
}


struct str *start_f(str *first, str *second)
{
	str *vrem;

	if (first == NULL || second == NULL)
	{
		printf("���� �� ������");
		return NULL;
	}

	vrem = max_element(first);
	vrem->previus = second;
	second->next = vrem;


	return first;
}


struct str *add_structure(str *elements, int nomer)
{

	if (elements == NULL)
	{
		printf("���� �� ������");
		system("pause");
		return NULL;
	}
	int kolvo = 0;
	str *Next_elements;
	Next_elements = elements;
	system("cls");
	do
	{
		printf("������� ���������� ��������� ������� ���������� �������� � ������\t %d", nomer);
		scanf("%d%*c", &kolvo);
	} while (kolvo < 1);

	for (int i = 0; i < kolvo; i++)
	{
		Next_elements = new	str;
		Next_elements->item = rand() % 1000;
		Next_elements->next = NULL;
		Next_elements->previus = elements;
		elements->next = Next_elements;
		elements = Next_elements;
	}

	return elements;
}



int printik(str *spisok, int keys)
{
	int k = 1;
	if (keys == 1)
	{
		while (spisok)
		{
			printf("%d.\t ������� ����� %p\t �������� %d\t ����� ���������� %p\t ����� ������� %p\n", k, spisok, spisok->item, spisok->next, spisok->previus);
			spisok = spisok->previus;
			k++;
		}
		return 0;
	}
	else
	{
		spisok->next = NULL;
		while (spisok->previus)
		{
			spisok = spisok->previus;
			k++;
		}
		do
		{
			printf("������� ����� %p\t �������� %d\t ����� ���������� %p\t ����� ������� %p\n", spisok, spisok->item, spisok->next, spisok->previus);
			spisok = spisok->next;
		} while (spisok);
	}

}