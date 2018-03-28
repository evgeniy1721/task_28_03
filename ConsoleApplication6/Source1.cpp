#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <locale.h>

#include <iostream>

struct crypt
{
	char razd[3];
	double plan[4][3];		//Двумерный указатель
	double fact[4][3];
	int kvart;
	int pokazat;
};

void generatoinNumber(double mas[][3], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		mas[i][0] = i;
		for (int j = 0; j < col; j++)
			mas[i][1] = (5000 + rand() % 15000) / (1 + rand() % 10);
	}
}

double* getMemory(int len)
{
	return (double*)malloc(sizeof(double)* len);
}

void checkPlan(crypt *Crypt)
{
	for (int i = 0; i < Crypt->kvart; i++)
	{
		if (Crypt->fact[i][1] >= Crypt->plan[i][1])
			Crypt->plan[i][2] = 1;
		else
			Crypt->plan[i][2] = 0;
	}
}

void generationCrypt(crypt *Crypt)
{
	printf("*");
	Crypt->pokazat = 3;
	Crypt->kvart = 4;

	generatoinNumber(Crypt->plan, Crypt->kvart, Crypt->pokazat);
	generatoinNumber(Crypt->fact, Crypt->kvart, Crypt->pokazat);

	for (int i = 0; i < 3; i++)
		Crypt->razd[i] =0+ rand() % 10;

	checkPlan(Crypt);
}
