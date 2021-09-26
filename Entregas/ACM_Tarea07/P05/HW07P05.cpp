/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW07P05
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <ctime> 
#include <iostream>
#include <cstdlib>
using namespace std;

float Tab[10] = {3.141592, 2.7178, 1.1, 0.00003, 2.2, 1.1111111, 90.45, 32.32, 1.0, 0.5};

//------------------------------------------------------------
//Función aleatoria.
float& aleatoria(void){
	srand(time(0));  
	int r = (rand() % 10);
	return Tab[r];
}


//------------------------------------------------------------
//Función maliciosa.
void maliciosa( const float &val ){
	const_cast <float&>(val);
  float& val2 = const_cast<float&>(val);
	val2 = aleatoria();	
}


//------------------------------------------------------------
int main (int argc, char * const argv[]) {

	cout << "Entrada original: " << Tab[0] << endl;
	maliciosa( Tab[0] );
	cout << "Entrada cambiada: " << Tab[0] << endl;
  return 0;
}
//------------------------------------------------------------
