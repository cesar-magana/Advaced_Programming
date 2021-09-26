/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW25P05
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
#include <cmath>

#define FOR(i, n) for( int i = 0, _n = (n); i < _n; i++ )
using namespace std;

//------------------------------------------------------------
void genera_arreglo (int *T, const int N)
	{
	FOR (i,N)
		T[i] = i+1;	
	T[14] = T[88];
	}


//------------------------------------------------------------
void pinta_arreglo (int *T, const int N)
	{
	cout << "n=" << N << endl;
	FOR (i,N)
		cout << T[i] << " ";
	cout << endl;
	}


//------------------------------------------------------------
void identifica (int *T, const int n, int &duplicado, int &ausente)
	{
	int sum_verdadera      = n*(n+1)/2;
	int sum_verdadera_cuad = n*(n+1)*(2*n+1)/6;
	int sum_arreglo        = 0;
	int sum_arreglo_cuad   = 0;
	FOR(i,n)
		{
		sum_arreglo      += T[i];
		sum_arreglo_cuad += T[i]*T[i];
		}
	int C1 = sum_verdadera-sum_arreglo;
	int C2 = sum_verdadera_cuad-sum_arreglo_cuad;
	ausente = (C1*C1+C2)/(2*C1);
	duplicado = ausente-C1;
	}


//------------------------------------------------------------
int main (int argc, char * const argv[]) {
	const int N=100;
	int duplicado, ausente;
	int *T;
	T= new int[N];
	genera_arreglo (T, N);
	pinta_arreglo (T, N);
	identifica (T, N, duplicado, ausente);	
	cout << "El numero duplicado:" << duplicado << endl;
	cout << "El numero ausente:" << ausente << endl;
	delete T;
	return 0;
}
//------------------------------------------------------------
