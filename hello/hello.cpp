
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <process.h>
#include <locale.h>
#define Pi 3.1415926

// Лабораторная задача 2-1

void lab_2_1()
{
	setlocale(LC_CTYPE, "Russian");

	double alpha, z1, z2;
	system("cls");
	printf("Введите значение угла альфа: ");
	scanf_s("%lf", &alpha);
	z1 = cos(alpha) + sin(alpha) + cos(3 * alpha) + sin(3 * alpha);
	z2 = 2 * sqrt(2) * cos(alpha) * sin((Pi / 4) + (2 * alpha));
	printf("alpha is %lf\n", alpha);
	printf("z1 is %.4lf z2 is %.4lf\n", z1, z2);
	_getch();
	return;

}


// Лабораторная задача 2-2

void lab_2_2()
{
	setlocale(LC_CTYPE, "Russian");

	double x, y, z, u;
	system("cls");
	printf("Введите значение x: ");// Тут начало фигни
	scanf_s("%lf", &x);
	printf("Введите значение y: ");
	scanf_s("%lf", &y);
	printf("Введите значение z: ");
	scanf_s("%lf", &z);
	//printf("Введите значение x, y, z: ");
	//scanf_s("%lf%lf%lf", &x, &y, &z);  // Тут конец фигни
	printf("\n x =%.4lf, y =%.4lf, z =%.4lf", x, y, z);
	printf("\n");
	double z1 = (pow(8 + pow(fabs(x - y), 2) + 1, 1. / 3));
	double z2 = pow(x, 2) + pow(y, 2) + 2;
	double z3 = exp(fabs(x - y)) * pow((pow(tan(z), 2)) + 1, x);
	printf("z1 is %.4lf and z2 is %.4lf, z3 is %.4lf\n", z1, z2, z3);
	u = (z1 / z2) - z3;

	printf("u is %lf\n", u);

	_getch();
	return;

}



// Лабораторная задача 2-3


void lab_2_3() {

	setlocale(LC_CTYPE, "Russian");
	double a, x, b, z, up, down, y;
	system("cls");
	printf("Введите число a: ");
	scanf_s("%lf", &a);
	printf("Введите число b: ");
	scanf_s("%lf", &b);
	printf("Введите число z: ");
	scanf_s("%lf", &z);
	//printf("Введите значение a, b, z: ");
	//scanf_s("%lf%lf%lf", &a, &b, &z);
	if (z < a * b) {
		x = sqrt(pow(a, 2) + pow(b, 2) * z);
	}
	else {
		x = pow(sin(z), 2) + fabs(a * b * z);
	}

	up = a * x + b * x * cos(sqrt(x));
	down = x + a * b;

	y = up / down;

	printf("\nЗначение y = %.4lf", y);
	_getch();
	return;
}




// Лабораторная задача 2-4
void lab_2_4()
{
	setlocale(LC_CTYPE, "Russian");
	double x, y, z, n, max, min;
	system("cls");
	printf("Введите последовательно значение x, y, z: ");
	scanf("%lf%lf%lf", &x, &y, &z);
	if (x + y > y - z ? min = y - z : min = x + y);
	x > y ? max = x : max = y;
	if (max != 0) {
		n = min / max;
		printf("\n n= %.4lf", n);
	}
	else { printf("\n Деление на 0 недопустимо"); }

	_getch();
	return;
}


//Лабораторная задача 2-5
void lab_2_5()
{
	double fifa, teta, result;
	setlocale(LC_CTYPE, "Rus");
	system("cls");
	printf("Введите число fifa: ");
	scanf_s("%lf", &fifa);
	printf("Введите число teta: ");
	scanf_s("%lf", &teta);

	if (5 * fabs(teta) < fabs(fifa) && fabs(fifa) <= 7.5 * fabs(teta)) {
		result = log(fabs(2 * pow(fifa, 2) - 3 * teta));
		printf("Выведен ветка 2 значение т = %.4lf\n", result);

	}
	else if (fifa < 5 * fabs(teta))
	{
		result = log(fabs(2 * fifa - 3 * exp(2) * teta));
		printf("Выведен ветка 1 значение т = %.4lf\n", result);
	}

	else
	{
		printf("Нет вариантов\n");
	}
	_getch();

}



// Лабораторная задача 3-1
void lab_3_2() {

	double begin, finish, step;  //  a до b с шагом h.Значения a, b, h и n вводятся с клавиатуры.
	int k = 1, number_of_operation;
	double summ_x, summ_y;  //Переменные расчетные (итоги)
	double x; // значение аргумента x изменяется от a до b с шагом h.
	system("cls");

	printf("Введите переменную begin: ");
	scanf("%lf", &begin);
	printf("Введите переменную finish: ");
	scanf("%lf", &finish);
	printf("Введите переменную step: ");
	scanf("%lf", &step);
	printf("Введите переменную number_of_operation: ");
	scanf("%d", &number_of_operation);
	//system("pause");
	puts("    x \t\t S(x) \t\t Y(x)\t\t  Y(x)-S(x)\t\t");
	puts("********************************************************************");
	for (begin; begin <= finish; begin += step) {
		//	printf("%lf\n", begin);
		summ_x = 0;
		summ_y = begin / 2;
		for (k = 1; k <= number_of_operation; k++) {
			summ_x += pow(-1, k + 1) * (sin(k * begin) / k);
		}
		printf_s("* %lf \t* %lf \t* %lf \t* %lf *\n", begin, summ_x, summ_y, summ_x - summ_y);

	}

	_getch();
}

// Функция подсчета итогов по Y
double itog_y(double perem) {
	return perem / 2;

}


// Функция возврата по укзателю
double itog_y_yk(double *perem) {
	return *perem / 2;

}



// Функция возврата по ссылке
double vozvrat_po_ssilke(int &cislo1, double &cislo2) {
	double k;
	k = sin(cislo1 * cislo2) / cislo1;
	return k;
}

double itog_x(int cikl, double shag)
{
	return pow(-1, cikl + 1) * (sin(cikl * shag) / cikl);

}


void my_print(double raz, double dva, double tri)
{
	double chetire = dva - tri;
	printf_s("* %lf \t* %lf \t* %lf \t* %lf *\n", raz, dva, tri, chetire);
}


// 
void lab_3_3() {

	double begin, finish, step;  //  a до b с шагом h.Значения a, b, h и n вводятся с клавиатуры.
	int k = 1, number_of_operation;
	double summ_x, summ_y, ppp;  //Переменные расчетные (итоги)
	double x; // значение аргумента x изменяется от a до b с шагом h.
	system("cls");

	printf("Введите переменную begin: ");
	scanf("%lf", &begin);
	printf("Введите переменную finish: ");
	scanf("%lf", &finish);
	printf("Введите переменную step: ");
	scanf("%lf", &step);
	printf("Введите переменную number_of_operation: ");
	scanf("%d", &number_of_operation);
	//system("pause");
	puts("    x \t\t S(x) \t\t Y(x)\t\t  Y(x)-S(x)\t\t");
	puts("********************************************************************");
	for (begin; begin <= finish; begin += step) {
		//	printf("%lf\n", begin);
		summ_x = 0;
		summ_y = itog_y(begin);
		for (k = 1; k <= number_of_operation; k++) {
			ppp = itog_x(k, begin);
			summ_x += ppp;
		}
		my_print(begin, summ_x, summ_y);

	}




	_getch();
}




// Версия лабораторной работы преподователя.
void lab_3_1()
{
	setlocale(LC_CTYPE, "Russian");
	double a, b, h, x, rez, y, s, delta;
	int n, i, k;
	system("cls"); fflush(stdin);
	printf("Введите a:");
	scanf_s("%lf", &a);
	printf("Введите b:");
	scanf_s("%lf", &b);
	printf("Введите h:");
	scanf_s("%lf", &h);
	printf("Введите n:");
	scanf_s("%d", &n);
	printf("\n");
	puts(" x | Y(x) | S(x) | Y(x)-S(x) |");
	puts("----------------------------------------- ");
	x = a;
	while (x <= b) {
		s = 0;
		for (k = 0; k <= n; k++) {
			rez = 1;
			for (i = 1; i <= 2 * k + 1; i++)
				rez *= i;
			s += pow(-1., k)*pow(x, (2 * k + 1)) / rez;
		}
		y = sin(x);

		delta = fabs(y - s);

		printf("\n %.2lf | %.5lf | %.5lf| %.5lf | \n", x, y, s, delta);

		x += h;

	}

	_getch();

}




void lab_3_4() {

	double begin, finish, step;  //  a до b с шагом h.Значения a, b, h и n вводятся с клавиатуры.
	int k = 1, number_of_operation;
	double summ_x, summ_y;  //Переменные расчетные (итоги)
	double x; // значение аргумента x изменяется от a до b с шагом h.
	system("cls");

	printf("Введите переменную begin: ");
	scanf("%lf", &begin);
	printf("Введите переменную finish: ");
	scanf("%lf", &finish);
	printf("Введите переменную step: ");
	scanf("%lf", &step);
	printf("Введите переменную number_of_operation: ");
	scanf("%d", &number_of_operation);

	puts("    x \t\t S(x) \t\t Y(x)\t\t  Y(x)-S(x)\t\t");
	puts("********************************************************************");
	for (begin; begin <= finish; begin += step) {

		summ_x = 0;
		summ_y = itog_y_yk(&begin); // УКАЗАТЕЛЬ
		for (k = 1; k <= number_of_operation; k++) {
			summ_x += pow(-1, k + 1) * vozvrat_po_ssilke(k, begin); // По ссылке возврат
		}
		printf_s("* %lf \t* %lf \t* %lf \t* %lf *\n", begin, summ_x, summ_y, summ_x - summ_y);

	}

	_getch();
}


void not_main() {
	system("cls");
	setlocale(LC_CTYPE, "rus");
	long int integer;
	float integer_tochka;
	char words;
	double doble_float;
	int bolshoe_4islo_int;
	printf("Введите число: ");
	scanf("%lf", &doble_float);
	printf("Вaше число равно %2.2lf", doble_float);
}

// Функция Main

void main4343() {

	system("cls");
	int vibor;
	setlocale(LC_CTYPE, "Rus");
	puts("Приятной работы тебе человек\n");
	printf("Введите номер задания (форма 11, где первое число номер лабы, второе число номер задачи): ");

	scanf("%d", &vibor);
	switch (vibor)
	{
	case 21:
		lab_2_1();
		break;
	case 22:
		lab_2_2();
		break;
	case 23:
		lab_2_3();
		break;
	case 24:
		lab_2_4();
		break;
	case 25:
		lab_2_5(); //Задание №5
		break;
	case 31:
		lab_3_1(); //Задание №1 (преподавательский вариант
		break;
	case 32: //Задание №1
		lab_3_2();
		break;
	case 33:	//Задание №2
		lab_3_3();
		break;
	case 34:	//Задание №2
		lab_3_4();
		break;
	case 35:	//Задание №2
		lab_3_4();
		break;

	default:
		break;

	}
	return;
}



