#ifndef COMPLEX_H
#define COMPLEX_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


struct complex {
	double x;
	double y;
};

typedef struct complex complex;

complex make(double x, double y);
complex prod(complex a, complex b);
complex compSub(complex a, complex b);
complex increment(complex a, complex b);
double moduleComplex(complex z);
void printComplex(complex z);

#endif

