#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>


void fill_array(int **, int, int);
int max(int **, int, int);



void main()
{
	setlocale(LC_CTYPE, "Rus");
	system("cls");
	int size_array, wide_array, max_ch;
	int **array;
m3: printf_s("¬ведите длинну массива: ");
	scanf_s("%d", &size_array);
	if (size_array < 1) {
		printf_s("¬ведите число больше 0\n");
		goto m3;
	}
m1: printf_s("¬ведите ширину массива: ");
	scanf_s("%d", &wide_array);
	if (wide_array < 1) {
		printf_s("¬ведите число больше 0\n");
		goto m1;
	}
	system("cls");
	array = new int*[size_array];
	for (int begin_array = 0; begin_array < size_array; begin_array++)
	{
		*(array + begin_array) = new int[wide_array];
		//for (int filling_array = 0; filling_array < wide_array; filling_array++) 
		//{
		//	printf_s("¬ведите в строке %d, число %d массива ", begin_array, filling_array);
		//	scanf_s("%d", &array[begin_array][filling_array]);
		//	printf_s("¬аше число равно : %d\n", array[begin_array][filling_array]);
		//}
	}
	fill_array(array, size_array, wide_array);
	max_ch = max(array, size_array, wide_array);
	printf_s("ћаксимальное число в массиве равно %d", max_ch);
	_getch();
	}


void fill_array(int **massive, int string, int width)
{
	for (int i = 0; i < string; i++)
	{
		for (int k = 0; k < width; k++)
		{
			printf_s("¬ведите в строке %d, число %d массива ", i+1, k+1);
			scanf_s("%d", &massive[i][k]);
//			printf_s("¬аше число равно : %d\n", *(*(massive + i) + k));
		}
	}
//	printf_s("Hello");
}


int max(int **mass, int stroka, int visota)
{
	int max_number;
	max_number = mass[0][0];

	for (int i = 0; i < stroka; i++)
	{
		for (int k = 0; k < visota; k++)
		{
			if (max_number > *(*(mass + i) + k)) { continue; }
			else
			{
				max_number = *(*(mass + i) + k);
			} 

		}
	}
	return max_number;
}
