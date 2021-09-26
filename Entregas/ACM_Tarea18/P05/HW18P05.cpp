/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW18P05
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
using namespace std;

//------------------------------------------------------------
int replace( string &linea, string sustituye, string variable ){
	int lon=sustituye.length();
	int pos;
	int contiene_cadena=0;
	if ((pos=linea.find(sustituye))<linea.length())
		 {
		 linea=linea.substr(0,pos)+variable+linea.substr(pos+lon,linea.length()-pos-lon);
		 contiene_cadena=1;
		 }
 return contiene_cadena;	
}


//------------------------------------------------------------
int main (int argc, char * const argv[]) {
	string input = "Querida Sa. <name>, usted y el Sr. <name> son los felices ganadores de un viaje para dos personas en XXXXXX. Su viaje para XXXX ha sido ya planeado.";
	replace(input,"<name>","Fernandez");
	replace(input,"<name>","Bravo");
	replace(input,"XXXXXX","AUSTRALIA");
	replace(input,"XXXX","AUSTRALIA");
	replace(input,"felices","infelices");
	replace(input,"planeado.","planeado para NOVIEMBRE.");
	cout << input	<< endl;
	return 0;
}
//------------------------------------------------------------
