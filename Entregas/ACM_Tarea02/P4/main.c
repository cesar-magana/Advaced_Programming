/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA HW01P04
Andrés César Magaña Martínez
cesar@cimat.mx

--------------------------------------------------------------*/

#include <stdio.h>

void swap( int * a, int * b){
	*a += *b;
	*b = *a-*b;
	*a -= *b;
}

int main (int argc, const char * argv[]) {
	int i;
	int cam;
	int a[] = {5, 8, 1, 4, 3, 9, 2, 7, 3, 8, 1, 4, 5, 3, 8};
	int dim = 15;

	printf( "Arreglo original: " );
	for ( i=0; i<dim; i++ )
		printf( "%d ", a[i] );

	do 
		{
		cam = 0;
		for ( i=0; i<dim-1 ;i++)
			{
			if ( a[i]>a[i+1] )
				{
				swap(&a[i],&a[i+1]);
				cam=1;
				}
			}
		}
	while ( cam==1 );
		
	printf( "\n\nArreglo reordenado:" );
	for ( i=0; i<dim; i++ )
		printf( "%d ", a[i] );
	
	printf( "\n\nPresione cualquier tecla para salir... " );
	getchar();
	return 0;
}
