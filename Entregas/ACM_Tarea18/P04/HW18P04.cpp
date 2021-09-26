/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW18P04
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//------------------------------------------------------------
void show_syntax(string name){
	printf("Sintaxis: \n  %s [NOMBRE DEL ARCHIVO]\n",name.c_str());
}


//------------------------------------------------------------
int main (int argc, char * const argv[]) {
	string word;
	int word_count				= 0;
	int total_word_count	= 0;
	int phrase_count			= 1;

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
	cout << phrase_count << ". ";
	while( file >> word )
		{
		word_count++;
		cout << word << " ";
		if ( word[word.length()-1]=='.' )
			{
			phrase_count++;
			cout << endl;
			cout << "Frase numero: " << (phrase_count-1) << ". ";
			cout << "Cantidad de palabras: " << word_count	<< endl << endl;
			word_count = 0;
			}
		total_word_count++;
		}	
	cout << endl;
	cout << "Numero de frases: " << phrase_count-1 << endl;
	cout << "Promedio de palabras por frase: " << total_word_count/(phrase_count-1) << endl;
	
	file.close();
	return 0;
}
//------------------------------------------------------------
