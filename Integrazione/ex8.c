#include <integration.h>
#include <math.h>

//Algoritmi perm e combinations presi da: https://people.engr.tamu.edu/djimenez/ut/utsa/cs3343/lecture25.html

/*Comando per compilare:
	gcc ex6.c -I./ -lm -o ex6.unx
*/
/*Per includere i file usare gcc -I./ che include tutti i file nella cartella corrente*/

	// 	CALCOLO VOLUME DELLA SFERA UNITARIA IN FUNZIONE DELLA DIMENSIONE DELLO SPAZIO SU CUI VIVE 
	// LA SFERA.

//passo integrazione: numero totale elementi
//dimensione della sfera: numero di elementi nel singolo gruppo 

//Passo integrazione (passo punti)
	const long double passo = 5000.0;
	const long double h = 1/passo;
	long double result = 0.0;

void printVector(long double* vec, int M)
{	
	printf("Printing... ");
	for (int i = 0; i < M; ++i)
	{
		printf("[%.4Lf]-",vec[i]);
	}
	printf("\n");
	return;
}


long double M_Sphere(int M, long double* comb)
{
	long double squares = 0.;
	//Calcolo somma dei quadrati
	for (int i = 0; i < M-1; ++i)
	{
		squares+= comb[i]*comb[i];
	}
	if(squares <= 1)
	{
		return sqrtl(1-squares);
	}
	else
	{
		return 0;
	}
}



void swap (long double* v, int i, int j) 
{
	long double	t;
	t = v[i];
	v[i] = v[j];
	v[j] = t;
	return;
}

void multiply(long double* v, int dim, int h)
{
	for (int i = 0; i < dim; ++i)
	{
		v[i]*=h;
	}
	return;
}

void perm (long double* v, int n, int i) 
{

	int	j;

	if (i == n) {

		/*
		for (j=0; j<n; j++) printf ("%.4Lf ", v[j]);
		printf ("\n");
		*/
		long double* temp = (long double*)malloc(n*sizeof(long double));
		for (int i = 0; i < n; ++i)
		{
			temp[i] = h*v[i];
		}
		result+=pow(h,n)*M_Sphere(n+1,temp);
		free(temp);
	} else{

			for (j=i; j<n; j++) {


				swap (v, i, j);
				perm (v, n, i+1);


				swap (v, i, j);
			}
		}
}

void combinations(long double* v, int start, int n, int k, int maxk)
{
	int i;
	if(k>maxk)
	{	
		long double* temp = (long double*)malloc(maxk*sizeof(long double));
		//printVector(v,maxk);
		for (int i = 1; i <= maxk; i++)
		{
			//printf("%.4Lf ",v[i] );
			temp[i-1] = v[i];
		}
		perm(temp,maxk,0);
		free(temp);
		return;
	}

	for(i=start; i<=n; i++)
	{
		//v[k] = (i+1)*h - h/2.0;
		v[k] = i;
		combinations(v, i+1,n,k+1, maxk);
	}
}


//Provare una funzione ricorsiva ? 

int main(int argc, char const *argv[])
{
	

	if(argc < 3)
	{
		printf("Utilizzo: dimensione-sfera nomefileOutput.txt\n");
	}

	FILE* file;
	file = fopen(argv[2],"w");
	int M = atoi(argv[1]);
	//long double* comb = (long double*)malloc((M-1)*sizeof(long double)); //Combinations to feed into func

	//Vettore con i possibili valori da permutare
	long double* values = (long double*)malloc(passo*sizeof(long double));

	
	//printf("Values:\n");
	for (int i = 0; i < passo; ++i)
	{
		values[i] = i+1;
		//printf("%.4Lf ", values[i]);
	}

	printf("\n---------------------------------------------------------------------\n");

		/*
		for (int i = 0; i < passo; ++i)
		{
			for (int j = 0; j < passo; ++j)
			{
				for (int k = 0; k < passo; ++k)
				{	
					for(int m = 0; m < passo; ++m)
					{
					comb[0] = (i+1)*h - h/2.0;
					comb[1] = (j+1)*h - h/2.0;
					comb[2] = (k+1)*h - h/2.0;
					comb[3] = (m+1)*h - h/2.0;
					result+= pow(h,M-1)*M_Sphere(M,comb);
					}
				}
			}
		}
	*/


		combinations(values,1,passo,1,M-1);
		printf("\n-----------------------------------------------\n");
		//perm(values,passo,0);

		//Convergenza è da sopra o sotto in base a se lascio o tolgo
		// la somma sugli elementi diagonali
		/*
		//Mi mancano da aggiungere gli elementi diagonali (h,h,h) (2h,2h,2h)
		long double* diag = (long double*)malloc((M-1)*sizeof(long double));

		for (int i = 0; i < M-1; ++i)
		{
			diag[i] = h;
		}

		for (int i = 0; i < passo; ++i)
		{
			multiply(diag,M-1,i+1);
			result+=pow(h,M-1)*M_Sphere(M,diag);

		}
		free(diag);
		*/
	
		printf("Risultato integrale = %.10Lf\n",(long double)pow(2,M)*(result));
		
	



	fclose(file);
	
	return 0;
}