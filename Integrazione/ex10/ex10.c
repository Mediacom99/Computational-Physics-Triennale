#include <integration.h>
#include <math.h>

/*Comando per compilare:
	gcc ex5.c -I./ -lm -o ex5.unx
*/
/*Per includere i file usare gcc -I./ che include tutti i file nella cartella corrente*/
/*
Cosa fare?
1. calcolare l'integrale con tutti i metodi diversi, plottare la deviazione |valore vero-valore calcolato|
 e plottarlo in funzione del numero di punti
 2. Calcolare l'integrale con legendre e laguerre, domanda ? laguerre è più efficiente di legendre?*/
long double func1(long double x)
{	
	
	return pow(x,7)*exp(-x);
	
}

long double func2(long double x)
{
	return cosh(x);
}

long double func3(long double x)
{
	return pow(x,2) + x*sin(4*x);
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
	long double result = 169.4821281958;
	a = -1;
	b = 8;
	int N = 10000000;

	long double max3 = (b+1)*(b+1) + b+1;
	//long double resultM = monteCarlo(N,a,b,func1);
	//long double resultHM = hit_or_miss(N,a,b,func1,func1(b));

	for (int i = 2; i < N; i*=2)
	{	
		// log Delta Montecarlo -  log delta HM - log(1/N)
		
		fprintf(file, "%.10Lf,%.10Lf,%.10Lf\n", logl(fabsl(result - monteCarlo(i,a,b,func3))), 
			logl(fabsl(result - hit_or_miss(i,a,b,func3,max3))), 
			logl(1/(long double)i));	
			
		/*
		fprintf(file, "%.10Lf,%.10Lf,%.10Lf\n", monteCarlo(i,a,b,func1), 
			hit_or_miss(i,a,b,func1,func1(b)), 
			logl(1/(long double)i));	
			*/
	}
	//fprintf(file, "Monte: %.10Lf\nHit: %.10Lf",resultM,resultHM);

	fclose(file);
	
	return 0;
}