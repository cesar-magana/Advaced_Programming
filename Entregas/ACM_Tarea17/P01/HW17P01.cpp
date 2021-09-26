/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW17P01
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;

//------------------------------------------------------------
class Excepcion
	{
	public:
		Excepcion( const string &_msg) : msg(_msg)
			{
			cout << "Excepcion creada: "	<< msg << endl;
			}
		const string &getMsg() const
			{
			return msg;
			}
		~Excepcion()
			{
			cout << "Excepcion destruida: " << msg << endl;
			}
	private:
		string msg;
	};


//------------------------------------------------------------
void funcionError()
	{
	throw Excepcion("Excepcion por valor.");
	}
	


//------------------------------------------------------------
void funcionErrorApuntador()
	{
	Excepcion *apuntador = new Excepcion("Excepcion por apuntador");
	throw apuntador;
	}


//------------------------------------------------------------
void funcionErrorReferencia()
	{
	Excepcion regresa("Excepcion por referencia");
	Excepcion &referencia = regresa;
	throw referencia;
	}
	
	
//------------------------------------------------------------
int main (int argc, char * const argv[]) {
	try
		{
		funcionError();
		}
	catch (...)
		{
		cout << "Se ha arrojado una excepcion." << endl;
		}		

	cout << endl;
	try
		{
		funcionErrorApuntador();
		}
	catch (Excepcion *cosa)
		{
		cout << "Se ha arrojado una excepcion por apuntador y no se llama al destructor." << endl;
		}		

	cout << endl;
	try
		{
		funcionErrorReferencia();
		}
	catch (Excepcion &cosa)
		{
		cout << "Se ha arrojado una excepcion por referencia y se llama al destructor dos veces." << endl;
		}		
	cout << endl;

	return 0;
}
//------------------------------------------------------------
