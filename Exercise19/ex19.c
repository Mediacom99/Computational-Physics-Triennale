#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*

BRACKETING:

uno zero è bracketed nell'intervallo (a,b) se f(a) e f(b) hanno segno opposto (supponendo funzione continua)
io do un intervallo iniziale (a,b) e l'algoritmo lo restringe fino a trovare un (x1,x2) che contiene un possibile zero
*/

double f(double x)
{
	//return 2*powf(x,2) - 3*x + 1;

	return (46189*powf(x,10) - 109395*powf(x,8) + 90090*powf(x,6) - 30030*powf(x,4) + 3465*powf(x,2) - 63) / 256.0;
}

//funzioni derivate di f per newton-raphson
double df(double x)
{
	//return 4*x - 3;
	return (10*46189*powf(x,9) - 8*109395*powf(x,7) + 6*90090*powf(x,5) - 4*30030*powf(x,3) 
		+ 2*3465*x) / 256.0;
}

//Algoritmo che partendo da un range iniziale trova sup e min di ogni intervallo che contiene una radice di f
//xb1[] e xb2[] formano le coppie (x1,x2) di range in cui c'è lo zero. dim(xb) = nroot= number of roots
// n tiene conto dei passi da fare
void bracketing(double(*f)(double), double x1, double x2, int n, double* xb1, double* xb2)
{	

	int nroot = 0;
	double dx = (x2 - x1) / n;
	double x = x1;
	double fp = f(x1);
	for (int i = 0; i < n; ++i)
	{
		double fc = f(x+=dx);

		//Se c'è il cambio di segno allora salva i valori
		if(fc*fp <= 0.0)
		{
			xb1[nroot] = x-dx;
			xb2[nroot] = x;
			nroot++;
		}
		fp=fc;
	}

	return;

}

//Algoritmo che, partendo dagli intervalli usati da bracketing, ricava precisamente la radice
//xacc = accuratezza entro cui cercare lo zero
double bisection(double(*func)(double), double x1, double x2, double xacc)
{
	const int JMAX = 100;
	//const int JMAX = 100;
	//maximum allowed number of bisections
	double dx,xmid,rtb;
	double f = func(x1);
	double fmid = func(x2);
	if(func(x1)*func(x2) >= 0)
	{
		printf("Bracketing da rifare");
		exit(EXIT_FAILURE);
	}
	if(f<0.0)
	{
		dx = x2-x1;
		rtb = x1;
	}else
	{
		dx = x1-x2;
		rtb = x2;
	}
	for (int i = 0; i < JMAX; ++i)
	{
		fmid=func(xmid=rtb+(dx*=0.5));
		//printf("fmid=%f rtb=%f\n",fmid,rtb);
		if(fmid <= 0.0) rtb = xmid;
		if(fabsf(dx)<xacc || fmid == 0.0) return rtb;
	}
	printf("Troppe iterazioni\n");
	exit(EXIT_FAILURE);

}

//Newton raphson

double newton(double(*func)(double), double(*dfunc)(double), double x1, double x2, double xacc)
{

	const int KMAX = 100;
	double rtn = 0.5*(x1+x2);
	double f,df,dx;
	for (int k = 0; k < KMAX; ++k)
	{	
		f=func(rtn);
		df = dfunc(rtn);
		dx = f/df;
		rtn += -dx;
		if(fabsf(dx) < xacc) 
		{
			printf("%d\n",k);
			return rtn;

		}
	}
	exit(EXIT_FAILURE);
}



int main(int argc, char const *argv[])
{	
	FILE* file = fopen("dataBp2.txt","w");
	FILE* file2 = fopen("dataNp2.txt","w");
	//Numero di radici
	int nroot = 10;
	//guess iniziali intervallo in cui cercare gli intervalli che contengono radici
	double a = -2.0;
	double b = 2.0;
	//array che contengono i sup e inf degli intervalli con radici
	double xb1[nroot];
	double xb2[nroot];
	//trovo gli intervalli partendo dal range iniziale(a,b)
	bracketing(f,a,b,1000,xb1,xb2);
	double xacc;

	
	//Loop sulle radici
	for (int i = 0; i < nroot; ++i)
	{
		xacc = powf(10,-10)*(fabsf(xb1[0]) + fabsf(xb2[0])) / 2.0;
		fprintf(file,"(%.10f,%.10f),%.10f\n",xb1[i],xb2[i],bisection(f,xb1[i],xb2[i],xacc));
	}
	

	xacc = powf(10,-5);
	//Newton
	for (int i = 0; i < nroot; ++i)
	{
		fprintf(file2,"(%.10f,%.10f),%.10f\n",xb1[i],xb2[i],newton(f,df,xb1[i],xb2[i],xacc));
	}
	
	fclose(file);
	fclose(file2);
	return 0;
}