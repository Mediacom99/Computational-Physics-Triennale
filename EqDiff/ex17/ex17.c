#include <math.h>
#include <time.h>
#include "eqDiffVec.h"



void func(long double* df, long double* f, long double t)
{
	/*dx/dt*/ df[0] = -10*(f[0]-f[1]);
	/*dy/dt*/ df[1] = -f[0]*f[2] + 28*f[0] - f[1];
	/*dz/dt*/ df[2] = f[0]*f[1] - (8/3.0)*f[2];
}


int main(int argc, char const *argv[])
{	

	FILE* file;
	file = fopen("XYZtData.txt","w");


	//Campionamento
	long double h = 1/144.0;
	//Iterazioni
	long double n = 8640;
	long double t = 0;
	long double stato[3]; //[dx, dy, dz] 
	//Valori iniziali
	/*x*/ stato[0] = 0.45;
	/*y*/ stato[1] = 0.7;
	/*z*/ stato[2] = 0.2;



	for (int i = 0; i < n; ++i)
	{

		//vecEulero(stato, func, t, h, 3);
		//vecRKII(stato, func, t, h, 3);
		vecRK4(stato, func, t, h, 3);

		fprintf(file, "%.20Lf, %.20Lf, %.20Lf, %.20Lf\n",stato[0], stato[1], stato[2],t);
		t+=h;
	}


	fclose(file);
	return 0;

}