/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW10P01b
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
int main (int argc, char * const argv[]) {
	cout << "Inicio del programa."	<< endl;

	for (int i=0; i< 10;i++){
	cout << i << endl;
	Objeto prueba;
	if (i==5)goto stop;
	}
	
	stop:
	cout << "Fin del programa." << endl;
  return 0;
}
//------------------------------------------------------------
