/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA HW01P02
Andrés César Magaña Martínez
cesar@cimat.mx

--------------------------------------------------------------*/

#include <stdio.h>

unsigned int combine( short short1, short short2){
	return (short1 << 16) | short2;
}

short getshort1( unsigned int uint ){
	return (short)(uint>>16);	
}

short getshort2( unsigned int uint ){
	return (short)(uint);	
}

int main (int argc, const char * argv[]) {
	short short1;
	short short2;
	unsigned int uint;

	printf( "Ingrese un short:\n" );
	scanf( "%hi",&short1 );

	printf( "Ingrese otro short:\n" );
	scanf( "%hi",&short2 );

	//Combina ambos números.
	uint = combine( short1, short2 );
	printf( "\nDatos ingresados:\n" );
	printf("short1: %hi \nshort2: %hi\nAqui se combinan los dos shorts en un unsigned int\nunsigned int combinado:%u\n\n",short1, short2, uint);

	//Recupera ambos numeros.
	printf( "\nAqui se recuperan ambos numeros a partir del unsigned int:\n" );
	short1 = getshort1(uint);
	short2 = getshort2(uint);
	printf("unsigned int combinado:%u\nshort1: %hi\nshort2: %hi\n\n", uint, short1, short2);
	printf("Presione cualquier tecla para salir... ");
	getchar();
	return 0;
}
