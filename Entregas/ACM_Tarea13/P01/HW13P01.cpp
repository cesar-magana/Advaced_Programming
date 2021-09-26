/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW13P01
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>

using namespace std;

//------------------------------------------------------------
class Class1{
	public:

		static int static_method()
			{
			return 1;
			}

		int method( int a )
			{
			return 2;
			}

		int method( Class1 &otro )
			{
			return 3;
			}

};


//------------------------------------------------------------
class Class2 : public Class1{
	public:

		static int static_method()
			{
			return 4;
			}

		int method( int a )
			{
			return 5;
			}
			
};


//------------------------------------------------------------
int main (int argc, char * const argv[]) {
	Class1 a;
	Class2 b;

	// Metodo static
	cout << b.static_method() << endl;

	/* 
	Si se descomentan las siguientes líneas es claro que los métodos de
	Class1 son escondidos. Si descomentara, no compilaría ya que no reconoce 
	los métodos:
	method( int a ) ni method( Class1 & )
	*/
	
	//b.method();
	//b.method(a);
	cout << b.method(1) << endl;

	return 0;
}
//------------------------------------------------------------
