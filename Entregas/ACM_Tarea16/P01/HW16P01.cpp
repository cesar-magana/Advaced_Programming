/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW16P01
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>

using namespace std;
class Toto { }; 
template<class T> 
class Truc 
	{
	private:
		int i;		
	public:
		template <class U> 
		void someMethod(Truc<U>& s) 
			{ 
			s.i = 3; 
			}
	}; 


//------------------------------------------------------------
int main (int argc, char * const argv[]) {
	Truc<int> a; 
	Truc<Toto> b, c; 
	a.someMethod(b); 
	b.someMethod(c);
}
//------------------------------------------------------------
