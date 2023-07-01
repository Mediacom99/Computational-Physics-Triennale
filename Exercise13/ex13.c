#include <integration.h>
#define _USE_MATH_DEFINES 
#include <math.h>

/*Comando per compilare:
	gcc ex10.c -I./ -lm -o ex10.unx
*/
long double func(long double x)
{	
	return 2*acos(1-2*x);
}



int main(int argc, char const *argv[])
{
	
	if(argc < 2)
	{
		printf("Utilizzo: nomefileOutput.txt\n");
	}

	FILE* file;
	file = fopen(argv[1],"w");
	int N = pow(2,22);
	long double pi = 3.14159265358979323846;
	long double exp;
	long double result = pi;
	for (int i = 2; i < N; i*=2)
	{
		exp = monteCarlo(i,0,1,func);
		fprintf(file, "%d,%.10Lf,%.10Lf\n", i, exp, fabsl(result - exp));	
	}
	fclose(file);
	return 0;
}