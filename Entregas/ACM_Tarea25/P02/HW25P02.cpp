/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW25P01
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
#define FOR(i, n) for( int i = 0, _n = (n); i < _n; i++ )

using namespace std;
//------------------------------------------------------------
void lee_matriz(int **T, const int N)
	{
	FOR (i,N)
		T[i] = new int[N];
	int k=5;
	FOR (i,N)
		FOR (j,N)
			T[i][j] = 2*k++;
	}


//------------------------------------------------------------
void pinta_matriz(int **T, const int N)
	{
	FOR (i,N)
		{
		FOR (j,N)
			cout << T[i][j] << " ";
		cout << endl;
		}
	}


//------------------------------------------------------------
int existe_entero(int **T, int n, int k)
	{
	int i=n-1,j=0;
	while (i>0 && j<n-1)
		{
		cout << T[i][j] << "->";
		if (abs(k-T[i-1][j]) < abs(k-T[i][j+1]) )
			i--;
		else 
			j++;
		if (T[i][j]==k)
			return T[i][j];			
		}
	if (i==0)
		for (int l=j; l<n;l++)
			{
			if(T[i][l]==k)
				return T[i][l];
			cout << T[i][l] << "->";
			}
	if (j==n-1)
		for (int l=i; l>-1;l--)
			{
			if(T[l][j]==k)
				return T[l][j];
			cout << T[l][j] << "->";
			}
	return 0;
	}


//------------------------------------------------------------
int main (int argc, char * const argv[]) {
	const int N=10;
	int existe;
	int k=1;
	//Aqui se crea la matriz
	int **T;
	T=new int*[N];
	lee_matriz(T,N);
	pinta_matriz(T,N);
	
	cout <<	endl <<"Introducir el numero que se va a buscar: ";
	cin >> k;		
	cout << endl << "Camino a seguir a partir de T[n-1][0]=" << T[N-1][0] << ":" << endl;
	existe=existe_entero(T,N,k);
	if (!existe)
		cout	<< endl << "No existe el elemento "<<	k	<< endl;
	else cout << existe << endl;
			
	FOR (i,N)
		delete T[i];
	delete T;
	return 0;
}
//------------------------------------------------------------
