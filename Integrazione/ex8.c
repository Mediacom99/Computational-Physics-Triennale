#include <integration.h>
#include <math.h>

/*Comando per compilare:
	gcc ex6.c -I./ -lm -o ex6.unx
*/
/*Per includere i file usare gcc -I./ che include tutti i file nella cartella corrente*/

	// 	CALCOLO VOLUME DELLA SFERA UNITARIA IN FUNZIONE DELLA DIMENSIONE DELLO SPAZIO SU CUI VIVE 
	// LA SFERA.



long double M_Sphere(long double x, int M, long double h)
{	
	long double temp = 0;
	temp = x*x;
	for (int i = 0; i < M-2; ++i)
	{
		temp+= h*h;
	}
	return (long double)sqrt(1-temp);
}

//Provare una funzione ricorsiva ? 

int main(int argc, char const *argv[])
{
	

	if(argc < 3)
	{
		printf("Utilizzo: dimensione-sfera nomefileOutput.txt\n");
	}

	FILE* file;
	file = fopen(argv[2],"w");
	int M = atoi(argv[1]);


	long double a,b;
	a = 0;
	b = 1.0;

	long double h = 1/20.0;

	//Costruisco la matrice con tutte le combinazioni di punti, poi dovro scegliere
	//solo le combinazioni che stanno dentro la sfera.
	long double** points = (long double**)malloc((M-1)*sizeof(long double*));
	for (int i = 0; i < (M-1); ++i)
	{
		points[i] = (long double*)malloc(20*sizeof(long double));
	}


	for (int i = 0; i < M-1; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			points[i][j] = h*(j+1);
		}
	}

	for (int i = 0; i < M-1; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			printf("%Lf\n",points[i][j]);
		}
	}

	//Prova a scrivere i for loop e riscriverla come funzione ricorsiva
	for (int i = 0; i < 20; ++i)
	{
		long double temp_x1 = points[0][i];
		for (int j = 1; j < M-1 ; ++j) //righe 
		{
			for (int k = 0; k < 20; ++k) //colonne
			{
				
			}
		}
	}


	fclose(file);
	
	return 0;
}