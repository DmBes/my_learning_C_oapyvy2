#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <process.h>
#include <conio.h>
#include <string.h>
#define N 20
#define M 20

struct der
{
	char *inf; // информационное поле
	int n; // число встреч инф. поля в бинарном дереве
	der *l, *r; // указатель на левое и правое поддерево
};

void see_2(der *);
der *sozd(der *);
void add(der *);
void main(void)
{
	setlocale(LC_CTYPE, "Rus");
	der *dr;
	dr = NULL; // адрес корня бинарного дерева
	system("cls");
	while (1)
	{
		puts("вид операции : \n1 - создать дерево");
		puts("2-вывод содержимого дерева");
		puts("3-добавление элементов в дерево");
		puts("4-выход");
		fflush(stdin);
		switch (_getch())
		{
		case '1': dr = sozd(dr); break;
		case '2': see_2(dr); _getch(); break;
		case '3': add(dr); break;
		case '4': return;
		}
		system("cls");
	}
}

der *sozd(der *dr)

{
	if (dr)
	{
		puts("Бинарное дерево уже создано");
		return (dr);
	}
	if (!(dr = (der *)calloc(1, sizeof(der))))
	{
		puts("Нет свободной памяти");
		_getch();
		return NULL;
	}
	puts("Введите информацию в корень дерева");
	dr->inf = (char *)calloc(1, sizeof(char)*N);
	fgets(dr->inf,50,stdin);
	dr->n = 1; // число повторов информации в дереве
	return dr;
}

void add(der *dr)

{
	der *dr1, *dr2;
	char *st; // строка для анализа информации
	int k; // результат сравнения двух строк
	int ind;
	if (!dr)
	{
		puts("Нет корня дерева \n");
		_getch();
		return;
	}
	do
	{
		puts("Введите информацию в очередной узел дерева (0 - выход)");
		st = (char *)calloc(1, sizeof(char)*N); //память под символьную инф.
		fgets(st,50, stdin);
		if (!*st) return; // выход в функцию main
		dr1 = dr;
		ind = 0; // 1 - признак выхода из цикла поиска
		do
		{
			if (!(k = strcmp(st, dr1->inf)))
			{
				dr1->n++; // увеличение числа встреч информации узла
				ind = 1; // для выхода из цикла do ... while
			}
			else
			{
				if (k < 0) // введ. строка < строки в анализируемом узле
				{
					if (dr1->l) dr1 = dr1->l; // считываем новый узел дерева
					else ind = 1; // выход из цикла do ... while
				}
				else // введ. строка > строки в анализируемом узле
				{
					if (dr1->r) dr1 = dr1->r; // считываем новый узел дерева
					else ind = 1; // выход из цикла do ... while
				}
			}
		} while (ind == 0);
		if (k) // не найден узел с аналогичной информацией
		{
			if (!(dr2 = (struct der *) calloc(1, sizeof(struct der))))
			{
				puts("Нет свободной памяти");
				return;
			}
			if (k < 0) dr1->l = dr2; // ссылка в dr1 налево
			else dr1->r = dr2; // ............ направо
			dr2->inf = (char *)calloc(1, sizeof(char)*N);
			strcpy(dr2->inf, st); // заполнение нового узла dr2
			dr2->n = 1;
		}
		free(st);
	} while (1); // любое условие т.к. выход из цикло по return
}

//вывод содержимого бинарного дерева

void see_2(der *dr1)
{
	struct stek
	{
		der *d;
		stek *s;
	} *st, *st1 = NULL;
	int pr = 1;
	for (int i = 0; i < 2; i++) // в стек заносятся 2 элемента содержащие указатель
	{
		st = (stek *)calloc(1, sizeof(stek)); // на корень дерева для прохода по
		st->d = dr1; // левому и правому поддеревьям
		st->s = st1; // указатель на стек вниз
		st1 = st;
	}
	printf("узел содержит : %s \n", dr1->inf);
	while (st)
	{
		do
		{
			if (pr && dr1->l) dr1 = dr1->l; // переход на узел слева
			else if (dr1->r) dr1 = dr1->r; // переход на узел cправа
			pr = 1; // сброс принудительного движения вправо
			if (dr1->l && dr1->r) // узел с 2 связями вниз
			{
				st1 = st;
				st = (stek *)calloc(1, sizeof(stek));
				st->d = dr1; // указатель на найденый узел
				st->s = st1; // указатель на стек вниз
			}
			printf("узел содержит : %s \n", dr1->inf);
		} while (dr1->l || dr1->r);
		dr1 = st->d; // возврат на узел ветвления
		st1 = st->s; // в стеке адрес узла выше удаляемого
		free(st); // удаление из стека указателя на узел после прохода через него налево
			st = st1;
		if (dr1->r) pr = 0; // признак принудительного перехода на
		// узел расположенный справа от dr1, т.к. dr1->inf уже выведен при проходе слева
	}
}