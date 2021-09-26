/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW11P01
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
#include "Complejo.h"


inline double Real(Complex c){
	return c.real();
}

inline double Imag(Complex c){
	return c.imaginary();
}


//------------------------------------------------------------
int main (int argc, char * const argv[]) {
	Complex c1(2, -4), c2(-3, 0), *c3, c4;
	c3 = new Complex;
	cout << "Clase Complejo: " << endl << endl;
	cout << "c1= "<< c1 << endl; 
	cout << "c2= "<< c2 << endl; 
	c3->copy(c1);
	cout << "c3->copy(c1)=> *c3="<< (*c3) << endl; 
	c4=c1.conjugado();
	cout << "c4= c1.conjugado()="<< c4 << endl; 
	c1.add(c2);
	cout << "c1=c1+c2= " << c1 << endl; 
	c1.mul(3.0);
	cout << "c1=c1*3.0= " << c1 << endl; 
	c1.mul(c2);
	cout << "c1=c1*c2= " << c1 << endl; 
	c2.SetReal(4.0);
	cout << "c2.SetReal(4.0)=> c2=" << c2 << endl; 
	c2.SetImag(-2.0);
	cout << "c2.SetImag(-1.0)=> c2=" << c2 << endl; 
	cout << "Angulo c1= " << c1.angulo() << endl;
	cout << "Modulo c1= " << c1.modulo() << endl;
	cout << "Re(c1)= " << c1.real() << endl;
	cout << "Im(c1)= " << c1.imaginary() << endl << endl;
	cout << "Aqui se puede ver la identidad Re( z ) = Modulo( z )^2:"<<endl;
	cout << "Para c1 = ";
	cout << c1 << endl; 
	c2 = c1;
	cout << endl;
	cout << "Re( c1 ) = " << Real(c1.mul(c1.conjugado())) << endl;
	cout << "Modulo( c1 )^2 = " << c2.modulo()*c2.modulo() << endl;

	delete c3;    return 0;
}
//------------------------------------------------------------
