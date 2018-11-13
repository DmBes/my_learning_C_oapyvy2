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
	printf_s("Функция A = %d", *number_1);
	printf_s("\nФункция  B = %d\n", *number_2);}






void change_number(int * number_1, int * number_2)
{
	int new_number = *number_1;
	*number_1 = *number_2;
	*number_2 = new_number;
}


	void prosto_ykazatel()
	{
		int a, b;
		int *uk_a;
		int *uk_b;
		int **uk_uk_a;
		int ***uk_uk_uk_a;
		uk_a = &a;
		uk_b = &b;
		uk_uk_a = &uk_a;
		uk_uk_uk_a = &uk_uk_a;

		setlocale(LC_CTYPE, "rus");

		printf_s("A = ");
		scanf_s("%d", &a);
		printf_s("B = ");
		scanf_s("%d", &b);
		//change_number(&a, &b);
		change_number_uk(uk_a, uk_b);  //Функция по изменению значания
		printf_s("A = %d\n", a);

		printf_s("B = %d", b);
		system("pause");


		scanf_s("%d", *uk_uk_a);
		printf_s("\n\n\n Указатель на указатель %d \n", a);
		system("pause");
		
		scanf_s("%d", **uk_uk_uk_a);
		printf_s("\n\n\n Указатель на указатель указатель %d \n", a);
		system("pause");
	}




	void F_uk(int *ukaz) {
		for (int i = 0; i < 5; i++)
		{
			printf_s("Enter your number: ");
			scanf_s("%d", ukaz + i);
			//scanf_s("%d", &c[i]);
			printf_s("значения %d равно %d\n", i, *(ukaz + i));
		}

	}


	void main() {
		int c[5];


		setlocale(LC_CTYPE, "rus");
		for (int i = 0; i < 5; i++)
		{
			printf_s("Enter your number: ");
			scanf_s("%d", c + i);
			//scanf_s("%d", &c[i]);
			printf_s("значения %d равно %d\n", i, *(c + i));
			printf_s("\n\n\n", i, *(c + i));
			

		}
		F_uk(c);
	}
