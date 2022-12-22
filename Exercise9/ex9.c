#include <integration.h>
#include <math.h>
#include <time.h>



int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		printf("Utilizzo: nomeProg nomeFile_output numeroPunti\n");
		exit(EXIT_FAILURE);
	}

	FILE* file;
	file = fopen(argv[1],"w");

	int N = atoi(argv[2]);

	long double mean = 0.0;
	long double mom2 = 0.0;
	long double temp;
	for (int i = 0; i < N; ++i)
	{	
		temp = gauss(-1,1,100);
		fprintf(file, "%.5Lf\n",temp);
		mean+=temp;
		mom2+=temp*temp;
	}
	mean/=N;
	mom2/=N;
	printf("Media della gaussiana: %.5Lf\n",mean);
	printf("Varianza della gaussiana: %.5Lf\n",mom2);




	fclose(file);
	return 0;
}