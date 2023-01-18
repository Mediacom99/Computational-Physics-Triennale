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
	// n = 0;
	fprintf(file, "%.10Lf,%.10Lf\n",x0,f0); //printo il valore a x0
	//calcolo per n = 1;
	long double evSol = f0 + h*df0; //Evoluzione funzione soluzione
	long double evDSol = df0 + h*fd(f0,0,x0);	//Evoluzione derivata soluzione
	long double xn = x0 + h;
	fprintf(file, "%.10Lf,%.10Lf\n",xn,evSol); //printo il valore a x1
	long double tempSol = 0; //queste due variabili temp mi servono per salvare il valore n-esimo nel loop
	long double tempDSol = 0;
	for (int i = 2; i <= n; ++i)
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
	file = fopen("DataRK2.txt","w");

	//f0 = dato iniziale della soluzione
	//df0 = dato iniziale della derivata
	//x0 = punto in cui vengono dati i dati iniziali

	//Valori iniziali
	fprintf(file, "%.10Lf,%.10Lf\n",x0,f0); //printo il valore a x0
	//calcolo per n = 1;
	long double k1f = (h/2)*(df0);
	long double k1d = (h/2)*(fd(f0,0,x0));
	long double evSol = f0 + h*(df0 + k1d); //Evoluzione funzione soluzione
	long double evDSol = df0 + h*fd(f0 + k1f,0,x0 + h/2);	//Evoluzione derivata soluzione
	long double xn = x0 + h;
	fprintf(file, "%.10Lf,%.10Lf\n",xn,evSol); //printo il valore a n = 1

	//ora in xn, k1f, k1d, evSol e evDSol sono i valori a n = 1

	//k1f = (h/2)*(evDSol);
	//k1d = (h/2)*(fd(evSol,0,xn)); 
	//Variabili temporanee per salvare i valori n-esimi nel loop
	long double tempSol = 0; 
	long double tempDSol = 0;
	//long double k1f_temp = 0;
	//long double k1d_temp = 0;
	//I primi valori che calcolo nel loop saranno per n = 2
	for (int i = 2; i <= n; ++i)
	{	
		//Salvo i valori n-esimi (n = 1 alla prima iterazione)
		tempSol = evSol;
		tempDSol = evDSol;
		//Calcolo i k n-esimi 
		k1f = (h/2)*(tempDSol);
		k1d = (h/2)*(fd(tempSol,0,xn)); 
		
		//trovo i valori n+1 esimi tramite i valori n-esimi (n = 2 alla prima iterazione)
		evDSol = tempDSol + h*fd(tempSol + k1d,0,xn + h/2); //usando xn, trovo xn+1
		evSol = tempSol + h*(tempDSol + k1f);
		xn += h; 
		
		fprintf(file, "%.10Lf,%.10Lf\n",xn,evSol); //printo il valore (n = 2 al primo)
	}

	fclose(file);
	return;

}

void provark2(long double (*fd)(long double, long double, long double), 
	long double f0, long double df0, long double x0, 
	long double h, int n)
{	
	FILE* file;
	file = fopen("DataRK2.txt","w");

	//f0 = dato iniziale della soluzione
	//df0 = dato iniziale della derivata
	//x0 = punto in cui vengono dati i dati iniziali

	//Valori iniziali
	// n = 0;
	fprintf(file, "%.10Lf,%.10Lf\n",x0,f0); //printo il valore a x0
	long double evSol = f0;  
	long double evDSol = df0; 
	long double xn = x0;
	long double k1d;
	long double k1f;
	long double k2d;
	long double k2f;

	for (int i = 1; i <= n; ++i)
	{	
		k1d = h*(-evSol);
		k1f = h*(evDSol);
		k2d = h*(-evSol + k1d/2.0);
		k2f = h*(evDSol + k1f/2.0);
		evDSol = evDSol + k2d;
		evSol = evSol + k2f;
		xn+=h;
		fprintf(file, "%.10Lf,%.10Lf\n",xn,evSol);
	}

	fclose(file);
	return;

}


void provaEulero(long double (*fd)(long double, long double, long double), 
	long double f0, long double df0, long double x0, 
	long double h, int n)
{	
	FILE* file;
	file = fopen("DataE.txt","w");

	//f0 = dato iniziale della soluzione
	//df0 = dato iniziale della derivata
	//x0 = punto in cui vengono dati i dati iniziali

	//Valori iniziali
	// n = 0;
	fprintf(file, "%.10Lf,%.10Lf\n",x0,f0); //printo il valore a x0
	//calcolo per n = 1;
	long double evSol = f0; //Evoluzione funzione soluzione
	long double evDSol = df0;	//Evoluzione derivata soluzione
	long double xn = x0;
	long double k1d;
	long double k1f;
	for (int i = 1; i <= n; ++i)
	{	
		//trovo i valori n+1 esimi
		k1d = -evSol;
		k1f = evDSol;
		evDSol = evDSol + h*(k1d); //usando xn, trovo xn+1
		evSol = evSol + h*k1f;
		xn += h; //passo a xn+1 che corrisponde ad evSol che trovo nel loop
		fprintf(file, "%.10Lf,%.10Lf\n",xn,evSol); //printo il valore (x2 al primo, poi x(n+1))
	}

	fclose(file);
	return;

}
