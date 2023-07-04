// File Header con implementazione metodi di risoluzione delle equazioni differenziali
// Edoardo Bertoli 869024

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* IMPLEMENTAZIONE EULERO RK2 E RK4 VETTORIALE
*/


//array k1: salva i valori n-esimi che servono per calcolare il passo successivo
// k1: rappresenta l'array con cui salvo l'evoluzione del sistema, cioè i vari xn che 
// 		   vado a stampare nel main di ex17.c

//N dimensione del sistema 
void vecEulero(long double* stato, void(*func)(long double*, long double*, long double), 
	long double t, long double h, int N)
{	
	long double k1[N]; //salvo i valori al tempo t per calcolare f(xn,yn,...,t)
	func(k1,stato,t); //k1 contiene f(xn,yn,...,t) per ogni variabile
	for (int i = 0; i < N; ++i)
	{
		//Update dello stato
		stato[i]+=h*k1[i];
	}
	return;

}

//Temp serve per costruire il vettore stato[] + (roba)k_{i-esimo} da usare per costruire gli altri k
void vecRKII(long double* stato, void(*func)(long double*, long double*, long double), 
			long double t, long double h, int N)
{

	long double k2[N];
	long double k1[N];
	long double temp[N];

	func(k1,stato,t); //Calcolo k1

	//Calcolo l'array con cui faccio lo step successivo per calcolare k2 = func(f+k1h/2)
	for (int i = 0; i < N; ++i)
	{
		temp[i] = stato[i] + (h/(2.0))*k1[i];
	}

	func(k2,temp,t + h/2.0); //Calcolo k2

	for (int i = 0; i < N; ++i)
	{
		stato[i] += h*k2[i];
	}

	return;
}


void vecRK4(long double* stato, void(*func)(long double*, long double*, long double), 
			long double t, long double h, int N)
{

	long double k2[N];
	long double k1[N];
	long double k3[N];
	long double k4[N];
	long double temp1[N];
	long double temp2[N];

	func(k1,stato,t); //Calcolo k1

	//Calcolo l'array con cui faccio lo step successivo per calcolare k2 = func(f+k1h/2)
	for (int i = 0; i < N; ++i)
	{
		temp1[i] = stato[i] + (h/(2.0))*k1[i];
	}

	func(k2,temp1,t + h/2.0); //Calcolo k2

	for (int i = 0; i < N; ++i)
	{
		temp1[i] = stato[i] + (k2[i]*h)/(2.0);
	}

	func(k3, temp1, t + h/2.0); //Calcolo k3

	for (int i = 0; i < N; ++i)
	{
		temp1[i] = stato[i] + h*k3[i];
	}

	func(k4, temp1, t+h);

	for (int i = 0; i < N; ++i)
	{
		stato[i]+= (h/(6.0))*(k1[i] + 2*k2[i] + 2*k3[i] + k4[i]);
	}

	return;
}
