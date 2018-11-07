#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>


void fill_array(int **, int, int);
int max(int **, int, int);



void laba51()
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





void enter_number(int **, int *, int *);
void my_print_massive(int **, int *, int *, int *);
int counter(int **, int *, int *);
void delete_cash(int **, int *);

void main()
{
	setlocale(LC_CTYPE, "rus");
	int n, m, *high, *longer;
	high = &n;  //create ukazatel
	longer = &m;
	int **array;
	int count;
	int *uk_count;
	uk_count = &count;
	printf_s("¬ведите число N: ");
	scanf_s("%d", &n);
	if (n < 1) {
		while (n < 1){
		printf_s("¬ведите число N: ");
		scanf_s("%d", &n);
		}
	}
	printf_s("¬ведите число M: ");
	scanf_s("%d", &m);
	if (m < 1) {
		while (m < 1) {
			printf_s("¬ведите число M: ");
			scanf_s("%d", &m);
		}
	}
	
	array = (int**)malloc(sizeof(int*)*n);
	for (int k = 0; k < m; k++) {
		*(array + k) = (int*)malloc(sizeof(int)*m);
	}
	enter_number(array, high, longer);
	count = counter(array, high, longer);
	my_print_massive(array, high, longer, uk_count);
	delete_cash(array, high);

	system("pause");
}

void enter_number(int **massive, int *visota, int *dlinna)
{
	printf("«драствуй, сейчас бедет производитс€ заполнение массива\n ");
	for (int v = 0; v < *visota; v++)
	{for (int d = 0; d < *dlinna; d++)
	{
		printf("Enter your number, height [%d] length[%d] : ", v +1, d + 1);
		scanf("%d", *(massive + v) + d);


	}
		
	}


}




void my_print_massive(int **mas, int *vis, int * dl, int *kolvo)
{

	printf("The array will now be printed. \n ");
	puts("*******************************************************************************");
	for (int v = 0; v < *vis; v++)
	{
		printf("string value range [%d] : \t", v+1 );
		for (int d = 0; d < *dl; d++)
		{
			printf("%d\t ", mas[v][d]);
			


		}
		printf("\n");
	}

	printf("The number of rows containing a zero value is %d\n", *kolvo);
}


int counter(int **mas, int *vis, int * dl) 
{
	int s = 0;
	for (int v = 0; v < *vis; v++)
	{
		for (int d = 0; d < *dl; d++)
		{
			if (mas[v][d] == 0) {
				s++;
				break;
			}


		}

	}
	return s;
}


void delete_cash(int **m, int *v)
{
	for (int n = 0; n < *v; n++) 
	{
		free(*(m + n));
	}
}