#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <process.h>
#include <conio.h>



/*
�������� ��������� �� ��������, ���������, ���������� � ������� ������������ ������ ��� ����������������� ��������� ������ (���� �/��� �������).
>>>>>>>>>>>>>>>>>>>>2. ������� ������ �� ��������� ����� ����� � ������� �� ���� ������ � ������� �������.






*/


struct lin_spis
{
	int number;
	struct lin_spis *previus_number;
};


int menu23(int *);
struct lin_spis *create_spisok(struct lin_spis *);
struct lin_spis *add_spisok(struct lin_spis *);
int print_spisok(struct lin_spis *);
struct lin_spis *start(struct lin_spis *);
//int delete_spisok(int);

int main654(int argc, char *argv[])
{

	int znac = 0;
	int *choice = &znac;

	lin_spis *my_spis = NULL;
	setlocale(LC_CTYPE, "rus");
	srand(time(NULL));
	do
	{
		menu23(choice);
		system("cls");
		switch (*choice)
		{
		case 1:

			my_spis = create_spisok(my_spis);
			break;
		case 2:
			print_spisok(my_spis);
			_getch();
			break;
		case 3:
			my_spis = add_spisok(my_spis);
			break;
		case 4:

			my_spis = start(my_spis);
			break;
		case 5:
			return 0;
		}
	} while (*choice != 5);

	_getch();
	return 0;
}


struct lin_spis *create_spisok(struct lin_spis *my_spis)
{
	int kolvo;
	if (my_spis != NULL)
	{
		printf_s("���� ������");
		_getch();

		return my_spis;
	};

	printf_s("������� ���������� ��������� �����: ");
	scanf("%d%*c", &kolvo);
	lin_spis *elements = NULL, *vrem = NULL;
	for (int i = 0; i < kolvo; i++)
	{
		vrem = elements;
		elements = new lin_spis;
		elements->previus_number = vrem;
		elements->number = rand() % 100;
	}
	return elements;
}

int print_spisok(struct lin_spis *spisok)
{
	printf_s("�������� ������\n");

	while (spisok)
	{
		printf_s("������: %p ��������: %d   ������ ����� %p\n", spisok, spisok->number, spisok->previus_number);
		spisok = spisok->previus_number;
	}
	return 0;
}

struct lin_spis *start(struct lin_spis *my_spis)
{

	struct lin_spis *shagvpered, *verh;
	struct lin_spis *ydal;






	while (my_spis)					//(my_spis->number % 2 == 0 && my_spis != NULL)
	{
		if (my_spis->number % 2 == 0)
		{
			my_spis = my_spis->previus_number;
			continue;
		}
		break;
	}



	if (my_spis == NULL) {
		printf_s("���� ������� ������");
		return my_spis;

	}

	print_spisok(my_spis);
	shagvpered = my_spis;
	verh = my_spis;

	printf_s("\n_____________________________________________________\n");



	do
	{
		shagvpered = shagvpered->previus_number;

		if (shagvpered->number % 2 == 0 && shagvpered != NULL)
		{
			//ydal = vrem;
			verh->previus_number = shagvpered->previus_number;
			//verh = verh->previus_number;
			//delete ydal;
			//continue;
		}
		else {
			verh->previus_number = shagvpered;
			verh = verh->previus_number;
		}
		//printf_s("������: %p ��������: %d   ������ ����� %p\n", my_spis, my_spis->number, my_spis->previus_number);
	} while (shagvpered->previus_number != NULL);

	printf_s("\n_____________________________________________________\n");

	//my_spis = verh->previus_number;
	print_spisok(my_spis);
	_getch();
	system("pause");
	return my_spis;

}


int menu23(int *choice)
{
	system("cls");
	printf_s("\t\t\t�������� ���� ��������\n\t1 -�������� �����\n\t2 - �������� �����\n\t3 - ���������� �����\n\t4 - ���������� ������\n\t5 - �����\n");
	do
	{
		printf_s("\t������� ���� ��������: \t");
		scanf("%d%*c", choice);
	} while (*choice < 1 || *choice > 5);
	return 0;
}


struct lin_spis *add_spisok(struct lin_spis *my_spis)
{
	int kolvo;
	if (my_spis == NULL)
	{
		puts("������ �������� �� ������, �� ���������� �������������");
		my_spis = create_spisok(my_spis);
		_getch();

		return my_spis;
	};

	printf_s("������� ����� ���������� ��������� ����� ���������� ��������: ");
	scanf("%d%*c", &kolvo);
	lin_spis *elements = my_spis, *vrem = my_spis;
	for (int i = 0; i < kolvo; i++)
	{
		vrem = elements;
		elements = new lin_spis;
		elements->previus_number = vrem;
		elements->number = rand() % 100;
	}
	return elements;
}



