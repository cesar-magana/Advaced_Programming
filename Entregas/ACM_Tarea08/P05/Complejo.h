//---------------------------------------------------------------------------

#ifndef complejoH
#define complejoH

#include <iostream>
#include <cmath>

using namespace std;

class Complex
	{
    public:
		
        // Constructor
        Complex();
        Complex( double _a, double _b );
        void *operator new( size_t s );

        //Funciones
        void  print();
        const Complex &copy( const Complex &c );
        const Complex &add ( const Complex &c );
        const Complex &mul ( const Complex &c );
        const Complex &mul ( double d );
        Complex conjugado();
        double modulo();
				double angulo();

        void   SetReal( double _a );
        void   SetImag( double _b );
        double real();
        double imaginary();
				double a, b; // a + ib
				
				
				//Operadores
				//Suma
        Complex operator + (const Complex &c1) const
					{
					Complex c2(this->a + c1.a, this->b + c1.b);
					return c2;
					}
				
				//Resta
        Complex operator - (const Complex &c1) const
					{
					Complex c2(this->a - c1.a, this->b - c1.b);
					return c2;
					}
				
				//Multiplicación
        Complex operator * (const Complex &c1) const
					{
					Complex c2(this->a*c1.a - this->b*c1.b, this->a*c1.b + this->b*c1.a);
					return c2;
					}
					
				//División
				Complex operator / (const Complex &c1) const
					{
					Complex c2, c3;
					c3=c1;
					c3=c3.conjugado();
					c2= *this *c3;
					double d = c3.modulo();
					d *= d;
					c2.a /= d;
					c2.b /= d;
					return c2;
					}					
				
				//Sobrecarga del operador =
				Complex& operator=(const Complex& c1) 
					{ 
					a = c1.a; 
					b = c1.b; 
					return *this; 
					} 

    private:
		
	};
	
 ostream &operator << (ostream &out, const Complex& c);
	
#endif
