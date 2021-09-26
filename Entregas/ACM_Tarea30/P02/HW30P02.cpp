/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW30P02
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
#include <vector>
using namespace std;
#define FOR(i, n) for( int i = 0, _n = (n); i < _n; i++ )

//---------------------------------------------------------------------------
template<class T, template<class> class A>
T minimo(const A<T> &x)
	{
	int n = x.size();
	int m = n/2;
	T minimun = x[m];
	for( int i=m;i<n;i++ )
		if( x[i]<minimun )
			minimun = x[ i ];
	return minimun;
	}

//---------------------------------------------------------------------------
int main(int argc, char* argv[])
	{
	int n=7;
	vector<int> vheap(n);
	srand(time(NULL));

	vheap.resize(7);
	vheap[ 0 ] = 82;
	vheap[ 1 ] = 67;
	vheap[ 2 ] = 43;
	vheap[ 3 ] = 49;
	vheap[ 4 ] = 10;
	vheap[ 5 ] = 32;
	vheap[ 6 ] = 43;		
	
	cout << "Primera prueba." <<  endl << "El monticulo es:" << endl;
	FOR(i,n)
		cout << vheap[i] << " ";
	cout << endl << "El minimo del monticulo es: " << minimo(vheap) << endl<< endl;

	n=150;
	vheap.resize(n);
	vheap[0]=1000;
	FOR (i,n-1)
		vheap[i+1]=vheap[(i+1)/2]-rand()%100;
	cout << "Segunda prueba." <<  endl << "El monticulo es:" << endl;
	FOR(i,n)
		cout << vheap[i] << " ";
	cout << endl << "El minimo del monticulo es: " << minimo(vheap) << endl<< endl;

	n=256;
	vheap.resize(n);
	vheap[0]=20;
	FOR(i,n)
		vheap[i+1]=vheap[(i+1)/2]-rand()%3;
	cout << "Tercera prueba." << endl << "El monticulo es:" << endl;	
	FOR(i,n)
		cout << vheap[i] << " ";
	cout << endl <<  "El minimo del monticulo es: " << minimo(vheap) << endl<< endl;
	return 0;
	}
//---------------------------------------------------------------------------
