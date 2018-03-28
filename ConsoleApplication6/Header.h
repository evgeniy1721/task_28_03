struct crypt
{
	char razd[3];
	double plan[4][3];		//Двумерный указатель
	double fact[4][3];
	int kvart;
	int pokazat;
};

//void generatoinNumber(double *mas, int row, int col);
void generationCrypt(crypt *Crypt);
//static double* getMemory(int len);