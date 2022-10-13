// Exercise 1 - Computational Physics 13/10/22 - Edoardo Bertoli - 869024

/*

Note per relazione: 

La somma inversa è più precisa poichè all'inizio sommo numeri molto piccoli con numeri molto piccoli e poi verso la fine
aggiungo numeri più grandi, quindi non perdo precisione. Con la somma diretta invece quando arrivo a sommare gli ultimi numeri
con N grande, gli ultimi (quelli dopo N = 10^-4) non verrano considerati. (Leggi come vengono storate le cifre)

*/

#include <stdlib.h>
#include <stdio.h>

// Somma della serie 1/n^2 partendo da n=1 -> fino a n = N
float directSum(int N)
{	
	float sum = 0;
	for (int i = 1; i < N - 1 ; ++i)
	{
		sum += 1 / (float)(i*i) ; 
	}

	return sum;
}

// Somma della serie 1/n^2 partendo da n=N -> fino a n = 1
float inverseSum(int N)
{	
	float sum = 0;
	for (int i = N; i > 0 ; --i)
	{
		sum += 1 / (float)(i*i) ; 
	}

	return sum;
}

int main(int argc, char const *argv[])
{
	if(argc < 4)
	{
		printf("Utilizzo programma: ./ex1.unx [Ni = N iniziale], [Np = passo su cui iterare], [Nf = N finale]\n");
		exit(EXIT_FAILURE);
	}
		int Ni = atoi(argv[1]); //N iniziale e counter nell'iterazione
		int Np = atoi(argv[2]); //Passo con cui aumento N
		int Nf = atoi(argv[3]); // N finale da raggiungere

		//printf("[Float, single precision]-Somma diretta da 1 a %d = %f\n", N, directSum(N));
		//printf("[Float, single precision]-Somma inversa da %d a 1 = %f\n", N, inverseSum(N));

		FILE *file;

		file = fopen("data.txt", "w");
		//fprintf(file, "N Diretta Inversa\n");

		while(Ni < Nf){
			
			fprintf(file, "%d,%f,%f\n", Ni, directSum(Ni), inverseSum(Ni));
			Ni+=Np;
			
		}

		fclose(file);
	return 0;
}