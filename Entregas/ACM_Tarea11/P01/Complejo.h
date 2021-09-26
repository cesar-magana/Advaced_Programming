//---------------------------------------------------------------------------

#ifndef complejoH
#define complejoH

#include <iostream>
#include <cmath>

using namespace std;

class Complex
	{
    public:
				double a, b; // a + ib
				//------------------------------------------------------------
				//Constructores.
				Complex(){
					a = b = 0;
				}

				Complex( double _a, double _b ){
					a = _a;
					b = _b;
				}

				void *operator new(size_t s){
					return ::operator new(s);
				}


				//------------------------------------------------------------
				//Función que imprime.
				inline void print(){
					cout << this->a;
					if( b >= 0 )
							cout << "+";
					cout << this->b << "i";
				}


				//------------------------------------------------------------
				//Copia.
				inline const Complex &copy( const Complex &c ){
					this->a = c.a;
					this->b = c.b;
					return ( *this );
				}


				//------------------------------------------------------------
				//Suma.
				 inline const Complex &add ( const Complex &c ){
					this->a += c.a;
					this->b += c.b;
					return ( *this );
				}


				//------------------------------------------------------------
				//Multiplicación por complejo. 
				inline const Complex &mul ( const Complex &c ){
					this->a = this->a*c.a - this->b*c.b;
					this->b = this->a*c.b + this->b*c.a;
					return (*this);
				}


				//------------------------------------------------------------
				//Multiplicación por un escalar.
				const Complex &mul ( double d ){
					this->a *= d;
					this->b *= d;
					return (*this);
				}


				//------------------------------------------------------------
				//Conjugado.
				inline Complex conjugado(){
					Complex c = (*this);
					c.b = -c.b;
					return c;
				}


				//------------------------------------------------------------
				//Modulo
				inline double modulo(){
					return sqrt(this->a*this->a + this->b*this->b);
				}


				//------------------------------------------------------------
				//Ángulo
				inline double angulo(){
					return atan(this->a/this->b);
				}

				//------------------------------------------------------------
				//Set y Get
				inline void SetReal( double _a ){
					a = _a;
				}


				//------------------------------------------------------------
				inline void SetImag( double _b ){
					b = _b;
				}


				//------------------------------------------------------------
				inline double real(){
					return this->a;
				}


				//------------------------------------------------------------
				inline double imaginary(){
					return this->b;
				}
				
    private:
		
	};
	
ostream &operator << (ostream &out, const Complex& c);
	
#endif
