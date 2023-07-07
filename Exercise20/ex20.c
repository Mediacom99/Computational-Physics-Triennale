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
		//printComplex(dx);
		rtn = compSub(rtn,dx); //rtn-=dx
		if(moduleComplex(dx) < xacc) //volendo potresti fare il modulo di rtn
		{	
			return k;

		}
	}
	
	return 0;
}



int main(int argc, char const *argv[])
{	
	FILE* file = fopen("data.txt","w");

	//Griglia di punti
	int N = 2000;
	double h = 4.0 / N;


	double xacc = powf(10,-3); //epsilon
	complex z = make(-2.0,-2.0); //punto iniziale

	
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{	
			if (j == N-1)
			{
				fprintf(file,"%d\n",newton(f,df,z,xacc));
				continue;
			}
				fprintf(file, "%d,",newton(f,df,z,xacc));
			z.x += h;
		}
		z.x = -2.0;
		z.y+=h;
	}
	
	fclose(file);
	return 0;
}