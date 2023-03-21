#include <math.h>
#include <time.h>
#include "eqDiff.h"

//Esercizio 15, stesso main del 14, cambio solo la funzione fd per tenere conto dei diversi componenti dell'eq che 
// voglio risolvere. 

// x segue la funzione soluzione (f(t)), y segue la derivata(df/dt), z la variabile indipendente (t)
//fd è la funzione sull'eq differenziale della derivata
//ff è la funzione sull'eq differenziale della soluzione
long double fd(long double x, long double y, long double z)
{
	return -sin(x);
}


int main(int argc, char const *argv[])
{	
	
	long double f0 = 0; //Dato iniziale soluzione
	long double df0 = 1; //Dato iniziale derivata soluzione
	long double T = 15.70796327*4;
	long double h = 0.1;
	long double n = T/h;
	EuleroII(fd, f0, df0 , 0 , h ,n);
	Runge_Kutta2(fd, f0 , df0 , 0 , h ,n);
	Runge_Kutta4(fd,f0,df0,0,h,n);
	
	//Questa parte serve per il grafico della deviazione dell'esericizio 14
	/*
	FILE* Etxt = fopen("devsE.txt","w");

	FILE* RK2txt = fopen("devsRK2.txt","w");

	FILE* RK4txt = fopen("devsRK4.txt","w");

	FILE* htxt = fopen("h.txt","w");

	long double T = 1.570796327;
	long double h = 0.01;
	while(h <= 0.5)
	{
	fprintf(htxt, "%.20Lf\n", logl(fabsl(h)));
	long double n = T/h;
	EuleroII(fd, 0 , 1 , 0 , h ,n, Etxt);
	Runge_Kutta2(fd, 0 , 1 , 0 , h ,n, RK2txt);
	Runge_Kutta4(fd,0,1,0,h,n, RK4txt);
	h+=0.01;
	}
	fclose(Etxt);
	fclose(RK2txt);
	fclose(RK4txt);
	*/
	return 0;

}