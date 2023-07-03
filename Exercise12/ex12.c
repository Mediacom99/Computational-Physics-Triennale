#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

const long double rp = 1.77245385091; //square root pi
const long double p = 3.14159265358979;
//Generatore numeri casuali tra a e b
long double uniformRandom(long double a, long double b)
{
	return a + (b - a) * rand () / (long double) (RAND_MAX) ;
}

long double cumulativaEsatta(long double y, long double k)
{
	return sqrtl(-logl(y))*cos(2*p*k);
}



long double cumulativaInversa(long double y)
{	
	if(y < (1/rp))
	{
		return rp*y;
	}else{

	return sqrtl(1-logl(3-2*rp*y));
	}
}


long double f(long double x)
{
	return (1/(rp))*exp(-x*x);
}

long double g(long double x)
{
	if (x < 1 && x > 0)
	{
		return (1/rp);
	}else{
		return (1/rp)*x*exp(1-x*x); 
	}
}

long double reject()
{
	int sgn;
	if(rand()%2==0){
		sgn = +1;
	}else{
		sgn=-1;
	}
	long double check = 0;
	long double value = 0;
	for (int i = 0; i < 100; ++i)
	{
		
		value = cumulativaInversa(uniformRandom(0,1.5*rp));
		check = f(value) / g(value);
		if (check > uniformRandom(0,1))
		{
			return sgn*value;
		}
	}
	return NAN;
}



int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		printf("Utilizzo: nomeProg nomeFile_output\n");
		exit(EXIT_FAILURE);
	}

	FILE* file;
	file = fopen(argv[1],"w");
	int N = 100000;

	/*
	//Metodo esatto
	for (int i = 0; i < N; ++i)
	{
		fprintf(file, "%.10Lf\n", cumulativaEsatta(uniformRandom(0,1),uniformRandom(0,1)));
	}
	*/


	//Accept-Reject
	
	
	
	for (int i = 0; i < N; ++i)
	{
		fprintf(file, "%.10LF\n",reject());
		
	}
	


	fclose(file);
	return 0;
}