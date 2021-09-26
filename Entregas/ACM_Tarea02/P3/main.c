/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA HW01P03
Andrés César Magaña Martínez
cesar@cimat.mx

--------------------------------------------------------------*/

#include <stdio.h>

//Recibe el unsigned long y lo recorre shift lugares a la derecha circularmente.
unsigned long rotate_r( unsigned long value, int shift ){
	return (value >> shift) | (value << (32 - shift));
}


int main (int argc, const char * argv[]) {
	int cuanto;
	unsigned long entrada;
	unsigned long salida;

	printf( "Ingrese un unsigned long:\n" );
	scanf( "%u",&entrada );
	printf( "Cuanto se quiere rotar? (entero):\n" );
	scanf( "%d",&cuanto );

	//"Rota" el número a la derecha.
	salida = rotate_r( entrada, cuanto );
	printf( "\nEntrada:%u\nSalida:%u\n\n", entrada, salida );

	printf( "Presione cualquier tecla para salir... " );
	getchar();
	return 0;
}
