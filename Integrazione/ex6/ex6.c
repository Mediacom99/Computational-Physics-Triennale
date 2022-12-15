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
	
	//return pow(x,5)*exp(-x*x);
	return logl(x)*logl(x)*0.5;
}

long double funcL(long double x)
{
	return (long double)pow(x,5)*exp(-x*x + x);
}

//Taglio e incollo la funzione in modo da poter integrare con hermite, dividere per due il risultato
// e ottenere l'integrale iniziale.
long double funcCollage(long double x)
{	
	if(x>=0)
	{
		return (long double)pow((x+3),5)*exp(- 6*x - 9);
	}else{
		return (long double)pow((-x+3),5)*exp(- 6*(-x) - 9);
	}
}

int main(int argc, char const *argv[])
{
	
	if(argc < 2)
	{
		printf("Utilizzo: nomefileOutput.txt\n");
	}

	FILE* file;
	file = fopen(argv[1],"w");


	long double a,b,c,d;
	a = 0;
	b = 1.0 / exp(9.0);
	d = (1.0/20.0)*(b-a); //Serve per tenere conto della singolarità
	//c = 3;
	long double result = 0.006232195106377317249630653;
	
	/*
	long double s;
	//long double t3,t5;
	for(int N = 11; N < 111; N+=12)
	{	

		//t5 = trapezio(N,d,b,func) + open5(a,d,func);
		//t3 = trapezio(N,d,b,func) + open3(a,d,func);
		s = simpson(N,d,b,func) + open5(a,d,func);
		//fprintf(file, " %d,%.10Lf,%.10Lf,%.10Lf,%.10Lf\n",N, t, s,fabsl(result-t), fabsl(result - s) );
		// PLOT fprintf(file, "%lf %.20Lf\n",log(1.0/N),logl(fabsl(s-result)));
		fprintf(file, "%d,%.10Lf,%.10Lf\n",N,s,(fabsl(s-result)));
	}
	*/
	
	
	//long double legendre;
	long double laguerre;
	//int punti[7] = {1,2,3,4,8,16,48};
	//long double romby;
	//long double hermite;
	//int puntiH[8] = {2,4,5,8,10,24,48,100};
	int puntiLag[5] = {2,4,8,24,64};
	//long double A,B;
	
	for (int i = 0; i < 5; ++i)
	{
		//legendre = Legendre(punti[i],a,b,func);
		laguerre = Laguerre(puntiLag[i],3,funcL);
		//B = Laguerre(puntiLag[i],3,func) - Laguerre(puntiLag[i],8,func);
		//hermite = Hermite(puntiH[i],0,funcCollage) / 2.0;
		//romby = romberg(i,d,b,func) + open5(a,d,func);
		fprintf(file, "%d,%.10Lf,%.15Lf\n",puntiLag[i],laguerre,fabsl(result-laguerre));
	}
	

	/*
	long double ciao;
	ciao = romberg(15,a,b,func);
	fprintf(file,"%Lf\n",ciao);
	//fclose(file);
	*/
	return 0;
}