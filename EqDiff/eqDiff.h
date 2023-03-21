// File Header con implementazione metodi di risoluzione delle equazioni differenziali
// Edoardo Bertoli 869024

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Implementazione metodo di Eulero, discretizza le derivate
Sfrutto il fatto che ogni eq diff ordinaria si può riscrivere come sistema dinamico di 
eq diff del primo ordine, func è la funzione che conosco nell'eq diff che voglio risolvere
*/

// h è il passo di discretizzazione (frequenza di sampling)
// n è il termine di evoluzione
// T = nh è il tempo totale di campionamento


//per ora funziona solo per eq diff del II ordine
void EuleroII(long double (*fd)(long double, long double, long double), 
	long double f0, long double df0, long double t0, 
	long double h, int n)
{	
	FILE* file;
	file = fopen("DataE.txt","w");


	//f0 = dato iniziale della soluzione
	//df0 = dato iniziale della derivata
	//x0 = punto in cui vengono dati i dati iniziali

	long double f = f0; //variabile che segue l'evoluzione della soluzione dell'eq diff
	long double df = df0; //variabile che segue l'evoluzione della derivata della soluzione dell'eq diff
	long double tn = t0; //evoluzione della variabile indipendente
	long double k1d,k1f; //variabili di supporto nel loop per salvare i valori n-esimi

	/* PRINTO I VALORI INIZIALI */
		//fprintf(file, "%.20Lf,%.20Lf\n",tn,f); //printo f(t)
		fprintf(file, "%.20Lf,%.20Lf\n",tn,df); //printo f'(t)
		//fprintf(file, "%.20Lf,%.20Lf\n",f,df); //printo f'(f) (grafico di fase)
	for (int i = 0; i < n; ++i)
	{	
		//salvo i valori n-esimi
		k1f = df;
		k1d = f;
		//calcolo i valori n+1
		f = f + h*(k1f);
		df = df + h*fd(k1d,0,tn);
		tn+=h;	
		//fprintf(file, "%.20Lf,%.20Lf\n",tn,f); //printo f(t)
		fprintf(file, "%.20Lf,%.20Lf\n",tn,df); //printo f'(t)
		//fprintf(file, "%.20Lf,%.20Lf\n",f,df); //printo f'(f) (grafico di fase)
	}

	//fprintf(Etxt, "%.20Lf\n", logl(fabsl(1-f)));
	fclose(file);
	return;

}

/*****************************************************************************************************************/

//Metodo Runge-Kutta 2 

//Per ora implemento solo per eq diff II ordine, disaccoppiandole in due eq diff del I ordine accoppiate

void Runge_Kutta2(long double (*fd)(long double, long double, long double), 
	long double f0, long double df0, long double t0, 
	long double h, int n)
{	
	FILE* file1;
	file1 = fopen("DataRK2.txt","w");


	//f0 = dato iniziale della soluzione
	//df0 = dato iniziale della derivata
	//x0 = punto in cui vengono dati i dati iniziali

	long double f = f0; //variabile che segue l'evoluzione della soluzione dell'eq diff
	long double df = df0; //variabile che segue l'evoluzione della derivata della soluzione dell'eq diff
	long double tn = t0; //evoluzione della variabile indipendente
	long double k1d,k1f,k2d,k2f; //variabili di supporto nel loop per salvare i valori n-esimi

	//PRINTO I VALORI INIZIALI
		//fprintf(file1, "%.20Lf,%.20Lf\n",tn,f); //printo f(t)
		fprintf(file1, "%.20Lf,%.20Lf\n",tn,df); //printo f'(t)
		//fprintf(file1, "%.20Lf,%.20Lf\n",f,df); //printo f'(f) (grafico di fase)
	for (int i = 0; i < n; ++i)
	{	
		//calcolo i k1 e k2
		k1f = h*df;
		k1d = h*fd(f,0,tn);
		k2f = h*(df + k1d/2.0);
		k2d = h*fd(f + k1f/2.0,0,tn + h/2.0);
		
		//calcolo i valori n+1
		f = f + k2f;
		df = df + k2d;
		tn+=h;
		//fprintf(file1, "%.20Lf,%.20Lf\n",tn,f); //printo f(t)
		fprintf(file1, "%.20Lf,%.20Lf\n",tn,df); //printo f'(t)
		//fprintf(file1, "%.20Lf,%.20Lf\n",f,df); //printo f'(f) (grafico di fase)
	}

	//fprintf(RK2txt, "%.20Lf\n", logl(fabsl(1-f)));
	fclose(file1);
	return;

}


/***************************************************************************************************************/


void Runge_Kutta4(long double (*fd)(long double, long double, long double), 
	long double f0, long double df0, long double t0, 
	long double h, int n)
{	
	FILE* file2;
	file2 = fopen("DataRK4.txt","w");

	//f0 = dato iniziale della soluzione
	//df0 = dato iniziale della derivata
	//x0 = punto in cui vengono dati i dati iniziali

	long double f = f0; //variabile che segue l'evoluzione della soluzione dell'eq diff
	long double df = df0; //variabile che segue l'evoluzione della derivata della soluzione dell'eq diff
	long double tn = t0; //evoluzione della variabile indipendente
	long double k1d,k1f,k2d,k2f,k3d,k3f,k4d,k4f; //variabili di supporto nel loop per salvare i valori n-esimi

	// PRINTO I VALORI INIZIALI
	//fprintf(file2, "%.20Lf,%.20Lf\n",tn,f); //printo f(t)
	fprintf(file2, "%.20Lf,%.20Lf\n",tn,df); //printo f'(t)
	//fprintf(file2, "%.20Lf,%.20Lf\n",f,df); //printo f'(f) (grafico di fase)
	fprintf(file2,"%.20Lf,%.20Lf\n",tn,f); //printo i valori iniziali
	for (int i = 0; i < n; ++i)
	{	
		//calcolo i k1 e k2
		k1f = h*df;
		k1d = h*fd(f,0,tn);
		k2f = h*(df + k1d/2.0);
		k2d = h*fd(f + k1f/2.0,0,tn + h/2.0);
		k3f = h*(df + k2d/2.0);
		k3d = h*fd(f + k2f/2.0,0,tn + h/2.0);
		k4f = h*(df + k3d);
		k4d = h*fd(f + k3f,0,tn + h);
		
		//calcolo i valori n+1
		f = f + (1/6.0)*(k1f + 2*k2f + 2*k3f + k4f);
		df = df + (1/6.0)*(k1d + 2*k2d + 2*k3d + k4d);
		tn+=h;
		//fprintf(file2, "%.20Lf,%.20Lf\n",tn,f); //printo f(t)
		fprintf(file2, "%.20Lf,%.20Lf\n",tn,df); //printo f'(t)
		//fprintf(file2, "%.20Lf,%.20Lf\n",f,df); //printo f'(f) (grafico di fase)
	}

	//fprintf(RK4txt, "%.20Lf\n", logl(fabsl(1-f)));
	fclose(file2);
	return;

}

