/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW09P05
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

	c1.print(); 
	cout << endl;
	c2.print(); 
	cout << endl;
	c3->print(); 
	cout << endl;

	c3->copy(c1);
	c3->print(); 
	cout << endl;

	c1.mul(3.0);
	c1.mul(c2);
	c1.print();

	cout << endl;
	cout << "Aqui se puede ver la identidad Re( z ) = Modulo( z )^2:"<<endl;
	cout << "Para x = ";
	c1.print();
	c2 = c1;
	cout << endl;
	cout << "Re( x ) = " << Real(c1.mul(c1.conjugado())) << endl;
	cout << "Modulo( x )^2 = " << c2.modulo()*c2.modulo() << endl;

	delete c3;    return 0;
}
//------------------------------------------------------------
