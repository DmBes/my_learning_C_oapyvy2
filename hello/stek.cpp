#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <io.h>
#include <conio.h>
#include <process.h>

#include <stdlib.h>

struct list_element

{

	int value; //«начение

	struct list_element * next;//”казатель на следующую структуру

};

void main22() {
	struct list_element * FIRST = NULL, *TMP = NULL;
	int N = 4;

	//FIRST -- указатель на начало списка, TMP -- вспомогательна€ переменна€

		for (int i = 0; i < N; i++) {

		TMP = FIRST; // «аписываем в TMP адрес структуры, котора€ быласоздана на предыдущей итерации(1 - € итерации -- NULL)
		FIRST = new list_element; //—оздаем в пам€ти новую структуру

		FIRST->next = TMP; //јдресом структуры следующей за структурой создaна данной итерации(поле next) указываем адрес структуры
		//созд.наред.шаге(адрес был сохранен в TMP)

		FIRST->value = rand();//”станавливаем значение пол€ value созданной структуры

		printf("%d - %d\n", i + 1, FIRST->value); //¬ыводим на печать информацию по о созданной структуре

		}

	_getch();

}



