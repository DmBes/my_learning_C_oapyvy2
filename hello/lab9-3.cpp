#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <locale.h>

struct three
{
	int key;
	char *FIO[50];
	char *PASSPORT[10];
	three *left, *right;
};

three create_three();
three add_three();
int find_key();
three delete_key();
int print_three();
int summ_leaf();
int menu_three();



/*
«јƒјЌ»≈ 2. ƒеревь€
–азработать проект дл€ обработки дерева поиска, каждый элемент которого содержит целочисленный ключ и строку текста, содержащую, например, ‘»ќ и номер паспорта (ввод исходной информации рекомендуетс€ записать в файл). ¬ программе должны быть реализованы следующие возможности:
Ц  создание дерева;
Ц  добавление новой записи;
Ц  поиск информации по заданному ключу;
Ц  удаление информации с заданным ключом;
Ц  вывод информации;
Ц  решение индивидуального задани€;
Ц  освобождение пам€ти при выходе из программы.

>>>>>>>>>>>>>>>>2. ѕодсчитать число листьев в дереве.

*/

int main(int argc, char *argv[])
{
	int choice = 0;
	three *lipa;
	lipa = NULL;

	do
	{
		choice = menu_three();
		system("cls");
		switch (choice)
		{
		case 1:
			create_three();

			break;
		case 2:
			add_three();
			break;
		case 3:
			find_key();
			break;
		case 4:
			delete_key();
			break;
		case 5:
			print_three();
			break;
		case 6:
			summ_leaf();
			break;
		case 7:
			return 0;

		}
	} while (choice <= 7 || choice >= 1);


	return 0;
}


int menu_three() 
{
	int choice2 = 0;
	system("cls");
	printf_s("\t\t\t¬ыберете свое значение\n\t1 -создание дерева\n\t2 - добавление новой записи\n\t3 - поиск информации по заданному ключу\
\n\t4 - удаление информации с заданным ключом\n\t5 - вывод информации\n\t6 -решение индивидуального задани€\n\t7 - выход\n");

	do
	{
		printf_s("\t¬ведите свое значение: \t");
		scanf("%d%*c", &choice2);
	} while (choice2 < 1 || choice2 > 7);
	return choice2;
}




three create_three() 
{

	return;
}
three add_three() 
{
	return;
}


int find_key() 
{

	return;
}



three delete_key() 
{
	
	return;
}
int print_three() 
{
	
	return 0;
}

int summ_leaf() 
{

	return;
}
int menu_three()
{

	return 0;
}