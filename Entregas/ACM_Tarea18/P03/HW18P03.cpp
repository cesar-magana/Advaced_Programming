/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW18P03
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
#include <string>


using namespace std;

template <class T>
int count_minuscule(T in){
	int count=0;
	//string::iterator it;
	for (unsigned int i=0; i< in.length(); i++)
	//for (it=in.begin(); it<in.end();it++)
		{
		if (in[i] >= 'a' && in[i] <='z') count ++;
		//if (*it >= 'a' && *it <='z') count ++;
		}
	return count;
}

//------------------------------------------------------------
int main (int argc, char * const argv[]) {
	int count=0;
	
	string input="AQUI hay TRECE minusculas";
	count = count_minuscule(input);
	//cout << sizeof(input) << endl;
	cout << input << endl;
	cout << "Numero de minusculas: " << count << endl;
	/*
	char *input_="AQUI hay TRECE minusculas";
	//cout << strlen(input_);
	count = count_minuscule(input_);
	cout << input_ << endl;
	cout << "Numero de minusculas: " << count << endl;
	*/
	return 0;
}
//------------------------------------------------------------
