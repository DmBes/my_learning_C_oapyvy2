#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <process.h>
#include <conio.h>



/*
ƒвунаправленные списки
Ќаписать программу по созданию, просмотру, добавлению и решению поставленной задачи дл€ двунаправленного линейного списка.
>>>>>>>>>>>2. —оздать два списка из случайных целых чисел. ¬ первом найти максимальный элемент и за ним вставить элементы второго.


*/

struct str
{
	int number;
	struct str *previus;
	struct str *next;
};

int menu_9_2();
struct str *create_structure();
int print_structure();
struct str *add_structure();


int main1234321(int argc, char *argv[]) 
{
	int vib = 0;
	str *znac = NULL;
	setlocale(LC_CTYPE, "rus");


	do
	{
		vib = menu_9_2();
		system("cls");
		switch (vib)
		{
		case 1:

			
			break;
		case 2:
			
			_getch();
			break;
		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			return 0;
		}
	} while (vib != 5);

	_getch();
	return 0;
}

int menu_9_2()
{
	int choice = 0;
	system("cls");
	printf_s("\t\t\t¬ыберете свое значение\n\t1 -создание стека\n\t2 - просмотр стека\n\t3 - добавление стека\n\t4 - выполнение задачи\n\t5 - выход\n");
	
	do
	{
		printf_s("\t¬ведите свое значение: \t");
		scanf("%d%*c", choice);
	} while (choice < 1 || choice > 5);
	return choice;
}

struct str *create_structure() 
{
	str *tmp_previos = NULL, *tmp_next = NULL;


	return 0;
}
