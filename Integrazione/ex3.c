#include <integration.h>
#include <math.h>

/*Comando per compilare:
	gcc ex3.c -I./ -lm -o ex3.unx
*/
/*Per includere i file usare gcc -I./ che include tutti i file nella cartella corrente*/
/*
Cosa fare?
1. calcolare l'integrale con tutti i metodi diversi, plottare la deviazione |valore vero-valore calcolato|
 e plottarlo in funzione del numero di punti
 2. Calcolare l'integrale con legendre e laguerre, domanda ? laguerre è più efficiente di legendre?*/
long double func(long double x)
{
	//return pow(x,7)*exp(-x);
	return pow(x,5)*exp(-x*x + x);
	
}

int main(int argc, char const *argv[])
{
		printf("Metodi di integrazione:\nTrapezio = 1\nSimpson = 2\nRomberg = 3\nLegendre = 4\nLaguerre = 5\nHermite = 6\n");
		printf("NOTA BENE: per romberg indicare nella posizione del numero di punti il numero di suddivisioni da fare, cioè 2^(J), indicare J\n");
		printf("\n\n\nNumero punti disponibili:\n");
		printf("Legendre: 1,2,3,4,8,16,48\n");
		printf("Laguerre: 2,4,8,24,64\n");
		printf("Hermite: 2,4,5,8,10,24,48,100\n");
	if(argc<3)
	{
		printf("Utilizzo: ./ex3.unx [N = numero pti integrazione] [Type of integration method (1-4)]\n");
		printf("exiting...\n");
		exit(EXIT_FAILURE);
	}
	int N = atoi(argv[1]); //Numero di punti su cui dividere l'intervallo e integrare
	int method = atoi(argv[2]);

	if(method!=3)
	{
		printf("Numero di punti utilizzati: %d\n",N);
	}else{
		printf("Valore suddivisione intervalli: 2^(%d)\n",N);
	}

	if(method == 1)
	{
		printf("Metodo del trapezio, risultato: %.20Lf\n",trapezio(N,0,5,func));
	}
	else if(method == 2)
	{
		printf("Metodo di Simpson, risultato: %.20Lf\n",simpson(N,0,5,func));
	}
	else if(method == 3)
	{	
		//printf("Numero punti utilizzati: %d\n", (int)(pow(2,N)+1));
		printf("\n\nMetodo di romberg, risultato: %.20Lf\n", romberg(N,0,5,func));
	}
	else if(method==4)
	{
		printf("\n\nMetodo di Gauss, Legendre, risultato: %.20Lf\n", Legendre(N,0,5,func));
	}
	else if (method==5)
	{	
		//RICORDA DI TOGLIERE IL PESO EXP DALLA FUNZIONE FUNC
		printf("\n\nMetodo di Gauss, Laguerre, risultato: %.20Lf\n", Laguerre(N,3,func));
	}
	else if (method == 6)
	{
		//RICORDA DI TOGLIERE IL PESO E^-X2 DALLA FUNZIONE FUNC
		printf("\n\nMetodo di Gauss, Hermite, risultato: %.20Lf\n", Hermite(N,3,func));
	}
	else
	{
		printf("NOT IMPLEMENTED YET, exiting...\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}