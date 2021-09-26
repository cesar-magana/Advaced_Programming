/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW07P06
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
#include <vector>
#include <fstream>

#define FOR(i, n) for( int i = 0, _n = (n); i < _n; i++ )
using namespace std;

//------------------------------------------------------------
//Función que muestra la sintaxis del programa.
void ShowSyntax(const char * nombre){
   cout << "Sintaxis: " << endl << nombre <<  "[NOMBRE DEL ARCHIVO]" << endl;
}


//------------------------------------------------------------
//Función que calcula el número de frecuencias en un archivo de texto dado.
vector< pair<int, char> > calcula_frecuencias ( const string &entrada ){
	char c;
	vector< pair<int, char> > frec( 26 );
	ifstream ENTRADA( entrada.c_str() );

	if ( !ENTRADA.is_open() )
		return frec;

	FOR ( i,26 )
		{
		frec[ i ].first  = 0;
		frec[ i ].second = 97 + i;
		}

	while( !ENTRADA.eof() )
		{
		ENTRADA.get( c );
		if( isalpha( c ) )
			{
			c = tolower( c );
			frec[ c - 97 ].first++;
			}
		}
	ENTRADA.close();
	return frec;
}


//------------------------------------------------------------
int main (int argc, char * const argv[]) {
	vector< pair<int, char> > frecuencias;
	vector< pair< int, char> > frecuencias_originales;

	if ( argc < 2)
		ShowSyntax( argv[0] );
	
	frecuencias_originales = calcula_frecuencias( argv[1] );
	sort( frecuencias_originales.begin(), frecuencias_originales.end() );
	reverse( frecuencias_originales.begin(), frecuencias_originales.end() );
	
	cout << "TABLA DE FRECUENCIAS: "<< argv[1] << endl;
	FOR ( i,26 )
		cout << 	frecuencias_originales[ i ].second << " - " <<
							frecuencias_originales[ i ].first << endl;
	
	return 0;
}
//------------------------------------------------------------

