/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA HW01P05
Andrés César Magaña Martínez
cesar@cimat.mx

--------------------------------------------------------------*/

#include <stdio.h>

double dabs( double valor ){
	if ( valor < 0 ) return -valor;
	return valor;
}

long double factorial(int n){
	int i;
	long double salida=1;
	for ( i=2; i<n+1; i++ )
		salida*=i;
	return salida;
}

double TaylorE( double epsilon, int *iterations ){
	int n=0;
	long double result, termino;
	result=0.0;

	while ( n < *iterations )
		{
		termino = 1 /(double)factorial(n);
		result += termino;
		if ( dabs(termino) <epsilon )
			break;
		n++;
		}
	*iterations = n;
	return result;
}

int main (int argc, const char * argv[]) {
	double epsilon, aproximacion;
	int iteraciones = 100;
	
	printf( "Ingrese un epsilon:\n" );
	scanf("%lf",&epsilon);

	aproximacion = TaylorE( epsilon, &iteraciones );
	printf( "Aproximacion final de e: %1.50lf\nEn %d iteraciones.", aproximacion, iteraciones );
	printf( "\n\nPresione cualquier tecla para salir... " );
	getchar();
	return 0;
}
