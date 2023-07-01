#include <math.h>
#include <stdio.h>
#include <stdlib.h>
/*Comando per compilare:
	gcc ex6.c -I./ -lm -o ex6.unx
*/

//Generatore numeri casuali uniformi tra a e b
long double uniformRandom(long double a, long double b)
{
	return a + (b - a) * rand () / (long double) (RAND_MAX) ;
}

//Cumulativa inversa
long double func(long double y)
{
	return sqrt(-log(1-2*y));
}

int main(int argc, char const *argv[])
{
	
	if(argc < 2)
	{
		printf("Utilizzo: nomefileOutput.txt\n");
	}

	FILE* file;
	file = fopen(argv[1],"w");
	long double a = 0;
	long double b = 0.5;
	int N = 100000;

	for (int i = 0; i < N; ++i)
	{
		fprintf(file, "%.10Lf\n",func(uniformRandom(a,b)));
	}

	

	fclose(file);
	
	return 0;
}