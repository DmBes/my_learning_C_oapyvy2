#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>



void main()
{
	setlocale(LC_CTYPE, "Rus");
	system("cls");
	int size_array, wide_array;
	int **array;
	printf_s("¬ведите длинну массива: ");
	scanf_s("%d", &size_array);
	printf_s("¬ведите ширину массива: ");
	scanf_s("%d", wide_array);
	array = (int **)malloc(sizeof(int*)* (size_array));
	for (int i = 0; i < wide_array; i++)
	{
		(*(array + i) = (int*)malloc(sizeof(int)*wide_array));
	}



}