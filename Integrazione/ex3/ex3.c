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
	return pow(x,7);
}

int main(int argc, char const *argv[])
{
	
	if(argc < 2)
	{
		printf("Utilizzo: nomefileOutput.txt\n");
	}

	FILE* file;
	file = fopen(argv[1],"w");


	long double a,b;
	a = 0;
	b = 5.0;
	long double result = 672.19323731283680927664;
	
	/*
	long double s;
	long double t;
	for(int N = 3; N < 103; N+=20)
	{	

		t = trapezio(N,a,b,func);
		s = simpson(N,a,b,func);
		fprintf(file, " %d,%.10Lf,%.10Lf,%.10Lf,%.10Lf\n",N, t, s,fabsl(result-t), fabsl(result - s) );
		//fprintf(file, "%Lf,%.20Lf,%.20Lf\n",logl(1/(long double)N),t,logl(fabsl(result-t)));
		
	}
	*/

	//long double legendre;
	long double laguerre;
	//int punti[7] = {1,2,3,4,8,16,48};
	int punti[5] = {2,4,8,24,64};
	for (int i = 0; i < 5; ++i)
	{
		//legendre = Legendre(punti[i],a,b,func);
		laguerre = Laguerre(punti[i],a,func) - Laguerre(punti[i],b,func);
		fprintf(file, "%d,%.20Lf,%.20Lf\n",punti[i],laguerre,fabsl(result-laguerre));
	}

	return 0;
}