/* Esercizio 2 - Fisica Computazionale - 19/10/2022 - Edoardo Bertoli - 869024 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>



float chin(int n)
{
	float chimeno = 1;
	float chin = (sqrt(5.0) - 1) / 2.0;
	if(n == 1)
	{
		return chin;
	}else if(n == 0)
	{
		return 1;
	}
	n = n-2; //comodità per sincronizzare con funzione phin
	float sum = chimeno - chin;

	for (int i = 0; i < n; ++i)
	{	
		
	chimeno = chin;
	chin = sum;
	sum = chimeno - chin;

	}
	return sum;
}


//Funzione che calcola phi^n moltiplicandolo n volte per sè stesso
float phin(int n)
{
	float phi = (sqrt(5.0) - 1) / 2.0;
	float prod = 1;
	for (int i = 0; i < n; ++i)
	{
		prod*=phi;
	}

	return prod;
}


int main(int argc, char const *argv[])
{	
	if (argc < 4)
	{
		printf("Utilizzo prog: ./ex2.unx [Passo di N] [N totale da raggiungere] [Starting point]\n");
		exit(EXIT_FAILURE);
	}
	int passo = atoi(argv[1]);
	int N = atoi(argv[2]);
	int startPoint = atoi(argv[3]);
	FILE* file = fopen("data.txt", "w");
	int counter = startPoint;
	while(counter < N)
	{
		fprintf(file, "%f,%d\n", fabs(chin(counter) - phin(counter)), counter);
		counter+=passo;
	}
	//printf("%f, %f\n",chin(1), phin(1) );
	return 0;
}