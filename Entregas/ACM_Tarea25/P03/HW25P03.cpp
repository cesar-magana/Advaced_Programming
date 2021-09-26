/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW25P03
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
#include <vector>
using namespace std;

/*
Método de Horner para evaluación de polinomios.
ENTRADA:
	Vector de coeficientes a_i del polinomio p(x) =a_0+a_1x+...+a_nx^n.
	Punto de evaluación z.
SALIDA:
	p(z)
*/
template<class T>
T horner(vector <T> a, T z){
	int n=a.size();
	vector <T> b;
	b.resize(n+1);
	b[0]=a[0];
	for (unsigned int j=1; j<n; j++)
		b[j] = a[j]+b[j-1]*z;
	return b[n-1];
}

//------------------------------------------------------------
int main (int argc, char * const argv[]) {
	vector <double> a;
	a.resize(7);
	a[0]=1.0;
	a[1]=2.0;
	a[2]=3.0;
	a[3]=4.0;
	a[4]=5.0;
	a[5]=6.0;
	a[6]=7.0;
	double res= horner(a,5.0);
	cout << res << endl;
	return 0;
}
//------------------------------------------------------------
