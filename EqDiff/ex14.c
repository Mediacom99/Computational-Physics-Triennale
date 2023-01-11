#include <math.h>
#include <time.h>
#include "eqDiff.h"
#include <stdbool.h>

//Funzione delle y e x, dove y è la soluzione dell'eq diff e x la variabile indipendente
long double T(long double x, long double y)
{
	return -y;
}

int main(int argc, char const *argv[])
{
	EuleroII(T,0,1,0,0.001,1570.796*2);
	return 0;

}