/* File header contenente tutti i metodi di integrazione da utilizzare per gli esercizi 3-4-5-6-7-8*/
// Edoardo Bertoli - Lab. Fisica Computazionale - 869024

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//UTILITY
// dim1 = righe, dim2 = colonne
void printMatrix(int dim1, int dim2, long double** matrix)
{
	for (int j = 0; j < dim1; ++j)
	{
		for (int k = 0; k < dim2; ++k)
		{
			printf("[%d][%d] = %Lf\n",j,k,matrix[j][k]);
		}
	}
	return;
}

void printTableRomberg(int N, long double** values)
{

	for (int k = 0; k < N; ++k)
	{
		printf("K = %d:\n",k);
			for (int j = 0; j < N; ++j)
			{
				printf("R[%d][%d] = %Lf | ",k,j,values[k][j]);	
			}
		printf("\n");
	}
	return;
}

/*VALORI DA UTILIZZARE PER USARE METODO DI GAUSS CON LAGUERRE, LEGENDRE, HERMITE*/

// Legendre [-1,1]
//Array La_xn[] = array di n punti, ognuno ha sia il + che il -, ma entrambi con stesso peso
//Array La_wn[] = array di n pesi
//Per 2 e 4 punti invece è punto, peso, punto peso
long double Le_1[2] = {0,2};
long double Le_2[4] = {5.77350269189625764507e-01,1,-5.77350269189625764507e-01,1};

long double Le_x3[2] = {0,7.74596669241483377010e-01};
long double Le_w3[2] = {8.88888888888888888877e-01,5.55555555555555555562e-01};

long double Le_x4[2] = {8.61136311594052575248e-01,3.39981043584856264792e-01};
long double Le_w4[2] = {3.47854845137453857383e-01,6.52145154862546142644e-01};

long double Le_x8[4] = 
{1.83434642495649804936e-01,
5.25532409916328985830e-01,
7.96666477413626739567e-01,
9.60289856497536231661e-01};
long double Le_w8[4] = 
{3.62683783378361982976e-01,
3.13706645877887287338e-01,
2.22381034453374470546e-01,
1.01228536290376259154e-01};

long double Le_x16[8] = 
{9.50125098376374401877e-02,
2.81603550779258913231e-01,
4.58016777657227386350e-01,
6.17876244402643748452e-01,
7.55404408355003033891e-01,
8.65631202387831743866e-01,
9.44575023073232576090e-01,
9.89400934991649932601e-01};
long double Le_w16[8] = 
{1.89450610455068496287e-01,
1.82603415044923588872e-01,
1.69156519395002538183e-01,
1.49595988816576732080e-01,
1.24628971255533872056e-01,
9.51585116824927848073e-02,
6.22535239386478928628e-02,
2.71524594117540948514e-02};

long double Le_x48[24] = 
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
long double Le_w48[24] = 
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

/*******************************************************************************************/
//LAGUERRE [[0,+inf)]
//Punto peso, punto peso, etc.. nel caso 2, poi sono stati divisi in due array diversi
long double Lag_2[4] = {5.85786437626904951182e-01,    8.53553390593273762191e-01,
          3.41421356237309504876e+00,    1.46446609406726237796e-01};
long double Lag_4x[4] = {
3.22547689619392311802e-01,
1.74576110115834657569e+00,
4.53662029692112798345e+00,
9.39507091230113312950e+00};
long double Lag_4w[4] = {
6.03154104341633601660e-01,
3.57418692437799686640e-01,
3.88879085150053842740e-02,
5.39294705561327450102e-04};

long double Lag_8x[8] = {
1.70279632305100999786e-01,
9.03701776799379912170e-01,
2.25108662986613068929e+00,
4.26670017028765879378e+00,
7.04590540239346569719e+00,
1.07585160101809952241e+01,
1.57406786412780045781e+01,
2.28631317368892641052e+01};
long double Lag_8w[8] = {
3.69188589341637529929e-01,
4.18786780814342956078e-01,
1.75794986637171805706e-01,
3.33434922612156515224e-02,
2.79453623522567252491e-03,
9.07650877335821310457e-05,
8.48574671627253154502e-07,
1.04800117487151038157e-09};

long double Lag_24x[24] = {  
5.90198521815079769739e-02,
3.11239146198483726850e-01,
7.66096905545936646261e-01,
1.42559759080361308635e+00,
2.29256205863219029496e+00,
3.37077426420899771615e+00,
4.66508370346717079211e+00,
6.18153511873676541179e+00,
7.92753924717215217952e+00,
9.91209801507770601851e+00,
1.21461027117297655498e+01,
1.46427322895966743419e+01,
1.74179926465089787262e+01,
2.04914600826164247076e+01,
2.38873298481697331746e+01,
2.76359371743327174205e+01,
3.17760413523747232891e+01,
3.63584058016516216520e+01,
4.14517204848707670507e+01,
4.71531064451563230421e+01,
5.36085745446950698231e+01,
6.10585314472187615648e+01,
6.99622400351050304293e+01,
8.14982792339488853750e+01};
long double Lag_24w[24] = {
1.42811973334781851087e-01,
2.58774107517423902671e-01,
2.58806707272869802021e-01,
1.83322688977778024900e-01,
9.81662726299188921909e-02,
4.07324781514086460259e-02,
1.32260194051201566876e-02,
3.36934905847830355197e-03,
6.72162564093547889971e-04,
1.04461214659275180474e-04,
1.25447219779933332069e-05,
1.15131581273727991985e-06,
7.96081295913363025727e-08,
4.07285898754999966522e-09,
1.50700822629258491643e-10,
3.91773651505845138514e-12,
6.89418105295808568594e-14,
7.81980038245944846907e-16,
5.35018881301003760279e-18,
2.01051746455550347083e-20,
3.60576586455295903895e-23,
2.45181884587840268905e-26,
4.08830159368065782307e-30,
5.57534578832835675306e-35};

long double Lag_64x[64] = {
2.24158741467052800231e-02,
1.18122512096770479798e-01,
2.90365744018036483988e-01,
5.39286221227979039314e-01,
8.65037004648113944615e-01,
1.26781404077524139816e+00,
1.74785962605943625279e+00,
2.30546373930750871854e+00,
2.94096515672525184062e+00,
3.65475265020729052703e+00,
4.44726634331309435668e+00,
5.31899925449639034364e+00,
6.27049904692365391284e+00,
7.30237000258739574719e+00,
8.41527523948302419443e+00,
9.60993919279610803608e+00,
1.08871503838863721422e+01,
1.22477645042443016180e+01,
1.36927078455475051523e+01,
1.52229811115247288481e+01,
1.68396636526487372097e+01,
1.85439181708591905237e+01,
2.03369959487302355006e+01,
2.22202426659508765396e+01,
2.41951048759332539902e+01,
2.62631372271184857850e+01,
2.84260105275010272995e+01,
3.06855207675259717710e+01,
3.30435992364378291267e+01,
3.55023238911412095872e+01,
3.80639321656464682600e+01,
4.07308354444586263668e+01,
4.35056354664215298514e+01,
4.63911429786161920753e+01,
4.93903990256246866776e+01,
5.25066993413463016516e+01,
5.57436224132783804640e+01,
5.91050619190171066079e+01,
6.25952644001513955965e+01,
6.62188732512475643835e+01,
6.99809803771468292299e+01,
7.38871872324829632103e+01,
7.79436774344631203154e+01,
8.21573037783193042966e+01,
8.65356933494565182113e+01,
9.10873756131330901478e+01,
9.58219400155207320924e+01,
1.00750231969513979628e+02,
1.05884599468799949357e+02,
1.11239207524439582063e+02,
1.16830445051306498462e+02,
1.22677460268538576577e+02,
1.28802878769237672513e+02,
1.35233787949525827835e+02,
1.42003121489931519020e+02,
1.49151665900049388583e+02,
1.56731075132671161240e+02,
1.64808602655150522986e+02,
1.73474946836424274516e+02,
1.82858204691431463648e+02,
1.93151136037072911483e+02,
2.04672028485059455949e+02,
2.18031851935328516337e+02,
2.34809579171326164707e+02};
long double Lag_64w[64] = {
5.62528423390298457415e-02,
1.19023987312426027814e-01,
1.57496403862144523822e-01,
1.67547050415773947886e-01,
1.53352855779236618084e-01,
1.24221053609329744510e-01,
9.03423009864850577399e-02,
5.94777557683550242119e-02,
3.56275189040360718546e-02,
1.94804104311664060425e-02,
9.74359489938200223986e-03,
4.46431036416627529234e-03,
1.87535958132311482674e-03,
7.22646981575005122724e-04,
2.55487532833496709709e-04,
8.28714353439694217928e-05,
2.46568639678855874602e-05,
6.72671387882966852755e-06,
1.68178536996408889783e-06,
3.85081298154668441490e-07,
8.06872804099049979074e-08,
1.54572370675768882797e-08,
2.70448014761748140999e-09,
4.31677547542720091234e-10,
6.27775254176145220162e-11,
8.30631737628895806350e-12,
9.98403178722016405639e-13,
1.08835388711666268198e-13,
1.07401740344159018535e-14,
9.57573723157444210502e-16,
7.69702802364858610043e-17,
5.56488113745405325697e-18,
3.60975640901044207624e-19,
2.09509536954894766310e-20,
1.08479330109754928762e-21,
4.99469948636380407034e-23,
2.03783697459882230123e-24,
7.33953756427942062218e-26,
2.32378308219864875034e-27,
6.43823470690877180331e-29,
1.55312109578827474413e-30,
3.24425009201953746751e-32,
5.83238626783522807580e-34,
8.96325483310326880324e-36,
1.16870398955072802407e-37,
1.28205598435998071667e-39,
1.17209493740500221911e-41,
8.83533967232947430164e-44,
5.42495559030620008660e-46,
2.67554266667889197253e-48,
1.04291703141136705653e-50,
3.15290235195777262957e-53,
7.22954191064766081503e-56,
1.22423530123008223644e-58,
1.48216850490191038804e-61,
1.23251934881451880776e-64,
6.69149900457126952687e-68,
2.22046594185044891569e-71,
4.12094609473887625236e-75,
3.77439906189648917048e-79,
1.41411505291761941744e-83,
1.59183306404136791788e-88,
2.98948434886063430781e-94,
2.08906350843695277083e-101};

/********************************************************************************************/

/* HERMITE [-INF, INF]*/
//Ogni x ha anche -x

long double He_2[2] = {7.07106781186547524382e-01, 8.86226925452758013655e-01};

long double He_4x[2] = {
5.24647623275290317900e-01,
1.65068012388578455585e+00};
long double He_4w[2] = {
8.04914090005512836482e-01,
8.13128354472451771398e-02
};

long double He_5x[3] = {
0.00000000000000000000e+00,
9.58572464613818507097e-01,
2.02018287045608563291e+00};
long double He_5w[3] = {
9.45308720482941881207e-01,
3.93619323152241159825e-01,
1.99532420590459132082e-02
};

long double He_8x[4] = {
3.81186990207322116844e-01,
1.15719371244678019474e+00,
1.98165675669584292584e+00,
2.93063742025724401920e+00};
long double He_8w[4] = {
6.61147012558241291042e-01,
2.07802325814891879546e-01,
1.70779830074134754563e-02,
1.99604072211367619211e-04
};

long double He_10w[5] = {
6.10862633735325798764e-01,
2.40138611082314686412e-01,
3.38743944554810631376e-02,
1.34364574678123269223e-03,
7.64043285523262062930e-06
};
long double He_10x[5] = {
3.42901327223704608781e-01,
1.03661082978951365422e+00,
1.75668364929988177344e+00,
2.53273167423278979644e+00,
3.43615911883773760341e+00};

long double He_24x[12] = {
2.24414547472515585146e-01,
6.74171107037212235982e-01,
1.12676081761124507216e+00,
1.58425001096169414854e+00,
2.04900357366169891173e+00,
2.52388101701142697421e+00,
3.01254613756556482562e+00,
3.52000681303452471124e+00,
4.05366440244814950399e+00,
4.62566275642378726485e+00,
5.25938292766804436733e+00,
6.01592556142573971732e+00};
long double He_24w[12] = {
4.26931163868699249653e-01,
2.86179535346443017908e-01,
1.27739621784559160653e-01,
3.74454705032307460144e-02,
7.04835581007267097009e-03,
8.23692482688417457913e-04,
5.68869163640437976911e-05,
2.15824570490233363221e-06,
4.01897117494142968461e-08,
3.04625426998756390390e-10,
6.58462024307817006444e-13,
1.66436849648910887378e-16};

long double He_48x[24] = {
1.59492935848862470508e-01,
4.78646337594496098242e-01,
7.98304627778562231224e-01,
1.11881215240215656334e+00,
1.44052522013756518647e+00,
1.76381757989530000620e+00,
2.08908666094427643593e+00,
2.41676090487321645894e+00,
2.74730862482238321958e+00,
3.08124898864510584967e+00,
3.41916596936388461126e+00,
3.76172649022835778754e+00,
4.10970460356059023648e+00,
4.46401454693445890387e+00,
4.82575722813320948405e+00,
5.19628771879236454109e+00,
5.57731698122372862624e+00,
5.97107222501354540766e+00,
6.38056409618641062406e+00,
6.81006457807414138659e+00,
7.26604655416435040284e+00,
7.75929551976577463936e+00,
8.31075219070478413055e+00,
8.97531508193168706209e+00
};
long double He_48w[24] = {
3.11001030377963078889e-01,
2.53961542664759097647e-01,
1.69204471945641106716e-01,
9.18222970792851793213e-02,
4.04796769846038489857e-02,
1.44449615749810994174e-02,
4.15300491197755245160e-03,
9.56392319819415276727e-04,
1.75150431801172828783e-04,
2.52859902774848890262e-05,
2.84725869173484808304e-06,
2.46865899366975047785e-07,
1.62251413589576983694e-08,
7.93046749516538231080e-10,
2.81529653783816910885e-11,
7.04693258154588908422e-13,
1.19758986547917935294e-14,
1.31515962265840851188e-16,
8.73015960118667654513e-19,
3.18838732350513844266e-21,
5.56457746890228483629e-24,
3.68503608015066987942e-27,
5.98461269331387842586e-31,
7.93555146077399683864e-36
};

long double He_100x[50] = {
1.10795872422439482889e-01,
3.32414692342231807054e-01,
5.54114823591616988249e-01,
7.75950761540145781976e-01,
9.97977436098105243902e-01,
1.22025039121895305882e+00,
1.44282597021593278768e+00,
1.66576150874150946983e+00,
1.88911553742700837153e+00,
2.11294799637118795206e+00,
2.33732046390687850509e+00,
2.56229640237260802502e+00,
2.78794142398198931316e+00,
3.01432358033115551667e+00,
3.24151367963101295043e+00,
3.46958563641858916968e+00,
3.69861685931849193984e+00,
3.92868868342767097205e+00,
4.15988685513103054019e+00,
4.39230207868268401677e+00,
4.62603063578715577309e+00,
4.86117509179121020995e+00,
5.09784510508913624692e+00,
5.33615836013836049734e+00,
5.57624164932992410311e+00,
5.81823213520351704715e+00,
6.06227883261430263882e+00,
6.30854436111213512156e+00,
6.55720703192153931598e+00,
6.80846335285879641431e+00,
7.06253106024886543766e+00,
7.31965282230453531632e+00,
7.58010080785748888415e+00,
7.84418238446082116862e+00,
8.11224731116279191689e+00,
8.38469694041626507474e+00,
8.66199616813451771409e+00,
8.94468921732547447845e+00,
9.23342089021916155069e+00,
9.52896582339011480496e+00,
9.83226980777796909401e+00,
1.01445099412928454695e+01,
1.04671854213428121416e+01,
1.08022607536847145950e+01,
1.11524043855851252649e+01,
1.15214154007870302416e+01,
1.19150619431141658018e+01,
1.23429642228596742953e+01,
1.28237997494878089065e+01,
1.34064873381449101387e+01
};
long double He_100w[50] = {
2.18892629587439125060e-01,
1.98462850254186477710e-01,
1.63130030502782941425e-01,
1.21537986844104181985e-01,
8.20518273912244646789e-02,
5.01758126774286956964e-02,
2.77791273859335142698e-02,
1.39156652202318064178e-02,
6.30300028560805254921e-03,
2.57927326005909017346e-03,
9.52692188548619117497e-04,
3.17291971043300305539e-04,
9.51716277855096647040e-05,
2.56761593845490630553e-05,
6.22152481777786331722e-06,
1.35179715911036728661e-06,
2.62909748375372507934e-07,
4.56812750848493951350e-08,
7.07585728388957290740e-09,
9.74792125387162124528e-10,
1.19130063492907294976e-10,
1.28790382573155823282e-11,
1.22787851441012497000e-12,
1.02887493735099254677e-13,
7.54889687791524329227e-15,
4.82983532170303334787e-16,
2.68249216476037608006e-17,
1.28683292112115327575e-18,
5.30231618313184868536e-20,
1.86499767513025225814e-21,
5.56102696165916731717e-23,
1.39484152606876708047e-24,
2.91735007262933241788e-26,
5.03779116621318778423e-28,
7.10181222638493422964e-30,
8.06743427870937717382e-32,
7.27457259688776757460e-34,
5.11623260438522218054e-36,
2.74878488435711249209e-38,
1.10047068271422366943e-40,
3.18521787783591793076e-43,
6.42072520534847248278e-46,
8.59756395482527161007e-49,
7.19152946346337102982e-52,
3.45947793647555044453e-55,
8.51888308176163378638e-59,
9.01922230369355617950e-63,
3.08302899000327481204e-67,
1.97286057487945255443e-72,
5.90806786503120681541e-79
};


/*********************************************************************************************/
/********************************************************************************************/
/*Regola del trapezio: si basa sull'espansione di taylor in uno dei N punti scelti, integrali solo su
intervallo finito */
// N = numero di punti su cui eseguire l'integrazione, a e b sono gli estremi di integraziobe
//Punti equidistanziati h = (b-a) / N, func è un puntatore alla funzione da usare per
//accedere a funzione passata come parametro (*func)(input)
//INTEGRAZIONE DEL TRAPEZIO
long double trapezio(int N, long double a, long double b, long double (*func)(long double))
{

	long double h = (b-a) / (long double)(N-1) ;
	long double result = 0.0;
	result += 0.5*(func(a) + func(b)); //aggiungo 1/2 f(a)

	for (int i = 1; i < N-1; i++)
	{
		result+= func(a + (long double)i*h);
	}
	result*=h;

	return result;
}


//FORMULE APERTE INTEGRAZIONE DETERMINISTICA 3-5 PUNTI

long double open3(long double a, long double b, long double (*func)(long double))
{
	long double h = (b-a) / 2.0;
	return 2*h*func(a+h);
}

long double open5(long double a, long double b, long double (*func)(long double))
{
	long double h = (b-a) / 5.0;
	return h*(5.0/24.0)*(11*func(a+h) + func(a+2*h) + func(a+3*h) + 11*func(a+4*h));
}
/***************************************************************************************/

//COMPLETAMENTE ROTTO
//INTEGRAZIONE DI SIMPSON
//SIMPSON FUNZIONA SOLO CON NUMERO DI PUNTI MULTIPLI DI 3
long double simpson(int N, long double a, long double b, long double (*func)(long double))
{	
	if(N%2 == 0)
	{	
		printf("Simpson funziona solo con numero dispari\n");
		exit(EXIT_FAILURE);
	}
	long double h = (b-a) / (long double)(N-1) ;
	long double result = 0.0;
	result+= func(a) + func(b);
	for (int i = 1; i < N-1; i++)
	{
		if(i%2 != 0)
		{
			result += 4*func(a+(long double)i*h);
		}else if(i%2 == 0)
		{
			result += 2*func(a+(long double)i*h);
		}
	}
	return result*(h/3.0);

}

/*****************************************************************************/

long double romberg(int N, long double a, long double b, long double (*func)(long double))
{
	//FILE* file;
	//FILE* file2;
	//FILE* file3;
	//FILE* file4;
	//file = fopen("datiRColonna1.txt","w");
	//file2 = fopen("datiRColonna2.txt","w");
	//file3 = fopen("datiRColonna3GIUSTI.txt","w");
	//file4 = fopen("numeroDiPuntiGIUSTI.txt","w");
	//long double result = 672.19323731283680927664;
	//int J = floor(log2(N-1)); 	
	//N in questo caso è il numero di suddivisioni in intervalli da fare
	//cioè N = J
	long double** values = (long double**)malloc(N*sizeof(long double*));
	for (int i = 0; i < N; ++i)
	{
		values[i] = (long double*)malloc(N*sizeof(long double));
	}	


	//collezione dei risultati del trapezio
	//Riempio valuesT con i valori dei trapezi
	for (int i = 0; i < N; ++i)
	{
		values[i][0] = trapezio((int)(pow(2,i)+1),a,b,func); 
		//fprintf(file, "%.10Lf\n",logl(fabsl(values[i][0] - result))); //Printo la prima colonna
		//fprintf(file4, "%lf\n",log(1/(pow(2,i)+1)));
	}

	//Array con tutti i valori ricorsivi successivi
	for (int k = 1; k < N; ++k)
	{
		for (int j = 1; j <= k; ++j) 
		{
			values[k][j] = (pow(4,j)*values[k][j-1] - values[k-1][j-1]) / (pow(4,j) - 1);
			/*
			if(j == 1){
				fprintf(file2, "%.10Lf\n",logl(fabsl(values[k][1]-result)));
			}else if(j == 2){
				fprintf(file3, "%.10Lf\n",logl(fabsl(values[k][2]-result)));
			}
			*/
		}
	}

	//printMatrix(N,values);
	//printTableRomberg(N,values);
	//free(values);
	return values[N-1][N-1];

}

/**********************************************************************************************/

//Metodo delle quadrature gaussiane

//Piccola funzione per traslazione in Legendre da [-1,1] ad [a,b]
long double X(long double a, long double b, long double x)
{
	return ((b-a) / 2.0)*x + (b+a) / 2.0;
}

//Legendre [-1,1]

long double Legendre(int N, long double a, long double b, long double (*func)(long double))
{	
	long double result = 0;
	switch(N)
	{

		case 1:
			result+=func(X(a,b,Le_1[0]))*Le_1[1];
			break;
		case 2:
			result += func(X(a,b,Le_2[0])) + func(X(a,b,Le_2[1]));
			break;
		case 3:
			result += func(X(a,b,Le_x3[0]))*Le_w3[0] + func(X(a,b,Le_x3[1]))*Le_w3[1] + func(X(a,b,-Le_x3[1]))*Le_w3[1]; 
			break;
		case 4:
			for (int i = 0; i < 2; ++i)
			{
				result+= func(X(a,b,Le_x4[i]))*Le_w4[i] + func(X(a,b,-Le_x4[i]))*Le_w4[i]; 
			}
			break;
		case 8:
			for (int i = 0; i < 4; ++i)
			{
				result+= func(X(a,b,Le_x8[i]))*Le_w8[i] + func(X(a,b,-Le_x8[i]))*Le_w8[i];
			}
			break;
		case 16:
			for (int i = 0; i < 8; ++i)
			{
				result+= func(X(a,b,Le_x16[i]))*Le_w16[i] + func(X(a,b,-Le_x16[i]))*Le_w16[i];
			}
			break;
		case 48:
			for (int i = 0; i < 24; ++i)
			{
				result+= func(X(a,b,Le_x48[i]))*Le_w48[i] + func(X(a,b,-Le_x48[i]))*Le_w48[i];
			}
			break;
		default:
			printf("ERRORE: numero di punti scelto non valido per integrazione di Legendre\n");
            printf("Numero di punti validi: 1,2,3,4,8,16,48\n");
            exit(EXIT_FAILURE);

	}

	return result*(b-a)/(2.0);
}

/*************************************************************************************************/

//Laguerre [a,+inf]
//Così da poter integrare da un numero all'infinito
//RICORDARSI DI TOGLIERE IL PESO ESPONENZIALE DA FUNC
long double T(long double a, long double x)
{
	return (x+a);
}

long double Laguerre(int N, long double a, long double (*func)(long double))
{	
	long double result = 0;
	switch(N)
	{

		case 2:
			result+=func(T(a,Lag_2[0]))*Lag_2[1] + func(T(a,Lag_2[2]))*Lag_2[3];
			break;
		case 4:
			for (int i = 0; i < 4; ++i)
			{
				result+=func(T(a,Lag_4x[i]))*Lag_4w[i];
			}
			break;
		case 8:
			for (int i = 0; i < 8; ++i)
			{
				result+=func(T(a,Lag_8x[i]))*Lag_8w[i];
			}
			break;
		case 24:
			for (int i = 0; i < 24; ++i)
			{
				result+=func(T(a,Lag_24x[i]))*Lag_24w[i];
			}
			break;
		case 64:
			for (int i = 0; i < 64; ++i)
			{
				result+=func(T(a,Lag_64x[i]))*Lag_64w[i];
			}
			break;
		default:
			printf("ERRORE: numero di punti scelto non valido per integrazione di Laguerre\n");
            printf("Numero di punti validi: 2,4,8,24,64\n");
            exit(EXIT_FAILURE);

	}

	return result*exp(-a);
}

/*************************************************************************************************/

//Hermite [-inf, inf]
//RICORDARSI DI TOGLIERE IL PESO EXP-X^2 DA FUNC
//Per esercizio 6 (traslo la funzione così che asse sta in x=3, poi copio la parte di funzione
// da 3 a inf e la risbatto a sinistra in modo da renderla simmetrica rispetto all'asse y (pari)
// così poi integro tra -inf e inf e divido a metà e trovo il mio integrale)
//Puoi usare la funzione qua sotto per usare hermite su integrali su [a, inf]
long double aInfH(long double a, long double t, long double (*func)(long double))
{	
	long double value = func(t+a)*exp(-(a*a + 2*a*t)); //Proviene dalla traslazione
	if(t>=0){return value;}
	else if(t<0){return -value;} //Questa parte copia la parte di funzione che mi interessa e la simmetrizza
	else return 0;
}

long double Hermite(int N, long double a, long double (*func)(long double))
{	
	long double result = 0;
	switch(N)
	{

		case 2:
		{
			result += func(He_2[0])*He_2[1] + func(-He_2[0])*He_2[1];
			break;
		}
			
		case 4:
			for (int i = 0; i < 2; ++i)
			{
				result+=func(He_4x[i])*He_4w[i] + func(-He_4x[i])*He_4w[i]; 
			}
			break;
		case 5:
			for (int i = 1; i < 3; ++i)
			{
				result+=func(He_5x[i])*He_5w[i] + func(-He_5x[i])*He_5w[i];	
			}
			result+=func(He_5x[0])*He_5w[0];
			break;
		case 8:
			for (int i = 0; i < 4; ++i)
			{
				result+=func(He_8x[i])*He_8w[i] + func(-He_8x[i])*He_8w[i];	
			}
			break;
		case 10:
			for (int i = 0; i < 5; ++i)
			{
				result+=func(He_10x[i])*He_10w[i] + func(-He_10x[i])*He_10w[i];
			}
			break;
		case 24:
		{	
			for (int i = 0; i < 12; ++i)
			{
				result+=func(He_24x[i])*He_24w[i] + func(-He_24x[i])*He_24w[i];
			}
			break;
		}
		case 48:
		{
			for (int i = 0; i < 24; ++i)
			{
				result+=func(He_48x[i])*He_48w[i] + func(-He_48x[i])*He_48w[i];
			}
			break;
		}
		case 100:
		{
			for (int i = 0; i < 50; ++i)
			{
				result+=func(He_100x[i])*He_100w[i] + func(-He_100x[i])*He_100w[i];
				//result+=aInfH(a, He_100x[i],func)*He_100w[i] + aInfH(a,-He_100x[i],func)*He_100w[i];
			}
			break;
		}
		default:
			printf("ERRORE: numero di punti scelto non valido per integrazione di Hermite\n");
            printf("Numero di punti validi: 2,4,5,8,10,24,48,100\n");
            exit(EXIT_FAILURE);

	}

	return result;
}

/*************************************************************************************/
//Integrazione stocastica
/*************************************************************************************/


//Generatore numeri casuali tra a e b
long double uniformRandom(long double a, long double b)
{
	return a + (b - a) * rand () / (long double) (RAND_MAX) ;
}

//Metodo di monte carlo (trapezio+distribuzione uniforme)
long double monteCarlo(int N, long double a, long double b, long double (*func)(long double))
{

	//Prima genera N numeri casuali distribuiti uniformemente tra a e b
	//Usa quei numeri per implementare il trapezio
	long double h = (b-a) / (long double)(N) ;
	long double result = 0.0;
	int counter = 0;
	while(counter < N){
	
		result+=func(uniformRandom(a,b));
		counter++;
	}
	result*=h;

	return result;
	
	
}


//Variante Monte Caro hit or miss
long double hit_or_miss(int N, long double a, long double b, long double(*func)(long double), long double max)
{
	int n_hit = 0;
	long double result = 0;
	long double x = 0;
	long double y = 0;
	for (int i = 0; i < N; ++i)
	{
		//genera 2 numeri (x,y) random tra a e b e tra min e max (y)
		x = uniformRandom(a,b);
		y = uniformRandom(0,max);
		if(y<=func(x)){n_hit++;} //se y è una ordinata accettabile allora ho un hit, altrimenti un miss
	}
	result = (long double)(n_hit) / (long double)(N) ; //percentuale dell'area
	result*=(b-a)*(max); //area o volume di cui prendo la percentuale calcolata prima
	return result;
}

/************* IMPORTANCE SAMPLING **********************************************/
//La pdf da usare va scelta in base alla funzione da integrare
//Esempio I delle note
//pdf = pdf scelta, inversecumulative = inversa della primitiva della pdf, func = funzione iniziale
// da integrare
long double pdf(long double x)
{	
	//Qui scelgo la pdf da usare, di cui poi calcolerò la primitiva inversa
	return (1 / (1- exp(-2)) )*exp(-x);
}
long double inverseCumulative(long double x)
{	
	//Qui metto la cumulativa inversa
	long double a = 1 / (1-exp(-2)); //normalizzazione
	return -log(a - x);
}

long double importanceSampling(int N, long double (*func)(long double))
{	
	long double result = 0;
	long double z = 0;
	for (int i = 0; i < N; ++i)
	{	
		z = uniformRandom(0,1);
		result+= func(inverseCumulative(z)) / pdf(inverseCumulative(z));
	}
	result*= 1 / (long double)N;
	return result;
}