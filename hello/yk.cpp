#include <stdio.h>
#include <locale.h>
#define CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <process.h>




void change_number_uk(int *number_1, int  *number_2)
{
	int new_number = *number_1;
	*number_1 = *number_2;
	*number_2 = new_number;
	printf_s("A = %d", *number_1);
	printf_s("\nB = %d", *number_2);}






void change_number(int * number_1, int * number_2)
{
	int new_number = *number_1;
	*number_1 = *number_2;
	*number_2 = new_number;
}


	void main455()
	{
		int a, b;
		int *uk_a;
		int *uk_b;
		uk_a = &a;
		uk_b = &b;

		printf_s("A = ");
		scanf_s("%d", &a);
		printf_s("B = ");
		scanf_s("%d", &b);
		//change_number(&a, &b);
		change_number_uk(uk_a, uk_b);  //Функция по изменению значания
		printf_s("A = %d", a);

		printf_s("\nB = %d", b);
		system("pause");

	}