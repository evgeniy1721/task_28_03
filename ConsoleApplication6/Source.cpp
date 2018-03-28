#include <stdlib.h>
#include <stdio.h>

#include <time.h>
#include <locale.h>

#include <iostream>
#include <Windows.h>
#include "Header.h"
#include <fstream>
using namespace std;
void main(/*int args, char *argv[]*/)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("chcp 1251");
	system("cls");
	
	srand(time(0));
	rand();

	/*if (argv > 0)
	{
		for (int i = 0; i < args; i++)
		{
			printf("[%d] - %s\n", i, argv[i]);
		}
	}*/

	printf("Введите кол-во элементов: ");

	int count = 0;
	scanf("%d", &count);

	crypt *Crypt = (crypt*)malloc(sizeof(crypt) * count);
	if (Crypt != NULL)
	{
		for (int i = 0; i < count; i++)
			generationCrypt((Crypt + i));

		for (int i = 0; i < count; i++)
		{
			printf("Подразделение: %d%d%d\n", Crypt->razd[0], Crypt->razd[1], Crypt->razd[2]);
			for (int j = 0; j < 4; j++)
			{
				if(Crypt->plan[j][2] == 1)
					SetConsoleTextAttribute(hConsole, 12);
				else
					SetConsoleTextAttribute(hConsole, 15);
				printf("-->%2.2lf - %2.2lf - %lf\n", Crypt->fact[j][1], Crypt->plan[j][1], Crypt->plan[j][2]);
			}
		}

		
	}
	//system("pause");

}