/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW17P03
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
using namespace std;
//------------------------------------------------------------
int main (int argc, char * const argv[]) {
	double *ejemplo;
	try
		{
		ejemplo = new double[1000000000];
		}
	catch (exception &e)
		{
		
		cout << "Excepcion del sistema: " << e.what() << endl;
		}
	if ( ejemplo!=NULL )
		cout << "Si reservé memoria" << endl;
	else
		cout << "No reservé memoria" << endl;
	delete ejemplo;
	return 0;
}
//------------------------------------------------------------
