#include <math.h>
#include <time.h>
#include "eqDiff.h"

// x segue la funzione soluzione (f(t)), y segue la derivata(df/dt), z la variabile indipendente (t)
//fd è la funzione sull'eq differenziale della derivata
//ff è la funzione sull'eq differenziale della soluzione
long double fd(long double x, long double y, long double z)
{
	return -x;
}


int main(int argc, char const *argv[])
{	
	/*
	long double T = 1.570796327;
	long double h = 0.9;
	long double n = T/h;
	EuleroII(fd, 0 , 1 , 0 , h ,n);
	Runge_Kutta2(fd, 0 , 1 , 0 , h ,n);
	Runge_Kutta4(fd,0,1,0,h,n);
	*/
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
	return 0;

}