/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW04P02
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/

#include <stdio.h>
char* cifras[] = {"CERO", "UNO", "DOS", "TRES", "CUATRO", "CINCO", "SEIS", "SIETE", "OCHO", "NUEVE"};

//------------------------------------------------------------
//Función recursiva.
void LeeNumero( unsigned int n ){
	if (n<10) printf( "%s  ", cifras[n] );
	else 
		{
		printf( "%s  ", cifras[n%10] );
		return LeeNumero ( n/10 );
		}
	}



//------------------------------------------------------------
//Función iterativa.
/*	 
	int potencia = 10;
	int cifra;
	
	while ( n-potencia > 0 )
		{
		cifra = (n/potencia)%10;
		potencia *= 10;
		printf( "%s  ", numeros[cifra] );
		}*/


//------------------------------------------------------------
int main (int argc, const char * argv[]) {
	unsigned int n;
	printf( "Ingrese un unsigned int:\n" );
	scanf( "%u",&n );
	LeeNumero(n);
	getchar();
	return 0;
}
//------------------------------------------------------------