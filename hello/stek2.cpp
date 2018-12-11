#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <io.h>
#include <conio.h>
#include <process.h>
#include <time.h>
#include <stdlib.h>




struct list_element

{
	int value;
	struct list_element * next;
};

void print_list(struct list_element *);
struct list_element * create_LIFO(int);
void delete_list(struct list_element *);

void main1233()

{
	int N;
	struct list_element *FIRST = NULL; //Указатель на первый элемент списка
	setlocale(LC_CTYPE, "Russian");
	printf("Введите кол-во элементов списка (N - целое число):\n");
	scanf("%d", &N);
	srand(time(0));
	puts("Создание списка:");
	FIRST = create_LIFO(N);
	puts("Исходный список:");
	print_list(FIRST);
	delete_list(FIRST);
	_getch();

}

struct list_element *create_LIFO(int N)
{
	struct list_element * FIRST = NULL, *TMP = NULL;
	for (int i = 0; i < N; i++)

	{
		TMP = FIRST;
		FIRST = new list_element;
		FIRST->next = TMP;
		FIRST->value = rand();
		printf("%d - %d\n", i + 1, FIRST->value);

	}
	return FIRST;
	}


void print_list(struct list_element * list)

{
	int i = 1; //Переменная, которая содержит номер обрабатываемой структуры(использ.при выводе для большей наглядности)

		while (list) //Организуем цикл, кот выполняется пока list не станет равно NULL
		{
		printf("%2.d ADDR: %p VALUE: %d\tADDR_NEXT: %p\n", i, list,
		list->value, list->next); //Вывод информации об элементе списка
		list = list->next; //Получаем в list адрес элемента следующего за элементом, адрес которого на данной итерации хранится в list
		i++; //увелич. счетчик структур
		}

}


void delete_list(struct list_element *list)

{
	struct list_element *tmp; //Вспомог. переменная, которая будет хранить адрес удал.Структуры
	while (list) //Цикл вып. пока list не станет равным NULL (не дойдем до последней структуры)
	{
	tmp = list; //Адрес текущего элемента в списке заносим во временную (вспомогательную)переменную
	list = list->next; //В качестве текущей структуры устанавливаем следующую
	delete tmp; //Удаляем структуру, которую обрабатывали на данной итерации
	}

}