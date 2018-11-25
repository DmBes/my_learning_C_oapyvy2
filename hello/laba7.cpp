#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <process.h>
#include <io.h>
#include <conio.h>
#include <Windows.h>

/*
2. Каждая заглавная буква заменяется строчной буквой, пара букв "ки";
меняется на "ю".
*/


int output_on_display(int *); //Function to display screen requests
int forming_string_and_wr(char *, FILE *);
int reading_and_print_str(char *, FILE *);
int encrypt_and_write_str(char *, FILE *, int *, int *);
int decrypt_and_write_str(char *, FILE *, int *, int *);

int main3(int argc, char *argv[])
{
	int choice = 0;  //User choice
	char *memory = new char[300];
	FILE *my_file = 0;
	int *position_words = (int *)(calloc(300, sizeof(int)));
	int *replace_words = (int *)(calloc(300, sizeof(int)));




	setlocale(LC_CTYPE, "rus");

	//SetConsoleOutputCP(1251);

	while (choice < 1 || choice > 5)
	{
	r1:		output_on_display(&choice);
	}

	switch (choice)
	{
	case 1:
		forming_string_and_wr(memory, my_file);
		goto r1;
	case 2:
		reading_and_print_str(memory, my_file);
		goto r1;
	case 3:
		encrypt_and_write_str(memory, my_file, position_words, replace_words);
		goto r1;
	case 4:
		decrypt_and_write_str(memory, my_file, position_words, replace_words);
		goto r1;
		
	case 5:
		return 0;

	default:
		break;
	}


	printf_s("\na = %d", choice);

	_getch;
	delete(memory);
	free(position_words);
	free(replace_words);

	return 0;
}


int output_on_display(int *a)
{
	system("cls");
	puts("Нажмите подходящий вариант для запуска программы");
	puts("1 – Сформировать с клавиатуры строку и записать в файл (строка может содержать пробелы); ");
	puts("2 – Считать строку из файла и распечатать");
	puts("3 - Зашифровать строку и записать в файл");
	puts("4 – Расшифровать строку и записать в файл;");
	puts("5 – Выход.");
	printf_s("Введите ваш вариант :");
	scanf_s("%d%*c", a);
	_getch;


	return 0;
}

int forming_string_and_wr(char * user_string, FILE *my_f)
{
	if ((my_f = fopen("d:\\test1.txt", "w")) == NULL) { printf("Cannot open file.\n"); }
	puts("Введите вашу строку");
	puts("**********************************************************");
	fflush(stdin);
	gets_s(user_string, 300); //	catch zero
	//gets_s(user_string, 300);

	fputs(user_string, my_f);

	*user_string = 0;
	fclose(my_f);
	return 0;
}


int reading_and_print_str(char * user_string, FILE *my_f)
{

	if ((my_f = fopen("d:\\test1.txt", "r")) == NULL) { printf("Cannot open file.\n"); exit(1); }

	fgets(user_string, 300, my_f);
	printf(user_string);
	_getch();
	*user_string = 0;

	fclose(my_f);
	return 0;
}


int encrypt_and_write_str(char * user_string, FILE *my_f, int *words, int *pos_ki)
{

	char str[] = "ka";
	char replece = 'e';



	if ((my_f = fopen("d:\\test1.txt", "r")) == NULL) { printf("Cannot open file.\n"); exit(1); }
	fgets(user_string, 300, my_f);
	fclose(my_f);
	if ((my_f = fopen("d:\\test1.txt", "w")) == NULL) { printf("Cannot open file.\n"); exit(1); }

	for (int begin_words = 0; begin_words < strlen(user_string); begin_words++)// index text lower
	{
		words[begin_words] = isupper(user_string[begin_words]);
		if (words[begin_words])
		{
			char c;
			c = user_string[begin_words];
			user_string[begin_words] = c + 32;

		}

	}




	for (int i = 0, j = 0; i < strlen(user_string); i++, j++) // index text replace
	{
		if (user_string[i] == str[0] && user_string[i + 1] == str[1])
		{
			fputc(replece, my_f);
			pos_ki[j] = 1;
			i++;

		}
		else
		{
			fputc(user_string[i], my_f);
		}
		printf("\n%d ", pos_ki[i]);
	}
	
	fclose(my_f);
	*user_string = 0;
	printf_s("Your text encrypt");
	_getch();
	return 0;
}

int decrypt_and_write_str(char * user_string, FILE *my_f, int *words, int *pos_ki)
{
	char str[] = "ka";
	char replece = 'e';
	//char blin[300];


	if ((my_f = fopen("d:\\test1.txt", "r")) == NULL) { printf("Cannot open file.\n"); exit(1); }
	fgets(user_string, 300, my_f);
	fclose(my_f);
	if ((my_f = fopen("d:\\test1.txt", "w")) == NULL) { printf("Cannot open file.\n"); exit(1); }
	


	for (int i = 0, xz = 0; i < strlen(user_string); i++, xz++) // index text replace
	{
		if (pos_ki[i])
		{
			for (int kkk = 0; kkk < 2; kkk++)
			{
				fputc(str[kkk], my_f);
			}

		}
		else
		{
			fputc(user_string[i], my_f);
		}
			

				
			

			

		}
	fclose(my_f);
	



	if ((my_f = fopen("d:\\test1.txt", "r")) == NULL) { printf("Cannot open file.\n"); exit(1); }
	fgets(user_string, 300, my_f);
	fclose(my_f);
	if ((my_f = fopen("d:\\test1.txt", "w")) == NULL) { printf("Cannot open file.\n"); exit(1); }

	puts(user_string);

	for (int begin_words = 0; begin_words < strlen(user_string); begin_words++)// index text lower
	{

		if (words[begin_words])
		{
			char c;
			c = user_string[begin_words];
			user_string[begin_words] = c - 32;

		}

	}
	fputs(user_string, my_f);

	fclose(my_f);
	for (int beg = 0; beg < 300; beg++)
	{
		words[beg] = 0;
		pos_ki[beg] = 0;
	}

	return 0;
	
}