#include <math.h>
#include <time.h>
#include "eqDiff.h"

// x segue la funzione soluzione, y segue la derivata, z la variabile indipendente
//fd è la funzione sull'eq differenziale della derivata
//ff è la funzione sull'eq differenziale della soluzione
long double fd(long double x, long double y, long double z)
{
	return -x;
}


int main(int argc, char const *argv[])
{
	EuleroII(fd,0,1,0,0.01,157.0796*2);
	//Runge_Kutta2(ff,fd,0,1,0,0.001,1570.796);
	return 0;

}