#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <process.h>
#include <io.h>
#include <conio.h>




int output_on_display(int *); //Function to display screen requests
int forming_string_and_wr(char *, FILE *);
int reading_and_print_str(char *, FILE *);
int encrypt_and_write_str(char *);
int decrypt_and_write_str(char *);

int main(int argc, char *argv[]) 
{
	int choice = 0;  //User choice
	char *memory = new char[300];
	FILE *my_file = 0;



	setlocale(LC_CTYPE, "rus");

	while (choice < 1 || choice > 5)
	{
		output_on_display(&choice);
	}
	
	switch (choice)
	{
	case 1:
		forming_string_and_wr(memory, my_file);
		break;
	case 2:
		reading_and_print_str(memory, my_file);
		break;
	case 3:
		encrypt_and_write_str(memory);
		break;
	case 4:
		decrypt_and_write_str(memory);
		break;
	case 5:
		return 0;
		break;

	default:
		break;
	}


	printf_s("\na = %d", choice);

	_getch;
	return 0;
}


int output_on_display(int *a)
{
	system("cls");
	puts("Ќажмите подход€щий вариант дл€ запуска программы");
	puts("1 Ц —формировать с клавиатуры строку и записать в файл (строка может содержать пробелы); ");
	puts("2 Ц —читать строку из файла и распечатать");
	puts("3 - «ашифровать строку и записать в файл");
	puts("4 Ц –асшифровать строку и записать в файл;");
	puts("5 Ц ¬ыход.");
	printf_s("¬ведите ваш вариант :");
	scanf_s("%d", a);
	_getch;


	return 0;
}

int forming_string_and_wr(char * user_string, FILE *my_f)
{
	if ((my_f = fopen("d:\\test1.txt", "w")) == NULL) {printf("Cannot open file.\n"); exit(1);}
	puts("¬ведите вашу строку");
	puts("**********************************************************");
	fflush(stdin);
	gets_s(user_string, 300); //	catch zero
	gets_s(user_string, 300);
	
	fputs(user_string, my_f);
	*user_string = 0;
	fclose(my_f);
	return 0;
}


int reading_and_print_str(char * user_string, FILE *my_f)
{
	
	if ((my_f = fopen("d:\\test1.txt", "r")) == NULL) {printf("Cannot open file.\n"); exit(1);}

	fgets(user_string, 300, my_f);
	printf(user_string);
	*user_string = 0;

	_getch();

	return 0;
}


int encrypt_and_write_str(char * user_string)
{
	
	return 0;
}

int decrypt_and_write_str(char * user_string)
{
	
	return 0;
}
