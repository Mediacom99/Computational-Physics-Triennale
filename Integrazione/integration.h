/* File header contenente tutti i metodi di integrazione da utilizzare per gli esercizi 3-4-5-6-7-8*/
// Edoardo Bertoli - Lab. Fisica Computazionale - 869024

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Regola del trapezio: si basa sull'espansione di taylor in uno dei N punti scelti, integrali solo su
intervallo finito */
// N = numero di punti su cui eseguire l'integrazione, a e b sono gli estremi di integraziobe
//Punti equidistanziati h = (b-a) / N, func è un puntatore alla funzione da usare
//accedere a funzione passata come parametro (*func)(input)
//INTEGRAZIONE DEL TRAPEZIO
long double trapezio(int N, long double a, long double b, long double (*func)(long double))
{

	long double h = (b-a) / (long double)(N-1) ;
	long double result = 0.0;
	result += func(a)*0.5; //aggiungo 1/2 f(a)
	long double point = a+h;
	while(point < b){
	
		result+=func(point);
		point+=h;
		//printf("%Lf\n",point);
	}
	result+= func(b)*0.5; //aggiungo 1/2 f(b)
	result*=h;

	return result;
}

//INTEGRAZIONE DI SIMPSON
long double simpson(int N, long double a, long double b, long double (*func)(long double))
{
	long double h = (b-a) / (long double)(N-1) ;
	long double result = 0.0;
	result+= func(a);
	long double point = a+h;
	for (int i = 2; i <= N-2; ++i)
	{
		if(i%2 == 0) //se siamo al passo pari moltiplica per 4, altrimenti per 2
		{
			result+=4*func(point);
		}
		else
		{
			result+=2*func(point);
		}
		point+=h;
	}
	result+=func(b);
	result*=(h/3);
	return result;	
}