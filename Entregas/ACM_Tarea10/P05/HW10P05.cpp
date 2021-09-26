/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW10P05
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
#include "Complejo.h"


double Real(Complex c){
	return c.real();
}

double Imag(Complex c){
	return c.imaginary();
}


//------------------------------------------------------------
int main (int argc, char * const argv[]) {
	Complex c1(2, -4), c2(-3, 0), *c3;
	
	c3 = new Complex;

	cout << c1 << endl; 
	cout << c2 << endl; 
	cout << c3 << endl; 

	c3->copy(c1);
	cout << c3 << endl; 

	c1.mul(3.0);
	c1.mul(c2);
	cout << c1 << endl; 

	cout << "Aqui se puede ver la identidad Re( z ) = Modulo( z )^2:"<<endl;
	cout << "Para x = ";
	cout << c1 << endl; 
	c2 = c1;
	cout << endl;
	cout << "Re( x ) = " << Real(c1.mul(c1.conjugado())) << endl;
	cout << "Modulo( x )^2 = " << c2.modulo()*c2.modulo() << endl;

	delete c3;    return 0;
}
//------------------------------------------------------------
