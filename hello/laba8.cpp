#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <io.h>
#include <conio.h>
#include <process.h>
#include <string.h>

/*
В справочной автовокзала хранится расписание движения
автобусов. Для каждого рейсов указаны: номер рейса; тип
автобуса; пункт назначения; время отправления; время прибытия
на конечный пункт. ВЫВЕСТИ ИНФОРМАЦИЮ О РЕЙСАХ,
КОТОРЫМИ МОЖНО ВОСПОЛЬЗОВАТЬСЯ ДЛЯ ПРИБЫТИЯ
В ПУНКТ НАЗНАЧЕНИЯ РАНЬШЕ ЗАДАННОГО ВРЕМЕНИ
(отсортировать по типу автобуса).
*/

// Создание структур. Структура Time_departure и Time_arrival вложена в основную структуру
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

// Обьявление всех используемых функций!
int menu(int *);
int create();
int read_file();
int correction_of_records(int *);
int item_correction(int *);
int item_delete(int *);
int item_add(int *);
int menu_correction(int *);
int filtr();


//Главная функция
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
		filtr();
		goto m1;
	case 5:
		break;
	default:
		break;
	}



	if (remove("D:\\bus.txt") == 0) printf("File delete");
	else
	{
		printf("File don't delete");
	}
	_getch();
	return 0;
}


int menu(int *num)
{
	system("cls");
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

int create() // Функция по созданию файоа на жестком диске. Функция открывает с мгновенным
			 //закрытием файла
{
	FILE *user_file;
	user_file = fopen("d:\\bus.txt", "w");
	fclose(user_file);
	printf("New file is create!");
	_getch();


	return 0;
}

// Функция по чтению файла. Открывает файл в режиме чтения.
int read_file()
{
	Bus_Station autobus[30];
	FILE *bus;

	if ((bus = fopen("d:\\bus.txt", "rb")) == NULL) {
		printf("File don't create"); // В случае отстсвие файла возращает -1
		_getch();
		system("csl");
		return -1;
	}
	printf("Number of race|\t Type Race|\t Destinition|\t Time Departure|\t Time Arival| \n");
	while (fread(autobus, sizeof(Bus_Station), 1, bus) != NULL) {
		
		printf("\t%d\t %s\t\t %s \t\t\t%d:%d \t\t%d:%d \n", autobus->number_of_race, autobus->bus_type , autobus->destinition, autobus->time_d.departure_hour, autobus->time_d.departure_minute, autobus->time_a.hour_arrival, autobus->time_a.minute_arrival);

	}
	system("pause");
	fclose(bus);
	return 0;
}


int correction_of_records(int * choice)
{
	FILE*bus;
	Bus_Station autobus[30];
	int kol_vo = 0;

	if ((bus = fopen("D:\\bus.txt", "r")) == NULL)
	{
		printf("File don't create!!! ");
		exit(1);
		return -1;
	}

	while (fread(autobus, sizeof(Bus_Station), 1, bus) != NULL) {

		kol_vo ++;
	}

	fclose(bus);
	fflush(stdin);

m2:	menu_correction(choice);


	switch (*choice)
	{
	case 1:
		item_correction(&kol_vo);

		goto m2;
	case 2:
		item_add(&kol_vo);

		goto m2;
	case 3:
		item_delete(&kol_vo);

		goto m2;

	default:
		system("cls");
		break;
	}



	return 0;

}


int filtr()
{
	FILE*bus;
	char dest[30];
	int hour;
	int minute;
	Bus_Station autobus[30];
	read_file();
	if ((bus = fopen("D:\\bus.txt", "r")) == NULL)
	{
		printf("File don't create!!! ");
		exit(1);
		return -1;
	}


	printf_s("Введите город назначения: ");
	fflush(stdin);
	gets_s(dest);
	printf_s("Час прибытия: ");
	fflush(stdin);
	scanf_s("%d%*c", &hour);
	printf_s("Минуту прибытия: ");
	scanf_s("%d%*c", &minute);

	while (fread(autobus, sizeof(Bus_Station), 1, bus) != NULL) {
		

		

		if (!strcmp(autobus->destinition , dest)) {
			if (autobus[0].time_a.hour_arrival < hour) {
				printf("\t%d\t %s\t\t %s \t\t\t%d:%d \t\t%d:%d \n", autobus->number_of_race, autobus->bus_type, autobus->destinition,
					autobus->time_d.departure_hour, autobus->time_d.departure_minute, autobus->time_a.hour_arrival,
					autobus->time_a.minute_arrival);


			}
			else if (autobus[0].time_a.hour_arrival == hour)
			{
				if(autobus[0].time_a.minute_arrival <= minute){
					printf("\t%d\t %s\t\t %s \t\t\t%d:%d \t\t%d:%d \n", autobus->number_of_race, autobus->bus_type, autobus->destinition,
						autobus->time_d.departure_hour, autobus->time_d.departure_minute, autobus->time_a.hour_arrival,
						autobus->time_a.minute_arrival);

				}
			}
		
		}

	}

	return 0;
}


//Функция корректировки строк
int item_correction(int *kolvo)
{
	int choice_delete = 0;
	system("cls");
	read_file();
	printf_s("На текущий момент в базе присутствует %d записей\n", *kolvo);
	do
	{
		printf_s("Какую из записей вы хотите отредактировать? от 1 до %d: ", *kolvo);
		scanf_s("%d%*c", &choice_delete);
	} while (choice_delete < 1 || choice_delete > *kolvo);

	FILE*bus_read;
	FILE*bus_write;

	Bus_Station autobus_read[30];
	//Bus_Station autobus_write[30];
	int cikl = 0;

	bus_read = fopen("D:\\bus.txt", "rb");
	bus_write = fopen("D:\\bus_vrem.txt", "wb");


	while (fread(autobus_read, sizeof(Bus_Station), 1, bus_read) != NULL) {

		if (cikl + 1 != choice_delete) fwrite(autobus_read, sizeof(Bus_Station), 1, bus_write);
		else
		{
			printf_s("Укажите номер рейса: ");
			fflush(stdin);
			scanf_s("%d%*c", &autobus_read->number_of_race);
			printf_s("тип автобуса; : ");
			fflush(stdin);
			gets_s(autobus_read->bus_type);
			printf_s("пункт назначения: ");
			fflush(stdin);
			gets_s(autobus_read->destinition);
			do {
				printf_s("час отправления (1-23): ");
				fflush(stdin);
				scanf_s("%d%*c", &autobus_read->time_d.departure_hour);

			} while (autobus_read->time_d.departure_hour > 23 || autobus_read->time_d.departure_hour < 0);


			do {
				printf_s("Минуту отправления (1-59): ");
				fflush(stdin);
				scanf_s("%d%*c", &autobus_read->time_d.departure_minute);
			} while (autobus_read->time_d.departure_minute > 59 || autobus_read->time_d.departure_minute < 0);

			do {
				printf_s("час прибытия (1-23): ");
				fflush(stdin);
				scanf_s("%d%*c", &autobus_read->time_a.hour_arrival);
			} while (autobus_read->time_a.hour_arrival > 23 || autobus_read->time_a.hour_arrival < 0);

			do {
				printf_s("Минуту прибытия (1-59): ");
				fflush(stdin);
				scanf_s("%d%*c", &autobus_read->time_a.minute_arrival);
			} while (autobus_read->time_a.minute_arrival > 59 || autobus_read->time_a.minute_arrival < 0);
			fwrite(autobus_read, sizeof(Bus_Station), 1, bus_write);
		}
		cikl++;

	}

	fclose(bus_read);
	fclose(bus_write);


	bus_read = fopen("D:\\bus_vrem.txt", "rb");
	bus_write = fopen("D:\\bus.txt", "wb");


	while (fread(autobus_read, sizeof(Bus_Station), 1, bus_read) != NULL) {

		fwrite(autobus_read, sizeof(Bus_Station), 1, bus_write);


	}

	fclose(bus_read);
	fclose(bus_write);
	remove("D:\\bus_vrem.txt");

	return 0;
}


// Функция удаления строк
int item_delete(int *kolvo)
{
	int choice_delete = 0;
	system("cls");
	read_file();
	printf_s("На текущий момент в базе присутствует %d записей\n", *kolvo);
	do
	{
		printf_s("Вы желаете удалить какую из записей вы хотите удалить? от 1 до %d: ", *kolvo);
		scanf_s("%d%*c", &choice_delete);
	} while (choice_delete < 1 || choice_delete > *kolvo);
	
	FILE*bus_read;
	FILE*bus_write;

	Bus_Station autobus_read[30];
	Bus_Station autobus_write[30];
	int cikl = 0;

	bus_read = fopen("D:\\bus.txt", "rb");
	bus_write = fopen("D:\\bus_vrem.txt", "wb");
	

	while (fread(autobus_read, sizeof(Bus_Station), 1, bus_read) != NULL) {

		if (cikl + 1 != choice_delete) fwrite(autobus_read, sizeof(Bus_Station), 1, bus_write);
		cikl++;
		
	}

	fclose(bus_read);
	fclose(bus_write);


	bus_read = fopen("D:\\bus_vrem.txt", "rb");
	bus_write = fopen("D:\\bus.txt", "wb");


	while (fread(autobus_read, sizeof(Bus_Station), 1, bus_read) != NULL) {

		fwrite(autobus_read, sizeof(Bus_Station), 1, bus_write);


	}

	fclose(bus_read);
	fclose(bus_write);
	remove("D:\\bus_vrem.txt");




	_getch();
	return 0;
}


// Функция по добавлению строк
int item_add(int *kolvo)
{
	int i= 0, number_of_element = 0;
	printf_s("На текущий момент в базе содежится информация о %d элементах\n", *kolvo);
	printf_s("Укажите сколько элементов вы хотите добавить (приминаемые значения от 1 до ...: ");
	do {
		scanf("%d%*c", &number_of_element);
	} while (number_of_element < 1);


	int stop;
	FILE *files;
	//Bus_Station *param;
	Bus_Station param[20];
	//param = new Bus_Station[i];


	

	if ((files = fopen("d:\\bus.txt", "a+b")) == NULL) {
		printf("Cannot open file.\n");
		return -1;
	}

	//for (int i = 0; i < number_of_element; i++)
	//{
	//	printf_s("Номер записи добавленной %d\n", i + 1);
	//	printf_s("Укажите номер рейса: ");
	//	fflush(stdin);
	//	scanf_s("%d%*c", &param[i].number_of_race);
	//	printf_s("тип автобуса; : ");
	//	fflush(stdin);
	//	fgets(param[i].bus_type, 20, stdin);
	//	printf_s("пункт назначения: ");
	//	fflush(stdin);
	//	fgets(param[i].destinition, 20, stdin);
	//	do {
	//		printf_s("час отправления (1-23): ");
	//		fflush(stdin);
	//		scanf_s("%d%*c", &param[i].time_d.departure_hour);

	//	} while (param[i].time_d.departure_hour > 23 || param[i].time_d.departure_hour < 0);


	//	do {
	//		printf_s("Минуту отправления (1-59): ");
	//		fflush(stdin);
	//		scanf_s("%d%*c", &param[i].time_d.departure_minute);
	//	} while (param[i].time_d.departure_minute > 59 || param[i].time_d.departure_minute < 0);

	//	do {
	//		printf_s("час прибытия (1-23): ");
	//		fflush(stdin);
	//		scanf_s("%d%*c", &param[i].time_a.hour_arrival);
	//	} while (param[i].time_a.hour_arrival > 23 || param[i].time_a.hour_arrival < 0);

	//	do {
	//		printf_s("Минуту прибытия (1-59): ");
	//		fflush(stdin);
	//		scanf_s("%d%*c", &param[i].time_a.minute_arrival);
	//	} while (param[i].time_a.minute_arrival > 59 || param[i].time_a.minute_arrival < 0);
	//	fwrite(param, sizeof(Bus_Station), number_of_element, files);
	//}

	
	for (int i = 0; i < number_of_element; i++) {
		//system("cls");
		printf_s("Номер записи добавленной %d\n", i + 1);
		printf_s("Укажите номер рейса: ");
		fflush(stdin);
		scanf_s("%d%*c", &param->number_of_race);
		//printf_s("тип автобуса; : ");
		//fflush(stdin);
		//fgets(param->bus_type, 20, stdin);
		//printf_s("пункт назначения: ");
		//fflush(stdin);
		//fgets(param->destinition, 20, stdin);
		printf_s("тип автобуса; : ");
		fflush(stdin);
		gets_s(param->bus_type);
		printf_s("пункт назначения: ");
		fflush(stdin);
		gets_s(param->destinition);
		do {
			printf_s("час отправления (1-23): ");
			fflush(stdin);
			scanf_s("%d%*c", &param->time_d.departure_hour);

		} while (param->time_d.departure_hour > 23 || param->time_d.departure_hour < 0);


		do {
			printf_s("Минуту отправления (1-59): ");
			fflush(stdin);
			scanf_s("%d%*c", &param->time_d.departure_minute);
		} while (param->time_d.departure_minute > 59 || param->time_d.departure_minute < 0);

		do {
			printf_s("час прибытия (1-23): ");
			fflush(stdin);
			scanf_s("%d%*c", &param->time_a.hour_arrival);
		} while (param->time_a.hour_arrival > 23 || param->time_a.hour_arrival < 0);

		do {
			printf_s("Минуту прибытия (1-59): ");
			fflush(stdin);
			scanf_s("%d%*c", &param->time_a.minute_arrival);
		} while (param->time_a.minute_arrival > 59 || param->time_a.minute_arrival < 0);
		fwrite(param, sizeof(Bus_Station), 1, files);
	}



	fclose(files);


	return 0;
}


//Функция отображения меню по выбору пунктов, добавления и редактирования, удаления (закончена)
int menu_correction(int *choice) {
	system("cls");

	printf("The amount of previously entered data \n");
	puts("1 - Correction note");
	puts("2 - Add note");
	puts("3 - Delete note");
	puts("4 - Exit");
	do
	{
		printf_s("Choice you variant: ");
		scanf_s("%d%*c", choice);
	} while (*choice < 1 || *choice > 4);

	system("cls");
	return 0;
}



