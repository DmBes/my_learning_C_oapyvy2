#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <process.h>
#include <conio.h>


struct list_element

{
	int value;//«начение
	struct list_element *next;//”казатель на следующую структуру
};

void printa_list(struct list_element *);
struct list_element * create_FIFO(int);
void deletea_list(struct list_element *);

void main46()
{
	int N;
	struct list_element * FIRST = NULL; //”казатель на первый элемент списка
	setlocale(LC_CTYPE, "Russian");
	printf("¬ведите кол-во элементов списка (N - целое число):\n");
	scanf("%d", &N);
	srand(time(0));
	puts("—оздание списка:");
	FIRST = create_FIFO(N);
	puts("»сходный список:");
	printa_list(FIRST);
	deletea_list(FIRST);
	_getch();
}

struct list_element * create_FIFO(int N)

{
	struct list_element * FIRST = NULL, *CURRENT = NULL;
	for (int i = 0; i < N; i++)
	{
		if (FIRST == NULL)
		{
			FIRST = new struct list_element;
			CURRENT = FIRST;
		}
		else
		{
			CURRENT->next = new struct list_element;
			CURRENT = CURRENT->next;
		}
		CURRENT->next = NULL;
		CURRENT->value = rand();
		printf("%d - %d\n", i + 1, CURRENT->value);
	}
	return FIRST;
}

void printa_list(struct list_element * list)

{
	int i = 1;
	while (list)
	{
		printf("%2.d ADDR: %p VALUE: %d\tADDR_NEXT: %p\n", i, list,	list->value, list->next);
		list = list->next;
		i++;
	}
}

void deletea_list(struct list_element *list)
{
	struct list_element *tmp;
	while (list)
	{
		tmp = list;
		list = list->next;
		delete tmp;
	}
}