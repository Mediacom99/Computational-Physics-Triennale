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
long double func(long double x)
{	
	
	return x*x + x*sin(4*x);
	
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
	a = -1.0;
	b = 8.0;
	long double result = 169.4821281958237425779343;
	
	/*
	long double s;
	//long double t;
	for(int N = 3; N < 103; N+=2)
	{	

		//t = trapezio(N,a,b,func);
		s = simpson(N,a,b,func);
		//fprintf(file, " %d,%.10Lf,%.10Lf,%.10Lf,%.10Lf\n",N, t, s,fabsl(result-t), fabsl(result - s) );
		// PLOT fprintf(file, "%lf %.20Lf\n",log(1.0/N),logl(fabsl(s-result)));
		fprintf(file, "%lf,%.10Lf\n",log(1.0/N),logl(fabsl(s-result)));
	}
	*/
	
	
	long double legendre;
	//long double laguerre;
	int punti[7] = {1,2,3,4,8,16,48};
	//long double romby;
	//int puntiLag[5] = {2,4,8,24,64};
	//long double A,B;
	
	for (int i = 0; i < 7; ++i)
	{
		legendre = Legendre(punti[i],a,b,func);
		//A = Laguerre(puntiLag[i],-8,func) - Laguerre(puntiLag[i],-3,func);
		//B = Laguerre(puntiLag[i],3,func) - Laguerre(puntiLag[i],8,func);
		//laguerre = 0.5*(A+B);
		//romby = romberg(i,a,b,func);
		fprintf(file, "%d,%.20Lf,%.20Lf\n",punti[i],legendre,fabsl(result-legendre));
	}
	
	/*
	long double ciao;
	ciao = romberg(15,a,b,func);
	fprintf(file,"%Lf\n",ciao);
	//fclose(file);
	*/
	return 0;
}