/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I EX01P02
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
#include "Vector3D.h"
using namespace std;
//------------------------------------------------------------
int main (int argc, char * const argv[]) {
	Vector3D<double> a( -2.0, 1.0, 9.5 );
	Vector3D<double> b( 7.8, -3.0, 10.1 );
	Vector3D<double> c;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	c=a+b;
	cout << "a + b: " << c << endl;
	c=a-b;
	cout << "a - b: " << c << endl;
	cout << "a.b: " << a*b << endl;

	cout << "Norm of a: " << a.norm() << endl;
	cout << "Norm of b: " << b.norm() << endl;

	return 0;
}
//------------------------------------------------------------
