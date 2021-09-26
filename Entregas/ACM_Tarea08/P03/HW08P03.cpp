/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW08P03
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
#include <cmath>
using namespace std;

struct myStruct{
	double a,b;
	float *data;
	int doSomething( const int &x )
		{
		//data = (float*) x;
		data = reinterpret_cast<float *>( x ); // No se usa después.
		//double b = pow(x,a)+pow(x,b);
		double b = pow(static_cast<int>(x),a)+pow(static_cast<int>(x),b);
		//return b;
		return static_cast<int>(b);
		}
	void setData( int *const someData )
		{
		//data = (float*) someData;
		data = reinterpret_cast<float *> (someData);
		}
};

//------------------------------------------------------------
int main (int argc, char * const argv[]) {
   
	int a[10];
	myStruct m;
	m.setData( &a[0] );
	return 0;

}
//------------------------------------------------------------
