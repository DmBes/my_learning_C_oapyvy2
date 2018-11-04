#include <stdio.h>
#define CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <process.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>


void my_print(int, double*);
void inputArray(int, double*, char*);

void main1()
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
	free(massivM);
	free(massivN);

	_getch();
}


void inputArray(int Cikl, double *array, char *nomer_massiva)
{


	double summ = 0;
	for (int begin = 0; begin < Cikl; begin++)
	{
		printf_s("\n������� �������� ������� [%c],[%d]= ", *nomer_massiva, begin+1);
		scanf_s("%lf", &array[begin]);
		//printf_s("%.4lf", array[begin]);
		begin == 0 ? summ = array[begin] : summ = summ * array[begin];
		//summ += array[begin];
		//printf_s("\n%lf", summ);

	}
	array[Cikl] = summ;
	//char replece_name[] = "g";
	//nomer_massiva = replece_name;

}


void my_print(int Cikl, double *array) 
{
	for (int k = 0; k < Cikl; k++) 
	{
		printf_s("�������� %d ������� ��������� : %.4lf\n", k+1, array[k]);
	}
	printf_s("������� �� ��������!!!!!");
}




void my_print2(double *array_1, double *array_2, int a, int b)
{
	printf_s("������ 1 ����� %lf, ������ 2 ����� %lf\n", array_1[0], array_2[0]);
	if (array_1[0] == array_2[0]) {
		printf_s("�������� ���������� �����");
	}
	else if (array_1[0] < array_2[0]) 
	{
		for (int k = 1; k < a + 1; k++)
		{
			printf_s("�������� %d ������� ��������� : %.4lf\n", k , array_1[k]);
		}
		printf_s("������� �� ��������!!!!!");
	}
	else
	{
		for (int k = 1; k < a + 1; k++)
		{
			printf_s("�������� %d ������� ��������� : %.4lf\n", k , array_2[k]);
		}
		printf_s("������� �� ��������!!!!!");
	}
	
}




void function2(int, double*, char *user_name_array);


void main()
{
	setlocale(LC_CTYPE, "rus");
	system("cls");
	int N, M;
	char nomer[] = "N";
	char *nomer_massive = nomer;


	printf("������� ������ ������� A: ");
	scanf_s("%d", &N);
	printf("������� ������ ������� B: ");
	scanf_s("%d", &M);
	double *massivA = (double *)(calloc((N+1),sizeof(double)));
	double *massivB = (double *)(calloc((M+1), sizeof(double)));
	function2(N, massivA, nomer_massive);
	function2(M, massivB, nomer_massive);
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
			printf_s("������� ����� %d ������� %c : ", step, *user_name_array);
			scanf_s("%lf", &user_mass[step]);
			step == 1 ? multiplicatin = user_mass[step] : multiplicatin = user_mass[step] * user_mass[0];
			user_mass[0] = multiplicatin;
			//printf_s("\n%lf", user_mass[0]);

		}



}