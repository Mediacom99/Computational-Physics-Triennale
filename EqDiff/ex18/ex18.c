#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "eqDiffVec.h"
#include <stdbool.h>

//Variabili che compongono l'array state sono 18, perchè sono 3 eq differenziali del II ordine per
// ognuno dei 3 corpi, quindi 9 eq differenziali del secondo ordine che vengono divise in 18 eq 
// differenziali del I ordine.
//Array stato è organizzato avendo prima i tre array di coordinate e poi i 3 array di derivate delle coordinate

const long double M[3] = {1.6,0.4,0.4};
//const long double M[3] = {0.3,0.3,0.3};

void iniZero(long double* vec)
{
	for (int i = 0; i < 18; ++i)
	{
		vec[i] = 0.0;
	}
	return;
}

//calcola norma tra x1-x2
long double ovd(long double* r1, long double* r2)
{	
	long double norms = 0.0;
	for (int i = 0; i < 3; ++i)
	{
		norms += powl(r1[i]-r2[i],2);
	}
	return sqrtl(norms);
}

long double squareMod(long double* vec)
{
	long double result = 0;
	for (int i = 0; i < 3; ++i)
	{
		result+=vec[i]*vec[i];
	}
	return result;
}

void func(long double* df, long double* f, long double t)
{	

	long double C = 0;
	iniZero(df); //inizializza df con variabili = 0


	//update COORDINATE
	for (int i = 0; i < 9; ++i)
	{
		df[i] = f[i + 9];
	}

	//Update MOMENTI

	//Loop sui 3 corpi
	for (int i = 0; i < 3; ++i)
	{	
		//Loop sugli altri corpi per l'iterazione
		for (int j = 0; j < 3; ++j)
		{	
				//togli autointerazione
				if(i==j)
				{
					continue; //skippa l'iterazione in cui vale i==j
				}
				//Coefficiente interazione corpo i con j
				C = -1*M[j] / powl(ovd(&f[3*i],&f[3*j]),3);
				//Loop sui momenti del corpi i-esimo da aggiornare aggiungendo interazione con j-esimo 
				// 3*i salta sui 3 corpi, k salta sui momenti del corpo i-esimo e +9 serve per 
				// accedere ai momenti (ultimi 9 posti) invece che alle coordinate (primi 9 posti)
				for (int k = 0; k < 3; ++k)
				{
					df[3*i + 9 + k] += C*(f[3*i + k] - f[3*j + k]); //dato che devo aggiungere df deve già essere vuoto ma assegnato
				}
		}
	}

}

void iniState(long double* stato, long double* data, int i, bool coord)
{	
	i-=1;
	if (coord)
	{
		for (int j = 0; j < 3 ; ++j)
		{
			stato[3*i + j] = data[j];
		}
		return;
	}
	else
	for (int j = 0; j < 3 ; ++j)
		{
			stato[3*i + j + 9] = data[j];
		}
	return;
}



long double energia(long double* stato)
{
	long double e = 0;

	//Energia Cinetica
	for (int i = 0; i < 3; ++i)
	{
		e += 0.5*M[i]*squareMod(&stato[3*i + 9]);
	}

	//energia potenziale
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if(i==j)
			{
				continue;
			}
			e += -0.5*M[i]*M[j] / ovd(&stato[3*i],&stato[3*j]);
		}
	}

	return e;
}


void initializeState(long double* stato)
{
	//Primo set dati iniziali
	
	/*
	long double x1[3] = {1.0,0.0,0.0};
	long double x2[3] = {-1.0,0.0,0.0};
	long double x3[3] = {0.0,0.0,0.0};
	long double p1[3] = {0.0,0.15,-0.15};
	long double p2[3] = {0.0,-0.15,0.15};
	long double p3[3] = {0.0,0.0,0.0};
	*/
	
	
	//Secondo set dati iniziali
	long double x1[3] = {1.0,0.0,0.0};
	long double x2[3] = {-1.0,0.0,0.0};
	long double x3[3] = {0.0,0.0,0.0};
	long double p1[3] = {0.0,0.4,0.0};
	long double p2[3] = {0.0,-0.8,0.7};
	long double p3[3] = {0.0,-0.8,-0.7};
	
	
	iniState(stato,x1,1,true);
	iniState(stato,x2,2,true);
	iniState(stato,x3,3,true);
	iniState(stato,p1,1,false);
	iniState(stato,p2,2,false);
	iniState(stato,p3,3,false);

	return;
}



int main(int argc, char const *argv[])
{
	
	FILE* file = fopen("data1.txt","w");
	FILE* file2 = fopen("data2.txt","w");
	FILE* file3 = fopen("data3.txt","w");
	FILE* file4 = fopen("energia.txt","w");
	//Campionamento
	long double h = 1/1000.0; //1/144
	long double T = 10.0;
	//Iterazioni
	long double n = T/h; //8640

	long double t;
	long double stato[18]; //[r(1,x), r(1,y), r(1,z),...,r(3,x),r(3,y),r(3,z), dr/dt(1,x),...] 

	//Dati iniziali
	
	initializeState(stato);
	t = 0;

	for (int i = 0; i < n; ++i)
	{

		//vecEulero(stato, func, t, h, 3);
		//vecRKII(stato, func, t, h, 3);
		vecRK4(stato, func, t, h, 18);

		//Sample ogni 10 per evitare di avere troppi punti 
		// talmente vicini che quando genero l'immagine vengono persi
		if(i%10==0)
		{
			fprintf(file, "%.5LF, %.5LF, %.5LF\n",stato[0], stato[1], stato[2]);
			fprintf(file2, "%.5LF, %.5LF, %.5LF\n",stato[3], stato[4], stato[5]);
			fprintf(file3, "%.5LF, %.5LF, %.5LF\n",stato[6], stato[7], stato[8]);
			fprintf(file4, "%.5LF, %.5LF\n",energia(stato),t);
		}
		t+=h;
	}


	fclose(file);
	fclose(file2);
	fclose(file3);
	fclose(file4);

	return 0;
}