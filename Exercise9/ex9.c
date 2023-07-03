#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

//Generatore numeri casuali tra a e b
long double uniformRandom(long double a, long double b)
{
	return a + (b - a) * rand () / (long double) (RAND_MAX) ;
}

long double bernoulliTrial(int N)
{	
	int value = 0;
	long double result = 0;
	for (int i = 0; i < N; ++i)
		{
				
			value = rand();
			if(value%2 == 0)
			{
				result+=1.0;
			}else{
				result+=-1.0;
			}
		}
	
	return 	result/(long double) N;
}

long double meanCalc(int N)
{	
	long double result = 0;
	for (int i = 0; i < N; ++i)
	{
		result+=uniformRandom(-1,1);
	}
	return result/(long double) N;
}

int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		printf("Utilizzo: nomeProg nomeFile_output\n");
		exit(EXIT_FAILURE);
	}

	FILE* file;
	file = fopen(argv[1],"w");

	// size campione
	int N = 1000000;
	//Numero di valori generati con cui plotto l'istogramma;
	int K = 1000;

	long double var1 = 0;
	long double var2 = 0;

	/*
	for (int i = 0; i < K; ++i)
	{
		//Valore uniforme, valore bernoulliTrial
		fprintf(file, "%.10Lf %.10Lf\n", meanCalc(N), bernoulliTrial(N));

	}
	*/
	long double n1,n2 = 0;
	for (int n = 10; n < N; n*=10)
	{
			for (int j = 0; j < K; ++j)
			{
			//Valore uniforme, valore bernoulliTrial
			//fprintf(file, "%.10Lf %.10Lf\n", meanCalc(N), bernoulliTrial(N));
			//var1+= pow(meanCalc(n),2);
			var2+=pow(bernoulliTrial(n),2);
			}
			//var1/=(long double)K;
			var2/=(long double)K;
			//fprintf(file, "%.10Lf, %f\n", logl(sqrtl(var2)), log(1/(n)));
			// M42,N1, M64,N2
			n1 = 3 / ((long double)pow(n,2) );
			n2 = 5.0 / ((long double)pow(n,2) );
			fprintf(file, "%.20LF, %.20f, %.20LF, %.20f\n", logl(3*powl(var2,2)), log(n1), logl(5*powl(var2,2)), log(n2));
	}


	fclose(file);
	return 0;
}