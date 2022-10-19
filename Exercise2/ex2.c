/* Esercizio 2 - Fisica Computazionale - 19/10/2022 - Edoardo Bertoli - 869024 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Idea: all'inizio ho x = phi1 + ephi2, man mano che applico la formula ricorsiva il peso di phi2 
aumenta al punto da superare phi1, quindi la differenza tra i due cresce esponenzialmente con n */

long double chin(int n)
{
	long double chimeno = 1;
	long double chin = ((sqrt(5.0) - 1) / 2.0) - 0.00000001*((sqrt(5.0) + 1) / 2.0);
	if(n == 1)
	{
		return chin;
	}else if(n == 0)
	{
		return 1;
	}
	n = n-2; //comodità per sincronizzare con funzione phin
	long double sum = chimeno - chin;

	for (int i = 0; i < n; ++i)
	{	
		
	chimeno = chin;
	chin = sum;
	sum = chimeno - chin;

	}
	return sum;
}


//Funzione che calcola phi^n moltiplicandolo n volte per sè stesso
long double phin(int n)
{
	long double phi = (sqrt(5.0) - 1) / 2.0;
	long double prod = 1;
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
	long double result;
	while(counter < N)
	{
	result = chin(counter) - phin(counter); //Serve per fare valore assoluto in long double
	if(result < 0)
	{
		result = -1*result;
	}
		fprintf(file, "%Lf,%d\n", result, counter);
		counter+=passo;
	}
	//printf("%f, %f\n",chin(1), phin(1) );
	return 0;
}