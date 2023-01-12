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
	long double f0, long double df0, long double x0, 
	long double h, int n)
{	
	FILE* file;
	file = fopen("DataE.txt","w");

	//f0 = dato iniziale della soluzione
	//df0 = dato iniziale della derivata
	//x0 = punto in cui vengono dati i dati iniziali

	//Valori iniziali
	fprintf(file, "%.10Lf,%.10Lf\n",x0,f0); //printo il valore a x0
	//calcolo per n = 1;
	long double evSol = f0 + h*df0; //Evoluzione funzione soluzione
	long double evDSol = df0 + h*fd(f0,0,x0);	//Evoluzione derivata soluzione
	long double xn = x0 + h;
	fprintf(file, "%.10Lf,%.10Lf\n",xn,evSol); //printo il valore a x1
	long double tempSol = 0; //queste due variabili temp mi servono per salvare il valore n-esimo nel loop
	long double tempDSol = 0;
	for (int i = 1; i <= n; ++i)
	{	
		//Salvo i valori n-esimi
		tempSol = evSol;
		tempDSol = evDSol;
		//trovo i valori n+1 esimi
		evDSol = tempDSol + h*fd(tempSol,0,xn); //usando xn, trovo xn+1
		evSol = tempSol + h*tempDSol;
		xn += h; //passo a xn+1 che corrisponde ad evSol che trovo nel loop
		fprintf(file, "%.10Lf,%.10Lf\n",xn,evSol); //printo il valore (x2 al primo, poi x(n+1))
	}

	fclose(file);
	return;

}

/*****************************************************************************************************************/

//Metodo Runge-Kutta 2 

//Per ora implemento solo per eq diff II ordine, disaccoppiandole in due eq diff del I ordine accoppiate

void Runge_Kutta2(long double (*fd)(long double, long double, long double), 
	long double f0, long double df0, long double x0, 
	long double h, int n)
{	
	FILE* file;
	file = fopen("DataE.txt","w");

	//f0 = dato iniziale della soluzione
	//df0 = dato iniziale della derivata
	//x0 = punto in cui vengono dati i dati iniziali

	//Valori iniziali
	fprintf(file, "%.10Lf,%.10Lf\n",x0,f0); //printo il valore a x0
	//calcolo per n = 1;
	long double k1f = (h/2)*(df0);
	long double k1d = (h/2)*(ff(f0,0,x0));
	long double evSol = f0 + h*(df0 + k1d); //Evoluzione funzione soluzione
	long double evDSol = df0 + h*ff(x0 + h/2, f0 + k1f);	//Evoluzione derivata soluzione
	// FINO ALLA RIGA SOPRA DOVREBBE ESSERE GIUSTO, BISOGNA SISTEMARE IL RESTO
	long double xn = x0 + h;
	fprintf(file, "%.10Lf,%.10Lf\n",xn,evSol); //printo il valore a x1
	long double tempSol = 0; //queste due variabili temp mi servono per salvare il valore n-esimo nel loop
	long double tempDSol = 0;
	for (int i = 1; i <= n; ++i)
	{	
		//Salvo i valori n-esimi
		tempSol = evSol;
		tempDSol = evDSol;
		//trovo i valori n+1 esimi
		evDSol = tempDSol + h*fd(tempSol,0,xn); //usando xn, trovo xn+1
		evSol = tempSol + h*tempDSol;
		xn += h; //passo a xn+1 che corrisponde ad evSol che trovo nel loop
		fprintf(file, "%.10Lf,%.10Lf\n",xn,evSol); //printo il valore (x2 al primo, poi x(n+1))
	}

	fclose(file);
	return;

}
