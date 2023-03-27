#include <math.h>
#include <time.h>
#include "eqDiff.h"

//Esercizio 15, stesso main del 14, cambio solo la funzione fd per tenere conto dei diversi componenti dell'eq che 
// voglio risolvere. 

// x segue la funzione soluzione (f(t)), y segue la derivata(df/dt), z la variabile indipendente (t)
//fd è la funzione sull'eq differenziale della derivata
//ff è la funzione sull'eq differenziale della soluzione

/*
Pendolo completo:
long double fd(long double x, long double y, long double z)
{
	return -sin(x);
}
*/

/*
// Pendolo completo + attrito
long double fd(long double x, long double y, long double z)
{
	return -sin(x) - 0.1*y;
}
*/

// Pendolo completo + attrito +  forzante
long double fd(long double x, long double y, long double z)
{
	return -sin(x) - 0.5*y + 0.1*sin((2.0/3.0)*z);
}

int main(int argc, char const *argv[])
{	
	
	long double f0 = 0; //Dato iniziale soluzione
	long double df0 = 1; //Dato iniziale derivata soluzione
	long double T = 15.70796327*4;
	long double h = 0.01;
	long double n = T/h;
	EuleroII(fd, f0, df0 , 0 , h ,n);
	Runge_Kutta2(fd, f0 , df0 , 0 , h ,n);
	Runge_Kutta4(fd,f0,df0,0,h,n);
	
	return 0;

}