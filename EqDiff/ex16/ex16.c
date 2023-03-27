#include <math.h>
#include <time.h>
#include "eqDiff.h"

//Esercizio 16

// x segue la funzione soluzione (f(t)), y segue la derivata(df/dt), z la variabile indipendente (t)
//fd è la funzione sull'eq differenziale della derivata
//ff è la funzione sull'eq differenziale della soluzione



long double fd(long double x, long double y, long double z)
{

	return -0.03*y - (0.5-0.63*cos(z))*(sin(x));
}

int main(int argc, char const *argv[])
{	
	
	long double f0 = 0; //Dato iniziale soluzione
	long double df0 = 0.1; //Dato iniziale derivata soluzione
	//long double T = 15.70796327*4;
	long double T = 300;
	long double h = 0.01;
	long double n = T/h;
	EuleroII(fd, f0, df0 , 0 , h ,n);
	Runge_Kutta2(fd, f0 , df0 , 0 , h ,n);
	Runge_Kutta4(fd,f0,df0,0,h,n);
	
	return 0;

}