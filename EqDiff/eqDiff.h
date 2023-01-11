// File Header con implementazione metodi di risoluzione delle equazioni differenziali
// Edoardo Bertoli 869024

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/*
Implementazione metodo di Eulero, discretizza le derivate
Sfrutto il fatto che ogni eq diff ordinaria si può riscrivere come sistema dinamico di 
eq diff del primo ordine, func è la funzione che conosco nell'eq diff che voglio risolvere
*/

// h è il passo di discretizzazione (frequenza di sampling)
// n è il termine di evoluzione
// T = nh è il tempo totale di campionamento


//per ora funziona solo per eq diff del II ordine
void EuleroII(long double (*T)(long double, long double), 
	long double f0, long double df0, long double x0, 
	long double h, int n)
{	
	FILE* file;
	file = fopen("Data.txt","w");

	//f0 = dato iniziale della soluzione
	//df0 = dato iniziale della derivata
	//x0 = punto in cui vengono dati i dati iniziali
	//T è la funzione dell'eq diff sulla derivata, che dipende dall'eq differenziale che voglio risolvere

	// df0 = 1
	// f0 = 0

	//Valori iniziali
	long double evDSol = df0 + h*T(x0,f0);	//Evoluzione derivata soluzione
	long double evSol = f0 + h*evDSol; //Evoluzione funzione soluzione

	for (int i = 1; i <= n; ++i)
	{
		
		evDSol = evDSol + h*T((x0 + i*h),evSol);
		evSol = evSol + h*evDSol;
		fprintf(file, "%.10Lf,%.10Lf\n",(x0+i*h),evSol);
	}

	fclose(file);
	return;

}