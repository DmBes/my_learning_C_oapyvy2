#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <process.h>
#include <conio.h>



/*
Написать программу по созданию, просмотру, добавлению и решению поставленной задачи для однонаправленного линейного списка (стек и/или очередь).
>>>>>>>>>>>>>>>>>>>>2. Создать список из случайных целых чисел и удалить из него записи с четными числами.




ЗАДАНИЕ 2. Деревья
Разработать проект для обработки дерева поиска, каждый элемент которого содержит целочисленный ключ и строку текста, содержащую, например, ФИО и номер паспорта (ввод исходной информации рекомендуется записать в файл). В программе должны быть реализованы следующие возможности:
–  создание дерева;
–  добавление новой записи;
–  поиск информации по заданному ключу;
–  удаление информации с заданным ключом;
–  вывод информации;
–  решение индивидуального задания;
–  освобождение памяти при выходе из программы.

>>>>>>>>>>>>>>>>2. Подсчитать число листьев в дереве.

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
struct lin_spis *start (struct lin_spis *);
//int delete_spisok(int);

int mainssa(int argc, char *argv[])
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
			start(my_spis);
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
		printf_s("Файл создан");
		_getch();
		
		return my_spis;
	};

	printf_s("Введите количество элементов стека: ");
	scanf("%d%*c", &kolvo);
	lin_spis *elements  = NULL, *vrem = NULL;
	for (int i = 0; i < kolvo; i++)
	{
		vrem = elements;
		elements = new lin_spis;
		elements->previus_number = vrem;
		elements->number = rand()%100;
	}
	return elements;
}

int print_spisok(struct lin_spis *spisok)
{
	printf_s("Исходный список\n");

	while (spisok)
	{
		printf_s("адресс: %p Значение: %d   Адресс новый %p\n", spisok, spisok->number, spisok->previus_number);
		spisok = spisok->previus_number;
	}
	return 0;
}

struct lin_spis *start (struct lin_spis *my_spis)
{

	struct lin_spis *vrem, *verh;
	struct lin_spis *ydal;



	while (my_spis->number % 2 == 0 && my_spis != NULL)
	{
		ydal = my_spis;
		my_spis = my_spis->previus_number;
		delete ydal;
	}
	if (my_spis == NULL) {
		printf_s("Нету верного ответа");
		return my_spis;

	}

	print_spisok(my_spis);
	vrem = my_spis;
	verh = my_spis;
	
	printf_s("\n_____________________________________________________\n");
	
	
	
	do
	{
		vrem = vrem->previus_number;

		if (vrem->number % 2 == 0 || my_spis == NULL)
		{
			ydal = verh;
			verh->previus_number = vrem->previus_number;
			verh = verh->previus_number;
			delete ydal;
			continue;
		}
		//verh->previus_number = vrem;
		//verh = verh->previus_number;
		printf_s("адресс: %p Значение: %d   Адресс новый %p\n", my_spis, my_spis->number, my_spis->previus_number);
	} while (vrem->previus_number != NULL);

	
	//my_spis = verh->previus_number;
	return my_spis;

}


int menu23(int *choice) 
{
	system("cls");
	printf_s("\t\t\tВыберете свое значение\n\t1 -создание стека\n\t2 - просмотр стека\n\t3 - добавление стека\n\t4 - выполнение задачи\n\t5 - выход\n");
	do
	{
		printf_s("\tВведите свое значение: \t");
		scanf("%d%*c", choice);
	} while (*choice < 1 || *choice > 5);
	return 0;
}


struct lin_spis *add_spisok(struct lin_spis *my_spis)
{
	int kolvo;
	if (my_spis == NULL)
	{
		puts("Список значений не создан, он создасться автоматически");
		my_spis = create_spisok(my_spis);
		_getch();

		return my_spis;
	};

	printf_s("Введите какое количество элементов стека необходимо добавить: ");
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



