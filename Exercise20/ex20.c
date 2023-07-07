#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex.h"




complex f(complex x)
{	
	
	complex result = prod(prod(x,x),x);
	result.x -= 1.0;
	return result;
}

//funzioni derivate di f per newton-raphson
complex df(complex x)
{
	complex result = prod(x,x);
	result.x*=3;
	result.y*=3;
	return result;
}





//Newton raphson per eq complesse

int newton(complex(*func)(complex), complex(*dfunc)(complex), complex z, double xacc)
{

	const int KMAX = 100;
	complex rtn = z;
	complex f,df,dx;
	for (int k = 0; k < KMAX; ++k)
	{	
		f=func(rtn);
		df = dfunc(rtn);
		dx = increment(f,df); //f/df
		rtn = compSub(rtn,dx); //rtn-=dx
		if(moduleComplex(dx) < xacc) //volendo potresti fare il modulo di rtn
		{	
			printComplex(rtn);
			return k;

		}
	}
	exit(EXIT_FAILURE);
}



int main(int argc, char const *argv[])
{	
	FILE* file = fopen("data.txt","w");

	double xacc = powf(10,-5); //epsilon
	complex z = make(1.2,0.0); //punto iniziale
	int j = newton(f,df,z,xacc);
	printf("Tot steps: %d\n",j);


	

	
	fclose(file);
	return 0;
}