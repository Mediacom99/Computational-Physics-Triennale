#include "complex.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>



complex make(double x, double y)
{
	complex z;
	z.x = x;
	z.y = y;
	return z;
}


complex prod(complex a, complex b)
{
	return make(a.x*b.x - a.y*b.y, a.x*b.y + a.y*b.x);
}

complex compSub(complex a, complex b)
{
	return make(a.x-b.x, a.y-b.y);
}

complex increment(complex a, complex b) //a/b
{
	complex result;
	double fact = 1 / (powf(b.x,2) + powf(b.y,2));
	result.x = fact*(a.x*b.x + b.y*a.y);
	result.y = fact*(a.y*b.x - a.x*b.y);
	return result;
}

double moduleComplex(complex z) //|a|
{
	return sqrtf(powf(z.x,2) + powf(z.y,2));
}

void printComplex(complex z)
{
	printf("(%.20f,%.20f)\n",z.x,z.y);
	return;
}