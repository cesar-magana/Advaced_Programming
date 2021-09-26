/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW07P02
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
#include <cstdlib>
using namespace std;
//------------------------------------------------------------
//Reserva memoria.
void allocate (int *&v, int s){
	v = (int *)malloc(sizeof(int)*s);
}


//------------------------------------------------------------
//Libera memoria.
void desallocate (int *&v){
	free(v);
}


//------------------------------------------------------------
//Suma
void add (int a, int b, int &result){
	result = a+b;
}


//------------------------------------------------------------
int main (int argc, char * const argv[]) {
	int v1 = 2, v2 = 3, v3, *v4;
	add(v1, v2, v3);
	cout << v1 << " + " << v2 << " = " << v3 << endl;
	allocate(v4, v2);
	cout << "v4 = " << (v4) << endl;
	desallocate(v4);
	return 0;
}
//------------------------------------------------------------

