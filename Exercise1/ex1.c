// Exercise 1 - Computational Physics 13/10/22 - Edoardo Bertoli - 869024

/*

Note per relazione: 

La somma inversa è più precisa poichè all'inizio sommo numeri molto piccoli con numeri molto piccoli e poi verso la fine
aggiungo numeri più grandi, quindi non perdo precisione. Con la somma diretta invece quando arrivo a sommare gli ultimi numeri
con N grande, gli ultimi (quelli dopo N = 10^-4) non verrano considerati. (Leggi come vengono storate le cifre)

IMPORTANTE: la somma inversa è diversa dalla diretta quando sono all'ordine di grandezza delle
cifre che riesce a mantenere la mantissa, perciò se sono in single point, la mantissa ha 8 elementi, 
perciò quando arrivo a ordini di grandezza di 2^-8 i numeri successivi non vengono sommati, invece
con la somma inversa parto sommando numeri dello stesso ordine di grandezza, quindi sono più preciso
Quello che mi aspetto quindi è che aumentando la precisione il punto di incontro dei due esponenziali
cresca verso N più grandi.
Perciò il punto di inversione è quando finisce la mantissa nella somma diretta è log10(2^(cifremantissa/2))
è l'ordine di grandezza a cui si ferma
*/

#include <stdlib.h>
#include <stdio.h>

// Somma della serie 1/n^2 partendo da n=1 -> fino a n = N
double directSum(int N)
{	
	double sum = 0;
	for (int i = 1; i < N - 1 ; ++i)
	{
		sum += 1.0 /  ( (double)i*(double)i ) ; 
	}

	return sum;
}

// Somma della serie 1/n^2 partendo da n=N -> fino a n = 1
double inverseSum(int N)
{	
	double sum = 0;
	for (int i = N; i > 0 ; --i)
	{
		sum += 1.0 / ( (double)i*(double)i ) ; 
	}

	return sum;
}

int main(int argc, char const *argv[])
{
	if(argc < 5)
	{
		printf("Utilizzo programma: ./ex1.unx [Ni = N iniziale], [Np = passo su cui iterare], [Nf = N finale], [\" Nome file\"]\n");
		exit(EXIT_FAILURE);
	}
		int Ni = atoi(argv[1]); //N iniziale e counter nell'iterazione
		int Np = atoi(argv[2]); //Passo con cui aumento N
		int Nf = atoi(argv[3]); // N finale da raggiungere

		//printf("[double, single precision]-Somma diretta da 1 a %d = %f\n", N, directSum(N));
		//printf("[double, single precision]-Somma inversa da %d a 1 = %f\n", N, inverseSum(N));

		FILE *file;

		file = fopen(argv[4], "w");
		//fprintf(file, "N Diretta Inversa\n");


		while(Ni < Nf){
			
			fprintf(file, "%d,%.20lf,%.20lf\n", Ni, directSum(Ni), inverseSum(Ni));
			Ni+=Np;
			
		}

		fclose(file);
	return 0;
}