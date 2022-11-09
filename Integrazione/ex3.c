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
	return pow(x,7)*exp(-x);
	
}

int main(int argc, char const *argv[])
{
	
	if(argc < 2)
	{
		printf("Utilizzo: nomefileOutput.txt\n");
	}

	FILE* file;
	file = fopen(argv[1],"w");

	//Per trapezio e Simpson faccio da N = 100 a N = 10000 con passi di 100
	/*Format print N - trapezio - simpson - discrepanza Trapezio(|Wolfram-mio|) - discrepanza Simpson */
	long double a,b;
	a = 0;
	b = 5.0;
	long double result = 672.19323731283680927664;
	long double s;
	//long double t;
	for(int N = 3; N < 150; N+=3)
	{	
		//t = trapezio(N,a,b,func);
		s = simpson(N,a,b,func);
		//fprintf(file, " %d,%.20Lf,%.20Lf,%.20Lf,%.20Lf\n",N, t, s,fabsl(result-t), fabsl(result - s) );
		fprintf(file, " %lf,%.20Lf,%.20Lf\n",1/(double)N,s,fabsl(result-s));
		
	}

	return 0;
}