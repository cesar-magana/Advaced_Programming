/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW10P01
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
using namespace std;

//------------------------------------------------------------
class Objeto{
	public:
			Objeto();
			~Objeto();
};


//------------------------------------------------------------
Objeto::Objeto(){
	cout << "Objeto construido"<< endl;
}


//------------------------------------------------------------
Objeto::~Objeto(){
	cout << "Objeto destruido" << endl;
}


//------------------------------------------------------------
void funcion_ejemplo(){
	cout << "Inicio de la funcion de ejemplo."	<< endl;
	Objeto prueba1;
	cout << "Fin de la funcion de ejemplo."	<< endl;
}


//------------------------------------------------------------
int main (int argc, char * const argv[]) {
	cout << "Inicio del programa."	<< endl;
	
	funcion_ejemplo();
	cout << "Fin del programa." << endl;
  return 0;
}
//------------------------------------------------------------
