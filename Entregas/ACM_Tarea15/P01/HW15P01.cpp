/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW15P01
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream> 


//------------------------------------------------------------
class Base 
	{ 
	public: 
		virtual void funcion(){}
		//virtual void funcion() const=0; 
	}; 


//------------------------------------------------------------
class Derivada : public Base
	{ 
	public: 
		void funcion(); 
	}; 


//------------------------------------------------------------
int main() { 
	Base *bp = new Derivada(); 
	bp->funcion(); 
	delete bp; 
	return 0; 
} 


//------------------------------------------------------------

void Derivada::funcion(){ 
	std::cout << "Cogito ergo sum" << std::endl; 
} 
//------------------------------------------------------------
