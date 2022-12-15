#include <integration.h>
#include <math.h>

/*Comando per compilare:
	gcc ex6.c -I./ -lm -o ex6.unx
*/
/*Per includere i file usare gcc -I./ che include tutti i file nella cartella corrente*/
/*
Cosa fare?
1. calcolare l'integrale con tutti i metodi diversi, plottare la deviazione |valore vero-valore calcolato|
 e plottarlo in funzione del numero di punti
 2. Calcolare l'integrale con legendre e laguerre, domanda ? laguerre è più efficiente di legendre?*/
long double func(long double x)
{	
	
	//Da usare con trapezio, simpson e romberg
	return (long double)pow(-log(x),(13.0/2.0)) / 2.0;
}

long double funcL(long double x)
{
	return (long double)pow(x,14)*exp(-x*x + x);
}

long double funcH(long double x)
{
	return (long double)pow(x,14);
}


int main(int argc, char const *argv[])
{
	
	if(argc < 2)
	{
		printf("Utilizzo: nomefileOutput.txt\n");
	}

	FILE* file;
	file = fopen(argv[1],"w");


	long double a,b,d;
	a = 0;
	b = 1.0;
	d = (1.0/1000.0)*(b-a); //Serve per tenere conto della singolarità
	//c = 3;
	long double result = 935.62715289889417323803;
	
	/*
	long double s;
	//long double t5;
	for(int N = 11; N < 1110; N+=120)
	{	

		//t5 = trapezio(N,d,b,func) + open5(a,d,func);
		
		s = simpson(N,d,b,func) + open5(a,d,func);
		//fprintf(file, " %d,%.10Lf,%.10Lf,%.10Lf,%.10Lf\n",N, t, s,fabsl(result-t), fabsl(result - s) );
		// PLOT fprintf(file, "%lf %.20Lf\n",log(1.0/N),logl(fabsl(s-result)));
		fprintf(file, "%d,%.10Lf,%.10Lf\n",N,s,(fabsl(s-result)));
	}
	*/
	
	
	//long double legendre;
	//long double laguerre;
	//int punti[7] = {1,2,3,4,8,16,48};
	//long double romby;
	long double hermite;
	int puntiH[8] = {2,4,5,8,10,24,48,100};
	//int puntiLag[5] = {2,4,8,24,64};
	//long double A,B;
	
	for (int i = 0; i < 8; ++i)
	{
		//legendre = Legendre(punti[i],a,b,func);
		//laguerre = Laguerre(puntiLag[i],0,funcL);
		//B = Laguerre(puntiLag[i],3,func) - Laguerre(puntiLag[i],8,func);
		hermite = Hermite(puntiH[i],0,funcH) / 2.0;
		//romby = romberg(i,d,b,func) + open5(a,d,func);
		fprintf(file, "%d,%.10Lf,%.15Lf\n",puntiH[i],hermite,fabsl(hermite-result));
	}
	

	

	fclose(file);
	
	return 0;
}