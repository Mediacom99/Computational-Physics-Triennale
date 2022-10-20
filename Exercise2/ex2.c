/* Esercizio 2 - Fisica Computazionale - 19/10/2022 - Edoardo Bertoli - 869024 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Idea della parte 2: epsilon nella quadrupla viene contato perchè ha tanti bit nella mantissa
mentre nella singola epsilon è troppo piccolo e viene troncato, perciò se paragono l'esponenziale
in precisione singola con l'esponenziale in precisione quadrupla con epsilon = 10^(-8) allora
i due esponenziali dovrebbero sovrapporsi perchè la quadrupla simula la singola, mentre se epsilon 
lo prendo più piccolo allora le due rette si staccano perchè la singola non ci sta più dietro 
a quella precisione
DA FARE: metto i grafici per verificare andamento esponenziale
		 metto i due grafici con epsilon diversi e spiego perchè*/

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
	if (argc < 5)
	{
		printf("Utilizzo prog: ./ex2.unx [Passo di N] [N totale da raggiungere] [Starting point] [Nome file dei dati]\n");
		exit(EXIT_FAILURE);
	}
	int passo = atoi(argv[1]);
	int N = atoi(argv[2]);
	int startPoint = atoi(argv[3]);
	FILE* file = fopen(argv[4], "w");
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