#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <process.h>
#include <conio.h>


struct list_element

{

	int value; //Значение
	struct list_element * next; //Указатель на следующую структуру
};

void maiadn()

{

	int N = 4;
	struct list_element * FIRST = NULL, *CURRENT = NULL; //FIRST --	указатель на начало списка, CURRENT -- вспомогательная переменная
		for (int i = 0; i < N; i++)
		{
			if (FIRST == NULL) //Проверяем создан ли первый элемент списка
			{
				FIRST = new struct list_element; //Если нет, создаем первый элемент
				CURRENT = FIRST; //Устанавливаем его в качестве текущего
			}
			else
			{//Если это не первый элемент
				CURRENT->next = new struct list_element; //Создаем в памяти	структуру, в поле next текущей структуры записываем адрес созданной
					CURRENT = CURRENT->next;//В качестве текущей устанавливаем следующую
			}
			CURRENT->next = NULL; //Адрес следующей за текущей устанавливаем в NULL
			CURRENT->value = rand(); //Устанавливаем значение поля value созданной структуры(используя генератор случ.чисел)
			printf("%d - %d\n", i + 1, CURRENT->value); //Выводим на печать	информацию по о созданной структуре
		}

		_getch();

}