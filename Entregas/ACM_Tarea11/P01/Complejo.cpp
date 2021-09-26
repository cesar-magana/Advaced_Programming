#include "Complejo.h"



//------------------------------------------------------------
ostream &operator << (ostream &out, const Complex& c)
	{
	out << c.a;
	if( c.b >= 0 )
			out << "+";
	out << c.b << "i";
	return out;
	}


