#include <stdio.h>
#define CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <process.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>


void my_print(int, double*);
void inputArray(int, double*, char*);

void main3()
{
	setlocale(LC_CTYPE, "rus");
	system("cls");

	int user_N, user_M;
	char nomer[] = "a";
	char *nomer_massive = nomer;
	double *massivN; //Создание массивов N и М
	double *massivM;
	printf("Введите размер массива N: ");
	scanf_s("%d", &user_N);
	printf("Введите размер массива M: ");
	scanf_s("%d", &user_M);
	massivN = (double*)(calloc((user_N + 1), sizeof(double)));// выделяем память под массив N
	massivM = (double*)(calloc((user_M + 1), sizeof(double)));// Выделяем память под массив M

															  //double summ = 0;
															  //for (begin = 0; begin < user_N; begin++)
															  //{
															  //	printf_s("\nВведите значения массива [%d],[%d]= ", nomer, begin);
															  //	scanf_s("%lf", &massivN[begin]);//Может нужно убрать &
															  //	printf_s("%.4lf", massivN[begin]);
															  //	summ += massivN[begin];
															  //	printf_s("\n%lf", summ);

															  //}

	inputArray(user_N, massivN, nomer);
	inputArray(user_M, massivM, nomer);
	system("pause");
	system("cls");

	if (massivN[user_N] < massivM[user_M])
	{
		printf_s("Сумма массива N составляет %lf, что меньше величины\
 суммы массива M который составляет %lf\n", massivN[user_N], massivM[user_M]);
		my_print(user_N, massivN);
	}
	else if (massivN[user_N] > massivM[user_M])
	{
		printf_s("Сумма массива N составляет %lf, что больше величины\
 суммы массива M который составляет %lf\n", massivN[user_N], massivM[user_M]);
		my_print(user_M, massivM);
	}
	else printf_s("Сумма массивов N, M РАВНА и составляет %lf", massivN[user_N]);
	free(massivM);
	free(massivN);

	_getch();
}


void inputArray(int Cikl, double *array, char *nomer_massiva)
{


	double summ = 0;
	for (int begin = 0; begin < Cikl; begin++)
	{
		printf_s("\nВведите значения массива [%c],[%d]= ", *nomer_massiva, begin + 1);
		scanf_s("%lf", &array[begin]);
		//printf_s("%.4lf", array[begin]);
		begin == 0 ? summ = array[begin] : summ = summ * array[begin];
		//summ += array[begin];
		//printf_s("\n%lf", summ);

	}
	array[Cikl] = summ;
	char replece_name = 'b';
	*nomer_massiva = replece_name;

}


void my_print(int Cikl, double *array)
{
	for (int k = 0; k < Cikl; k++)
	{
		printf_s("Значение %d массива составлют : %.4lf\n", k + 1, array[k]);
	}
	printf_s("Спасибо за просмотр!!!!!");
}




void my_print2(double *array_1, double *array_2, int a, int b)
{
	printf_s("Массив 1 равен %lf, Массив 2 равен %lf\n", array_1[0], array_2[0]);
	if (array_1[0] == array_2[0]) {
		printf_s("Значения диапазонов равны");
	}
	else if (array_1[0] < array_2[0])
	{
		for (int k = 1; k < a + 1; k++)
		{
			printf_s("Значение %d массива составлют : %.4lf\n", k, array_1[k]);
		}
		printf_s("Спасибо за просмотр!!!!!");
	}
	else
	{
		for (int k = 1; k < a + 1; k++)
		{
			printf_s("Значение %d массива составлют : %.4lf\n", k, array_2[k]);
		}
		printf_s("Спасибо за просмотр!!!!!");
	}

}




void function2(int, double*, char *user_name_array);


void main22()
{
	setlocale(LC_CTYPE, "rus");
	system("cls");
	int N, M;
	char nomer[] = "A";
	char *nomer_massive = nomer;


	printf("Введите размер массива A: ");
	scanf_s("%d", &N);
	printf("Введите размер массива B: ");
	scanf_s("%d", &M);
	double *massivA = (double *)(calloc((N + 1), sizeof(double)));
	double *massivB = (double *)(calloc((M + 1), sizeof(double)));
	function2(N, massivA, nomer);
	function2(M, massivB, nomer);
	my_print2(massivA, massivB, N, M);
	free(massivA);
	free(massivB);
	_getch();
}


void function2(int user_num, double *user_mass, char *user_name_array)
{
	double multiplicatin = 0;

	for (int step = 1; step < user_num + 1; step++)
	{
		printf_s("Введите число %d массива %c : ", step, *user_name_array);
		scanf_s("%lf", &user_mass[step]);
		step == 1 ? multiplicatin = user_mass[step] : multiplicatin = user_mass[step] * user_mass[0];
		user_mass[0] = multiplicatin;
		//printf_s("\n%lf", user_mass[0]);

	}

	char replece_name = 'B';
	*user_name_array = replece_name;

}





void zadanie2(int razmer_massiva, int *sam_massiv)
{
	int summa = 0;
	for (razmer_massiva; razmer_massiva >= 0; razmer_massiva--)
	{
		if (sam_massiv[razmer_massiva] != 0 && razmer_massiva == 0)
		{
			printf_s("Функция не имеет решения");
		}
		else if (sam_massiv[razmer_massiva] != 0)
		{
			continue;
		}
		else
		{
			for (razmer_massiva; razmer_massiva >= 0; razmer_massiva--)
			{
				summa += sam_massiv[razmer_massiva];
			}
			printf_s("Сумма диапазона равна %d", summa);
			_getch();
			break;
		}
	}

}



void main5()
{
	int n;
	int *array;
	setlocale(LC_CTYPE, "rus");
	system("cls");

	printf_s("Введите размер массива A: ");
	scanf_s("%d", &n);
	array = new int[n];
	if (!array) {
		printf("Out of memory. Press any key: ");
		_getch();
		exit(1);
	}

	int number = 0;
	int stepik = 0;

	while (stepik < n)
	{
		printf_s("Введите число %d массива: ", stepik + 1);
		scanf_s("%d", &number);
		if (number == 0)
		{
			stepik++;
			break;
		}
		else if (stepik == n)
		{

		}
		else {
			stepik++;
			if (stepik == n && number != 0) {
				printf_s("Функция не имеет решения\n");
				break;
			}
		}
	}


	for (stepik + 1; stepik < n; stepik++, number++)
	{
		printf_s("Введите число %d массива: ", stepik + 1);
		scanf_s("%d", &array[number]);
		//printf_s("Вывод массива %d\n", array[number]);
	}
	zadanie2(number, array);
	_getch();
}