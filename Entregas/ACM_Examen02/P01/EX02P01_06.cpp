/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I EX02P01
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
#include <string>

using namespace std;

string g1="GATACCA";
string g2="GTACCA";


//Valor de la constante Beta.
const int Beta = 10;

//Valores constantes de Alpha.
int Alpha(char s1, char s2){
	if (s1=='A' && s2=='C') return 1;
	if (s1=='C' && s2=='A') return 1;
	if (s1=='A' && s2=='G') return 2;
	if (s1=='G' && s2=='A') return 2;
	if (s1=='A' && s2=='T') return 3;
	if (s1=='T' && s2=='A') return 3;
	if (s1=='C' && s2=='G') return 4;
	if (s1=='G' && s2=='C') return 4;
	if (s1=='C' && s2=='T') return 5;
	if (s1=='T' && s2=='C') return 5;
	if (s1=='G' && s2=='T') return 6;
	if (s1=='T' && s2=='G') return 6;
	return 0;
}

int Min(int a,int b){
	if (b<a) return b;
	else return a;
}



//Supondre que siempre  l<k
int D(int k, int l){
	//Para esta parte del ejercio agregué las siguientes dos lineas:
	static int knownD[10][10];
	if (knownD[k][l]!=0) return knownD[k][l];
	if (l==0 ) return k*Beta;
	if (k==0 ) return l*Beta;
	int A=D( k-1, l-1) +Alpha(g1[k],g2[l]);
	int B=D( k, l-1)+Beta;
	int C=D( k-1, l)+Beta;
	return Min( A, Min(B,C) );
}


//------------------------------------------------------------
int main (int argc, char * const argv[]) {
	int k=5;
	int l=4;
	cout << "G1: "<< g1 << endl;
	cout << "k : "<< k << endl;
	cout << "G2: "<< g1 << endl;
	cout << "l : "<< l << endl;
	cout << "Costo de emparejamiento: "<< D( k, l ) << endl;
	return 0;
}
//------------------------------------------------------------
