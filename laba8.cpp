#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <io.h>
#include <conio.h>
#include <process.h>

/*
В справочной автовокзала хранится расписание движения
автобусов. Для каждого рейсов указаны: номер рейса; тип
автобуса; пункт назначения; время отправления; время прибытия
на конечный пункт. ВЫВЕСТИ ИНФОРМАЦИЮ О РЕЙСАХ,
КОТОРЫМИ МОЖНО ВОСПОЛЬЗОВАТЬСЯ ДЛЯ ПРИБЫТИЯ
В ПУНКТ НАЗНАЧЕНИЯ РАНЬШЕ ЗАДАННОГО ВРЕМЕНИ
(отсортировать по типу автобуса).
*/
struct Time_departure
{
	int departure_hour;
	int departure_minute;
};
struct Time_arrival
{
	int hour_arrival;
	int minute_arrival;
};
struct Bus_Station
{
	int number_of_race;
	char bus_type[20];
	char destinition[30];
	Time_departure time_d;
	Time_arrival time_a;


};

int menu(int *);
int create();
int read_file();
int correction_of_records(int *);
int item_correction();
int item_delete();
int item_add();
int menu_correction(int *);
int filtr();


int main(int argc, char *argv[]) 
{

	int user_choice, user_correction_choice = 0;

	setlocale(LC_CTYPE, "rus");



m1:	menu(&user_choice);
	switch (user_choice)
	{
	case 1:
		create();
		goto m1;
	case 2:
		read_file();
		goto m1;
	case 3:
		correction_of_records(&user_correction_choice);
		goto m1;
	case 4:

		goto m1;
	case 5:
		return 0;
	default:
		break;
	}


	_getch();
	return 0;
}


int menu(int *num) 
{
	puts("Choice you varint");
	puts("1 - Create new file");
	puts("2 - View file");
	puts("3 - File correction");
	puts("4 - Run task");
	puts("5 - Exit");

	do
	{
		printf_s("Choice you variant: ");
		scanf_s("%d%*c", num);
	} while (*num < 1 || *num > 5);

	system("cls");
	return 0;
}

int create() 
{
	FILE *user_file;
	user_file = fopen("d:\\bus.txt", "w");
	fclose(user_file);
	printf("New file is create!");
	_getch();

	
	return 0;
}

int read_file()
{
	FILE *bus;
	
	if ((bus = fopen("d:\\bus.txt", "r")) == NULL) {
		printf("File don't create");
		_getch();
		return 0;
	}


	return 0;
}


int correction_of_records(int * choice) 
{
	FILE*bus;
	if ((bus = fopen("D:\\bus.txt", "r+b"))= NULL)
	{
		printf("File don't create!!! ");
		return 0;
	}

	fflush(stdin);

m2:	menu_correction(choice);


	switch (*choice)
	{
	case 1:
		item_correction();

		goto m2;
	case 2:
		item_add();

		goto m2;
	case 3:
		item_delete();

		goto m2;

	default:
		system("cls");
		break;
	}

	//fclose(bus);

	return 0;

}


int filtr()
{

	return 0;
}


//Функция корректировки строк
int item_correction()
{


	return 0;
}


// Функция удаления строк
int item_delete()
{

	return 0;
}


// Функция по добавлению строк
int item_add() 
{
	int i = 0;
	char stop;
	Bus_Station param[30];

	do {
		printf_s("Укажите номер рейса: ");
		fflush(stdin);
		scanf_s("%d%*c", &param->number_of_race);
		printf_s("тип автобуса; : ");
		fflush(stdin);
		fgets(param->bus_type, 20, stdin);
		printf_s("пункт назначения: ");
		fflush(stdin);
		fgets(param->destinition, 20, stdin);
		printf_s("час отправления (1-23): ");
		fflush(stdin);
		scanf_s("%d%*c", &param->time_d.departure_hour);
		printf_s("Минуту отправления (1-59): ");
		fflush(stdin);
		scanf_s("%d%*c", &param->time_d.departure_minute);
		printf_s("час прибытия (1-23): ");
		fflush(stdin);
		scanf_s("%d%*c", &param->time_a.hour_arrival);
		printf_s("Минуту прибытия (1-59): ");
		scanf_s("%d%*c", &param->time_a.hour_arrival);
		fflush(stdin);
		i++;
		puts("прекратить работу?[y/n]");
		scanf("%c", &stop);


	} while (stop == 'n');


	return 0;
}


//Функция отображения меню по выбору пунктов, добавления и редактирования, удаления (закончена)
int menu_correction(int *choice) {
	system("cls");

	printf("The amount of previously entered data \n");
	puts("1 - change bus schedule entry");
	puts("2 - adding bus schedule entry");
	puts("3 - delete bus schedule entry");
	puts("4 - Exit");
	do
	{
		printf_s("Choice you variant: ");
		scanf_s("%d%*c", choice);
	} while (*choice < 1 || *choice > 4);

	system("cls");
	return 0;
}