/* File header contenente tutti i metodi di integrazione da utilizzare per gli esercizi 3-4-5-6-7-8*/
// Edoardo Bertoli - Lab. Fisica Computazionale - 869024

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//UTILITY
void printMatrix(int dim, long double** matrix)
{
	for (int j = 0; j < dim; ++j)
	{
		for (int k = 0; k < dim; ++k)
		{
			printf("[%d][%d] = %Lf\n",j,k,matrix[j][k]);
		}
	}
	return;
}

void makeTableRomberg(int J, long double** values)
{

	for (int k = 0; k < J; ++k)
	{
		printf("K = %d:\n",k);
			for (int j = 0; j < J; ++j)
			{
				printf("R[%d][%d] = %Lf | ",k,j,values[k][j]);	
			}
		printf("\n");
	}
	return;
}

/*VALORI DA UTILIZZARE PER USARE METODO DI GAUSS CON LAGUERRE, LEGENDRE, HERMITE*/

// LAGUERRE [-1,1]
//Array La_xn[] = array di n punti, ognuno ha sia il + che il -, ma entrambi con stesso peso
//Array La_wn[] = array di n pesi
//Per 2 e 4 punti invece è punto, peso, punto peso
long double La_1[2] = {0,2};
long double La_2[4] = {5.77350269189625764507e-01,1,-5.77350269189625764507e-01,1};

long double La_x3[2] = {0,7.74596669241483377010e-01};
long double La_w3[2] = {8.88888888888888888877e-01,5.55555555555555555562e-01};

long double La_x4[2] = {8.61136311594052575248e-01,3.39981043584856264792e-01};
long double La_w4[2] = {3.47854845137453857383e-01,6.52145154862546142644e-01};

long double La_x8[4] = 
{1.83434642495649804936e-01,
5.25532409916328985830e-01,
7.96666477413626739567e-01,
9.60289856497536231661e-01};
long double La_w8[4] = 
{3.62683783378361982976e-01,
3.13706645877887287338e-01,
2.22381034453374470546e-01,
1.01228536290376259154e-01};

long double La_x16[8] = 
{9.50125098376374401877e-02,
2.81603550779258913231e-01,
4.58016777657227386350e-01,
6.17876244402643748452e-01,
7.55404408355003033891e-01,
8.65631202387831743866e-01,
9.44575023073232576090e-01,
9.89400934991649932601e-01};
long double La_w16[8] = 
{1.89450610455068496287e-01,
1.82603415044923588872e-01,
1.69156519395002538183e-01,
1.49595988816576732080e-01,
1.24628971255533872056e-01,
9.51585116824927848073e-02,
6.22535239386478928628e-02,
2.71524594117540948514e-02};

long double La_x48[24] = 
{
3.23801709628693620343e-02,
9.70046992094626989322e-02,
1.61222356068891718055e-01,
2.24763790394689061224e-01,
2.87362487355455576728e-01,
3.48755886292160738148e-01,
4.08686481990716729925e-01,
4.66902904750958404535e-01,
5.23160974722233033658e-01,
5.77224726083972703838e-01,
6.28867396776513624013e-01,
6.77872379632663905208e-01,
7.24034130923814654658e-01,
7.67159032515740339276e-01,
8.07066204029442627087e-01,
8.43588261624393530704e-01,
8.76572020274247885885e-01,
9.05879136715569672805e-01,
9.31386690706554333107e-01,
9.52987703160430860724e-01,
9.70591592546247250472e-01,
9.84124583722826857765e-01,
9.93530172266350757526e-01,
9.98771007252426118580e-01};
long double La_w48[24] = 
{
6.47376968126839225006e-02,
6.44661644359500822082e-02,
6.39242385846481866207e-02,
6.31141922862540256548e-02,
6.20394231598926639029e-02,
6.07044391658938800517e-02,
5.91148396983956357477e-02,
5.72772921004032157044e-02,
5.51995036999841628676e-02,
5.28901894851936670964e-02,
5.03590355538544749590e-02,
4.76166584924904748267e-02,
4.46745608566942804201e-02,
4.15450829434647492133e-02,
3.82413510658307063158e-02,
3.47772225647704388909e-02,
3.11672278327980889025e-02,
2.74265097083569482001e-02,
2.35707608393243791410e-02,
1.96161604573555278142e-02,
1.55793157229438487279e-02,
1.14772345792345394895e-02,
7.32755390127626210220e-03,
3.15334605230583863260e-03,
};
/********************************************************************************************/
/*Regola del trapezio: si basa sull'espansione di taylor in uno dei N punti scelti, integrali solo su
intervallo finito */
// N = numero di punti su cui eseguire l'integrazione, a e b sono gli estremi di integraziobe
//Punti equidistanziati h = (b-a) / N, func è un puntatore alla funzione da usare
//accedere a funzione passata come parametro (*func)(input)
//INTEGRAZIONE DEL TRAPEZIO
long double trapezio(int N, long double a, long double b, long double (*func)(long double))
{

	long double h = (b-a) / (long double)(N-1) ;
	long double result = 0.0;
	result += func(a)*0.5; //aggiungo 1/2 f(a)
	long double point = a+h;
	while(point < b){
	
		result+=func(point);
		point+=h;
		//printf("%Lf\n",point);
	}
	result+= func(b)*0.5; //aggiungo 1/2 f(b)
	result*=h;

	return result;
}

//INTEGRAZIONE DI SIMPSON
long double simpson(int N, long double a, long double b, long double (*func)(long double))
{
	long double h = (b-a) / (long double)(N-1) ;
	long double result = 0.0;
	result+= func(a);
	long double point = a+h;
	for (int i = 2; i <= N-2; ++i)
	{
		if(i%2 == 0) //se siamo al passo pari moltiplica per 4, altrimenti per 2
		{
			result+=4*func(point);
		}
		else
		{
			result+=2*func(point);
		}
		point+=h;
	}
	result+=func(b);
	result*=(h/3);
	return result;	
}

long double romberg(int N, long double a, long double b, long double (*func)(long double))
{

	//int J = floor(log2(N-1)); //numero di ripetizioni
	int J = N; //IN questo caso N è il numero di suddivisioni da fare
	long double** values = (long double**)malloc(J*sizeof(long double*));
	for (int i = 0; i < J; ++i)
	{
		values[i] = (long double*)malloc(J*sizeof(long double));
	}
	


	//collezione dei risultati del trapezio
	//Riempio valuesT con i valori dei trapezi
	for (int i = 0; i < J; ++i)
	{
		values[i][0] = trapezio((int)(pow(2,i)+1),a,b,func); 
		//printf("Valore a %d = %Lf\n",i,values[i][0]);
	}

	
	//Array con tutti i valori ricorsivi successivi
	for (int k = 1; k < J; ++k)
	{
		for (int j = 1; j <= k; ++j) //OCCHIO
		{
			values[k][j] = (pow(4,j)*values[k][j-1] - values[k-1][j-1]) / (pow(4,j) - 1);
		}
	}

	//printMatrix(J,values);
	makeTableRomberg(J,values);
	free(values);
	return values[J-1][J-1];

}