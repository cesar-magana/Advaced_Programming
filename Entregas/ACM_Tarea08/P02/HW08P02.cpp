/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW08P08
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>

struct toto{
	int i;
};

//------------------------------------------------------------
int main (int argc, char * const argv[]) {
	toto *arreglo = new toto[10];
	for ( int k=0; k<10; k++ )
		arreglo[k].i = 1;
	delete[] arreglo;
	return 0;
}
//------------------------------------------------------------
