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
	EuleroII(fd, 0 , 1 , 0 , 0.1 , 31.41592*50);
	Runge_Kutta2(fd, 0 , 1 , 0 , 0.1 , 31.41592*50);
	return 0;

}