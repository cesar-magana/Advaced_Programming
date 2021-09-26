/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA HW01P04
Andrés César Magaña Martínez
cesar@cimat.mx

--------------------------------------------------------------*/

float SumFloats (int n){
	int i;
	float sumf = 0.0;
	for ( i=1; i<n+1; i++ )
		sumf+=(1/(float)n);
	return sumf;
}

double SumDoubles (int n){
	int i;
	float sumd = 0.0;
	for ( i=1; i<n+1; i++ )
		sumd+=(1/(float)n);
	return sumd;
}


#include <stdio.h>

int main (int argc, const char * argv[]) {
	int i, n=10;
	float sumf, errorf;
	double sumd, errord;
	printf("n\tSuma con floats                       Diferencia con el valor real\n");			
	for ( i=1; i<n+1; i++ )
		{
		sumf  = SumFloats(i);
		errorf = 1.0-sumf;
		printf("%d  %.25f        \t%.25f\n", i, sumf, errorf);
		}
	printf("\n\n");

	printf("n  Suma con doubles                    Diferencia con el valor real\n");			
	for ( i=1; i<n+1; i++ )
		{
		sumd  = SumDoubles(i);
		errord = 1.0-sumd;
		printf( "%d  %.25lf        \t%.25lf\n", i, sumd, errord );
		}

	
	printf("Presione cualquier tecla para salir...\n");	
	getchar();
	return 0;
}
