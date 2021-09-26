/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW07P04
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
using namespace std;

//------------------------------------------------------------
int main (int argc, char * const argv[]) {
	int a = 100;
	int &b = a;
	int *c = &b;
	int d;
	int e = &d - &a;
	cout << e << endl;
	return 0;
}
//------------------------------------------------------------
