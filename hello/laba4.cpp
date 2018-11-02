#include <stdio.h>
#define CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <process.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>


void my_print(int, double*);
void inputArray(int, double*, char*);

void main()
{
	setlocale(LC_CTYPE, "rus");
	system("cls");
	
	int user_N, user_M;
	char nomer[] = "N";
	char *nomer_massive = nomer;
	double *massivN; //�������� �������� N � �
	double *massivM;
	printf("������� ������ ������� N: ");
	scanf_s("%d", &user_N);
	printf("������� ������ ������� M: ");
	scanf_s("%d", &user_M);
	massivN = (double*)(calloc((user_N + 1) , sizeof(double)));// �������� ������ ��� ������ N
	massivM = (double*)(calloc((user_M + 1) , sizeof(double)));// �������� ������ ��� ������ M
	
	//double summ = 0;
	//for (begin = 0; begin < user_N; begin++)
	//{
	//	printf_s("\n������� �������� ������� [%d],[%d]= ", nomer, begin);
	//	scanf_s("%lf", &massivN[begin]);//����� ����� ������ &
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
		printf_s("����� ������� N ���������� %lf, ��� ������ ��������\
 ����� ������� M ������� ���������� %lf\n", massivN[user_N], massivM[user_M]);
		my_print(user_N, massivN);
	}
	else if (massivN[user_N] > massivM[user_M])
	{
		printf_s("����� ������� N ���������� %lf, ��� ������ ��������\
 ����� ������� M ������� ���������� %lf\n", massivN[user_N], massivM[user_M]);
		my_print(user_M, massivM);
	}
	else printf_s("����� �������� N, M ����� � ���������� %lf", massivN[user_N]);

	_getch();
}


void inputArray(int Cikl, double *array, char *nomer_massiva)
{


	double summ = 0;
	for (int begin = 0; begin < Cikl; begin++)
	{
		printf_s("\n������� �������� ������� [%d],[%d]= ", *nomer_massiva, begin);
		scanf_s("%lf", &array[begin]);
		//printf_s("%.4lf", array[begin]);
		begin == 0 ? summ = array[begin] : summ = summ * array[begin];
		//summ += array[begin];
		//printf_s("\n%lf", summ);

	}
	array[Cikl] = summ;
	//nomer_massiva++;
}


void my_print(int Cikl, double *array) 
{
	for (int k = 0; k < Cikl; k++) 
	{
		printf_s("�������� %d ������� ��������� : %.4lf\n", k+1, array[k]);
	}
	printf_s("������� �� ��������!!!!!");
}