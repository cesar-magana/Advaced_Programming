/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW21P01
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <set>

using namespace std;
//------------------------------------------------------------
void show_syntax(string name){
	printf("Sintaxis: \n  %s [NOMBRE DEL ARCHIVO]\n",name.c_str());
}

//------------------------------------------------------------
int main (int argc, char * const argv[]) {
	char ch;
	int option;
	set<char> char_set;

	if( argc < 2 )
		{
		show_syntax(argv[0]);	
		return 0;
		}

	ifstream file (argv[1], ios::in);
	if( !file.is_open() )
		{
		cout << "Error al abrir el archivo." << endl;
		return 0;
		}

	while( file >> ch )
		char_set.insert(ch);

	file.close();
	
	do
		{
		cout << "Opciones: " << endl;
		cout << "  [ 1 ]    \tBuscar un caracter." << endl;
		cout << "  [ OTRO ] \tSalir." << endl;
		cout << "     Opcion: ";
		cin >> option;
		cout << option << endl;
		if( option == 1 )
			{
			cout << endl << "Caracter a buscar: ";
			cin >> ch;
			cout << "El caracter " << ch;
			if( char_set.find(ch) != char_set.end() )
				cout << " si esta." << endl;
			else
				cout << " no esta." << endl;
			}
		cout << endl << endl;
		}
	while(option == 1);
	
	return 0;
}
//------------------------------------------------------------
