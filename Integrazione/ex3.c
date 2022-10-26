#include <integration.h>
#include <math.h>

/*Per includere i file usare gcc -I./ che include tutti i file nella cartella corrente*/
/*
Cosa fare?
1. calcolare l'integrale con tutti i metodi diversi, plottare la deviazione |valore vero-valore calcolato|
 e plottarlo in funzione del numero di punti
 2. Calcolare l'integrale con legendre e laguerre, domanda ? laguerre è più efficiente di legendre?*/
long double func(long double x)
{
	return pow(x,7)*exp(-x);
}

int main(int argc, char const *argv[])
{
	if(argc<3)
	{
		printf("Utilizzo: ./ex3.unx [N = numero pti integrazione] [Type of integration method (1-4)]\n");
		printf("Metodi di integrazione:\nTrapezio = 1\nSimpson = 2\nRomberg = 3\nGauss = 4\n");
		printf("exiting...\n");
		exit(EXIT_FAILURE);
	}
	int N = atoi(argv[1]); //Numero di punti su cui dividere l'intervallo e integrare
	printf("Numero di punti scelti: %d\n",N);
	int method = atoi(argv[2]);
	if(method == 1)
	{
		printf("Metodo del trapezio, risultato: %Lf\n",trapezio(N,0,5,func));
	}
	else if(method == 2)
	{
		printf("Metodo di Simpson, risultato: %Lf\n",simpson(N,0,5,func));
	}
	else
	{
		printf("NOT IMPLEMENTED YET, exiting...\n");
		exit(EXIT_FAILURE);
	}
	
	return 0;
}