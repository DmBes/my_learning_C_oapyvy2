#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>

void string_my(char *);
void new_arrays(char *, int p, int *);


void main()
{
	char *array;
	array = new char[300];
	system("cls");
	fflush(stdin);

	string_my(array);

}


void string_my(char *array)
{
	puts("Enter dear user you string!");
	puts("******************************************************");
	fflush(stdin);
	gets_s(array, 300);
	printf("Length is %d\n", _mbstrlen(array));
	int longer = _mbstrlen(array);
	printf_s("longer is %d\n", longer);
	if (_mbstrlen(array) % 2 != 0)
	{
		int s = _mbstrlen(array) / 2;
		int *dl = &s;
		printf_s("%d", s / 2);
		new_arrays(array, longer, dl);
	}
	puts(array);
	system("pause");
}


void new_arrays(char *mas, int p, int *x)
{
	printf("\n\n\n\n");


	for (int key = 0; key < p; key++)
	{
		if (key != *x) {
			printf_s("%c", mas[key]);
		}
		else continue;
	}
	printf("\n\n\n\n");
}