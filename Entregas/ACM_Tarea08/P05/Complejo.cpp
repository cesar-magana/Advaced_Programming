#include "Complejo.h"

//------------------------------------------------------------
//Constructores.
Complex::Complex(){
	a = b = 0;
}

Complex::Complex( double _a, double _b ){
	a = _a;
	b = _b;
}

void *Complex::operator new(size_t s){
	return ::operator new(s);
}


//------------------------------------------------------------
//Función que imprime.
void Complex::print(){
	cout << this->a;
	if( b >= 0 )
			cout << "+";
	cout << this->b << "i";
}


//------------------------------------------------------------
//Copia.
const Complex &Complex::copy( const Complex &c ){
	this->a = c.a;
	this->b = c.b;
	return ( *this );
}


//------------------------------------------------------------
//Suma.
const Complex &Complex::add ( const Complex &c ){
	this->a += c.a;
	this->b += c.b;
	return ( *this );
}


//------------------------------------------------------------
//Multiplicación por complejo. 
const Complex &Complex::mul ( const Complex &c ){
	this->a = this->a*c.a - this->b*c.b;
	this->b = this->a*c.b + this->b*c.a;
	return (*this);
}


//------------------------------------------------------------
//Multiplicación por un escalar.
const Complex &Complex::mul ( double d ){
  this->a *= d;
  this->b *= d;
	return (*this);
}


//------------------------------------------------------------
//Conjugado.
Complex Complex::conjugado(){
	Complex c = (*this);
  c.b = -c.b;
  return c;
}


//------------------------------------------------------------
//Modulo
double Complex::modulo(){
	return sqrt(this->a*this->a + this->b*this->b);
}


//------------------------------------------------------------
//Ángulo
double Complex::angulo(){
	return atan(this->a/this->b);
}


//------------------------------------------------------------
//Set y Get
void Complex::SetReal( double _a ){
	a = _a;
}


//------------------------------------------------------------
void Complex::SetImag( double _b ){
	b = _b;
}


//------------------------------------------------------------
double Complex::real(){
	return this->a;
}


//------------------------------------------------------------
double Complex::imaginary(){
	return this->b;
}


//------------------------------------------------------------
ostream &operator << (ostream &out, const Complex& c)
	{
	out << c.a;
	if( c.b >= 0 )
			out << "+";
	out << c.b << "i";
	return out;
	}
	

//------------------------------------------------------------


