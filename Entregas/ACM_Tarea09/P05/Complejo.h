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

        void   SetReal( double _a );
        void   SetImag( double _b );
        double real();
        double imaginary();

    private:
		
        double a, b; // a + ib

	};
#endif
